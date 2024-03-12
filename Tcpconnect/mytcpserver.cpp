/*
 * mytcpserver 类是一个继承自 QTcpServer 的服务器类，用于处理TCP连接和消息传递。
 * 它包含了与TCP连接相关的成员函数和信号槽，用于管理连接的线程和消息的转发。
 * */
#include "mytcpserver.h"
#include <QDebug>
#include "Tcpconnect/threadtcpsoc.h"

mytcpserver::mytcpserver(QWidget *parent) : QTcpServer(parent)
{

}
//处理来自客户端的消息，并将其转发给相应的线程进行处理。
void mytcpserver::slot_message_TCP(Info *inf,int state) //a是第几个发送
{//fasong_home()中调用
    QByteArray bty =  inf->str_to_Bty();

    QString str11(bty);
    shuchu<<str11;
    delete inf;
    inf=nullptr;
    bty.insert(0,common::mytoByteArray(bty.length()));
    switch (state) {
    case 2:{
        if(Tredtcpsoclis.size()>0)
        {
            emit sig_message_soc(Tredtcpsoclis.at(0),bty);
        }
        else
        {
            m_wanning->show_wanning("发送失败，未创建服务器或有人员断开了连接");
        }
        break;
    }
    case 3:{
        if(Tredtcpsoclis.size()>1)
        {
            emit sig_message_soc(Tredtcpsoclis.at(1),bty);
        }
        else
        {
            m_wanning->show_wanning("发送失败，未创建服务器或有人员断开了连接");
        }
        break;
    }
    default:
        break;
    }
}
//在内部使用,在内部使用的函数，用于将消息转发给线程进行处理。
void mytcpserver::message_TCP(QByteArray bty, int state)
{
    switch (state)
    {
    case 2:{
        if(Tredtcpsoclis.size()>0)
        {
            emit sig_message_soc(Tredtcpsoclis.at(0),bty);
        }
        else
        {
            m_wanning->show_wanning("发送失败，未创建服务器或有人员断开了连接");
        }
        break;
    }
    case 3:{
        if(Tredtcpsoclis.size()>1)
        {
            emit sig_message_soc(Tredtcpsoclis.at(1),bty);
        }
        else
        {
            m_wanning->show_wanning("发送失败，未创建服务器或有人员断开了连接");
        }
        break;
    }
    default:
        break;
    }
}
//处理客户端断开连接的事件，从线程列表中移除对应的线程对象。
void mytcpserver::slot_disconnected(Threadtcpsoc *e)
{
    Tredtcpsoclis.removeAt(Tredtcpsoclis.indexOf(e));// 获取与参数 e 对应的 Threadtcpsoc 对象在 Tredtcpsoclis 列表中的索引位置, 移除该对象
    e->disconnect();//端开
    e->deleteLater();//删除e对象
}
//用于将新的 Threadtcpsoc 对象添加到服务器的线程列表中。
void mytcpserver::slot_Appendthreadsoc(Threadtcpsoc *e)
{
    if(Tredtcpsoclis.size()<2)  //超过两个不处理
    {
        Tredtcpsoclis.append(e);
    }
    if(Tredtcpsoclis.size()==2)
    {
        emit sig_finish();
    }
//限制最多处理两个连接，并在达到数量时触发相应的信号。
}

void mytcpserver::slot_message_chu_pai(Threadtcpsoc *soc, QList<paidui> pailis, QString str1, QString str2, QString str3, QByteArray bty)
{
    int a = Tredtcpsoclis.indexOf(soc);
    if(a==0)
    {
        message_TCP(bty,3);
    }
    else if(a==1)
    {
        message_TCP(bty,2);
    }
    else
    {
        m_wanning->show_wanning("消息转发错误，应该有人掉线，排查！");
    }
    emit sig_message_chu_pai(soc,pailis,str1,str2,str3);
}

void mytcpserver::slot_message_buchu_pai(Threadtcpsoc *soc, QString str1, QString str2, QByteArray bty)
{
    int a = Tredtcpsoclis.indexOf(soc);
    if(a==0)
    {
        message_TCP(bty,3);
    }
    else if(a==1)
    {
        message_TCP(bty,2);
    }
    else
    {
        m_wanning->show_wanning("消息转发错误，应该有人掉线，排查！");
    }
    emit sig_message_buchu_pai(soc,str1,str2);
}

