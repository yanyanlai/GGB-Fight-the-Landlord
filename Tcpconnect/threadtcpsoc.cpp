#include "threadtcpsoc.h"
#include <QThread>
#include <QTcpSocket>
#include "common.h"
/*
 * Threadtcpsoc 类是一个继承自 QObject 的线程类，用于在单独的线程中处理与客户端的TCP连接。
 * 它包含了与TCP连接相关的成员函数和信号槽，用于接收和发送消息，并将消息转发给服务器或客户端的其他线程。
 *
这两个类共同协作，实现了服务器和客户端之间的通信功能。
mytcpserver 类负责监听和管理TCP连接，接收来自客户端的消息，并将其转发给相应的线程进行处理。
而 Threadtcpsoc 类负责处理单个客户端连接的消息收发和处理。
*/
Threadtcpsoc::Threadtcpsoc(int stor,QObject *parent) : QObject(parent),socketDescriptor(stor)
{
    thisthread = new QThread;
    moveToThread(thisthread);
    thisthread->start();
}

Threadtcpsoc::~Threadtcpsoc()
{
    tcpsocket->deleteLater();
    if(thisthread)
    {
        if(thisthread->isRunning())
            thisthread->terminate();
    }
    delete thisthread;
    thisthread = nullptr;
}

qintptr Threadtcpsoc::gainsocketDescriptor()
{
    return socketDescriptor;
}
//初始化与服务器的连接，并建立相应的信号槽连接。
void Threadtcpsoc::initconnect(QString str)
{
    tcpsocket = new QTcpSocket;
    tcpsocket->connectToHost(str,6666);
    //创建了一个 TCP 服务器对象，并使其开始监听指定的 IP 地址和端口号，以便接收客户端的连接请求。
    connect(tcpsocket,&QTcpSocket::readyRead,this,&Threadtcpsoc::slot_readreay);
    connect(tcpsocket,&QTcpSocket::disconnected,[=](){
        emit sig_disconnected(this);
    });
    connect(tcpsocket,&QTcpSocket::connected,[=](){emit sig_connected();});
}
//处理需要发送给服务器的消息，并通过TCP连接将消息发送出去。
void Threadtcpsoc::slot_tcp_message(Info *inf)
{
    QByteArray mm = inf->str_to_Bty();
    delete inf;
    inf = nullptr;

    mm.insert(0,common::mytoByteArray(mm.length()));
    QString str(mm);
    shuchu<<"这里是发送的最后一步::客户端"<<str;
    tcpsocket->write(mm);
}
//始化与客户端的连接，并建立相应的信号槽连接。
void Threadtcpsoc::slot_initSocket(Threadtcpsoc *e, qintptr ptr)
{
    if(this!=e)
    {
        return;
    }
    tcpsocket = new QTcpSocket;
    if(!tcpsocket->setSocketDescriptor(socketDescriptor))
    {
        return;//此处返回打开soc错误
    }
    connect(tcpsocket,&QTcpSocket::readyRead,this,&Threadtcpsoc::slot_readreay);
    connect(tcpsocket,&QTcpSocket::disconnected,[=](){
        emit sig_disconnected(this);
    });
    emit sig_appendthreadsoc(this);
}
//处理来自客户端的消息，并根据消息类型转发给相应的槽函数进行处理。
void Threadtcpsoc::messageData(QByteArray byt)
{
    QByteArray byt1;
    byt1 = byt;
    byt1 = byt1.mid(4);
    QString str(byt1);
    shuchu<<str;
    QStringList lis = str.split("|");
    if(lis.size()==0)
    {
        return;
    }
    QString hand = lis.at(0);
    shuchu<<hand;
    if(hand=="Init_Info_TCP")
    {
//Init_Info_TCP|name|本机IP|发送轮换编号|头像名|头像的数据流
        QString picname = lis.at(4);
        QString pic = lis.at(5);
        Use_stu stt;
        stt.name = lis.at(1); //用户名
        stt.pic_lujing = picname;//文件名
        stt.IP_dizhi = lis.at(2);//IP地址
        stt.lunhuannumb = lis.at(3).toInt(); //轮换标号
        common::dataToPic(pic,picname);
        emit sig_message_jiben(this,stt,byt);
    }
    //Home_Info_TCP|房间信息
    if(hand=="Home_Info_TCP")
    {
        QString homestate = lis.at(1);
        emit sig_message_home(this,homestate);
    }
    //Home_Info_TCP_Yes|name
    if(hand=="Home_Info_TCP_Yes")
    {
        QString name = lis.at(1);
        emit sig_message_home_Yes(this,name);
    }
    //Start_Info_TCP_start
    if(hand=="Start_Info_TCP_start")
    {
        emit sig_message_game_start(this);
    }
    //Card_fa_Info_TCP|花色#数字|花色#数字|…|发牌数
    if(hand=="Card_fa_Info_TCP")
    {
        QList<paidui> pailis;
        for(int a=1;a<lis.size()-1;a++)
        {
            paidui pa;
            pa.huase = QString(lis.at(a)).split("#").at(0);
            pa.number = QString(lis.at(a)).split("#").at(1).toInt();
            pailis.append(pa);
        }
        QString fapai_numb = lis.at(lis.size()-1);
        emit sig_message_fa_pai(this,pailis,fapai_numb);
    }

    //Card_chu_Info_TCP|name|花色#数字;花色#数字|…|出牌数|轮换编号
    if(hand=="Card_chu_Info_TCP")
    {
        QString name = lis.at(1);
        QString paicard = lis.at(2);
        QStringList pailist1 = paicard.split(";");
        QList<paidui> pailis;
        for(int a=0;a<pailist1.size();a++)
        {
            paidui pa;
            pa.huase = QString(pailist1.at(a)).split("#").at(0);
            pa.number = QString(pailist1.at(a)).split("#").at(1).toInt();
            pailis.append(pa);
        }
        QString card_numb = lis.at(3);
        QString lunhuan_numb = lis.at(4);

        emit sig_message_chu_pai(this,pailis,name,card_numb,lunhuan_numb,byt);
    }
    //Card_NO_Info_TCP|name|轮换编号
    if(hand=="Card_NO_Info_TCP")
    {
        QString name = lis.at(1);
        QString lunhuan_numb = lis.at(2);
        emit sig_message_buchu_pai(this,name,lunhuan_numb,byt);
    }
    //Win_Info_TCP|地主or农民|分数
    if(hand=="Win_Info_TCP")
    {
        QString win_user = lis.at(1);
        QString win_sorc = lis.at(2);
        emit sig_message_gane_score(this,win_user,win_sorc,byt);
    }
//Choose_Info_TCP|name|分数|轮换编号   选地主的分数
    if(hand=="Choose_Info_TCP")
    {
        QString name = lis.at(1);
        QString score = lis.at(2);
        QString lunhuan_numb = lis.at(3);
        emit sig_message_choose_score(this,name,score,lunhuan_numb,byt);
    }
    //Your_One_Info_TCP  第一个选地主的
    if(hand=="Your_One_Info_TCP")
    {
        emit sig_message_yourone_choose(this);
    }
    //MY_Info_Buf_TCP|轮换编号
    if(hand=="MY_Info_Buf_TCP")
    {
        QString lunhuan_numb = lis.at(1);
        emit sig_message_my_dizhu(this,lunhuan_numb,byt);
    }
}
//该函数用于接收完整的数据报文，并调用 messageData() 函数对接收到的数据进行处理。
void Threadtcpsoc::slot_readreay()
{
    if(tcpsocket->bytesAvailable()>0)
    {
        amdstr+=tcpsocket->readAll();
    }
    if(amdstr.length()<lengthint)
    {
        return;
    }
    int rpt_len = common::mytoInt(amdstr.mid(0,lengthint));
    if(amdstr.length()<rpt_len)
    {
        return;
    }

    messageData(amdstr);
    amdstr.clear();
}

void Threadtcpsoc::slot_message_soc(Threadtcpsoc *so, QByteArray bty)
{
    if(so!=this)
    {
        return;
    }
    QString str(bty);
    shuchu<<"发送::服务器--->"<<str;
    tcpsocket->write(bty);
}