void mytcpserver::slot_message_gane_score(Threadtcpsoc *soc, QString str1, QString str2, QByteArray bty)
{
    int a = Tredtcpsoclis.indexOf(soc);
    if(a==0)
    {
        message_TCP(bty,3);
    }
    else if(a==1)
    {
        message_TCP(bty,2);
    }
    else
    {
        m_wanning->show_wanning("消息转发错误，应该有人掉线，排查！");
    }
    emit sig_message_gane_score(soc,str1,str2);
}

void mytcpserver::slot_message_choose_score(Threadtcpsoc *soc, QString str1, QString str2, QString str3, QByteArray bty)
{
    int a = Tredtcpsoclis.indexOf(soc);
    if(a==0)
    {
        message_TCP(bty,3);
    }
    else if(a==1)
    {
        message_TCP(bty,2);
    }
    else
    {
        m_wanning->show_wanning("消息转发错误，应该有人掉线，排查！");
    }

    emit sig_message_choose_score(soc,str1,str2,str3);
}

void mytcpserver::slot_message_my_dizhu(Threadtcpsoc *soc, QString str1, QByteArray bty)
{
    state_size = 0;
    int a = Tredtcpsoclis.indexOf(soc);
    if(a==0)
    {
        message_TCP(bty,3);
    }
    else if(a==1)
    {
        message_TCP(bty,2);
    }
    else
    {
        m_wanning->show_wanning("消息转发错误，应该有人掉线，排查！");
    }
    emit sig_message_my_dizhu(soc,str1);
}

void mytcpserver::slot_message_jiben(Threadtcpsoc *soc, Use_stu us, QByteArray bty)
{
    int a = Tredtcpsoclis.indexOf(soc);
    shuchu<<a;
    if(a==0)
    {
        message_TCP(bty,3);
    }
    else if(a==1)
    {
        message_TCP(bty,2);
    }
    else
    {
        m_wanning->show_wanning("消息转发错误，应该有人掉线，排查！");
    }
    emit sig_message_jiben(soc,us);
}

void mytcpserver::slot_message_home_Yes(Threadtcpsoc * soc, QString str)
{
    state_size++;
    if(state_size>=2)
    {
        emit sig_home_yes();
    }
}
//重写QTcpServer的该函数，当有新的连接请求时，创建一个新的Threadtcpsoc对象，并将其移动到单独的线程中处理。
void mytcpserver::incomingConnection(qintptr handle)
{
    Threadtcpsoc *tcpsoc = new Threadtcpsoc(handle);
    connect(this,&mytcpserver::sig_startthread,tcpsoc,&Threadtcpsoc::slot_initSocket);
    connect(tcpsoc,&Threadtcpsoc::sig_appendthreadsoc,this,&mytcpserver::slot_Appendthreadsoc);
    connect(tcpsoc,&Threadtcpsoc::sig_disconnected,this,&mytcpserver::slot_disconnected);
    connect(this,&mytcpserver::sig_message_soc,tcpsoc,&Threadtcpsoc::slot_message_soc);

    //接收的槽
    connect(tcpsoc,&Threadtcpsoc::sig_message_chu_pai,this,&mytcpserver::slot_message_chu_pai);
    connect(tcpsoc,&Threadtcpsoc::sig_message_buchu_pai,this,&mytcpserver::slot_message_buchu_pai);
    connect(tcpsoc,&Threadtcpsoc::sig_message_gane_score,this,&mytcpserver::slot_message_gane_score);
    connect(tcpsoc,&Threadtcpsoc::sig_message_choose_score,this,&mytcpserver::slot_message_choose_score);
    connect(tcpsoc,&Threadtcpsoc::sig_message_my_dizhu,this,&mytcpserver::slot_message_my_dizhu);
    connect(tcpsoc,&Threadtcpsoc::sig_message_jiben,this,&mytcpserver::slot_message_jiben);
    connect(tcpsoc,&Threadtcpsoc::sig_message_home_Yes,this,&mytcpserver::slot_message_home_Yes);

    shuchu<<handle;
    emit sig_startthread(tcpsoc,handle);
}
