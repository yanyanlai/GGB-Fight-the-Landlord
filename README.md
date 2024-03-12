<center><font size=6>卡通人物斗地主游戏软件使用说明</font></center>

[TOC]

# 一、系统简介

卡通人物斗地主游戏软件是一款以卡通人物为主题的经典斗地主游戏软件，具有创建房间、加入房间、叫地主、发牌洗牌、得分结算等功能。通过将传统的经典游戏与现代化的卡通人物相结合，具有创新性，拓宽了使用群体。

# 二、设计目标

1. 游戏体验：设计一个具有良好的用户界面和交互体验的斗地主游戏，使玩家能够流畅地进行游戏操作，并享受游戏过程中的乐趣。

2. 玩家互动：多人游戏模式，玩家可以与其他真实玩家进行对战，增加游戏的互动性和挑战性。

3. 游戏规则：准确地实现斗地主的游戏规则，包括发牌、叫地主、出牌等各个环节的逻辑和限制条件，确保游戏的公平性和合理性。

# 三、操作手册

## 3.1初始界面

进入游戏即出现此界面，界面交互性良好，以热播动画猪猪侠为主题，具有创新性，符合大众审美，配上猪猪侠和斗地主的背景音乐，更具玩乐效果，实现了游戏的本质。

该界面可进行改名、调节声音、创建房间、加入房间、退出操作，如图：
![image-20231115202334320](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/d3b52058-6b76-40df-928d-acaecff45a61)


改名：更改玩家姓名。

调节声音：点击可出现拉条用来调节背景音乐大小。

创建房间：在局域网内，发送创建房间信号。

加入房间：弹出弹窗，可选择加入房间。

退出：游戏结束退出即可。

## 3.2改名

点击“改名”按钮，如下：
![image-20231115202424222](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/a116acbc-0fc1-409d-9e49-ecbaf1ea7dd0)

弹出“输入姓名”弹窗，玩家输入姓名即可：
![image-20231115202439450](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/bdd90610-f09d-4800-b914-1fe543bb26bf)

![image-20231115202507606](C:\Users\yanla\AppData\Roaming\Typora\typora-user-images\image-20231115202507606.png)

若玩家输入姓名为空，弹出警告窗口“输入名字不能为空！”，如下图所示：
![image-20231115202742312](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/338dbf56-96a9-4b6c-9fe4-5aa0132df8de)



当玩家输入非空姓名后，点击“ok”，回到初始界面，此时左上角的姓名已经被修改，如下图所示：
![image-20231115202536072](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/aaa814cb-b0ba-4375-a182-d4917655ff51)



## 3.3调节声音

点击“调节声音”按钮，弹出声音调节拉条，左右拖动此拉条，即可调节背景音乐大小：
![image-20231115202604212](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/e34bc86b-b603-4dfb-8fb0-6d76153bc3aa)



## 3.4创建房间

点击创建房间按钮，如下图所示：
![image-20231115202634035](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/a20e12d0-2b13-4ea4-97ca-1f788e5a76ad)



弹出“等待连接。。。”的提示，此时系统正在发送创建房间信号，如下图所示：
![image-20231115205007439](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/1069b03d-ef24-4ce2-9f35-97757b16cb6c)



## 3.5加入房间

点击“加入房间”按钮，如下图所示：
![image-20231115205135664](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/b7bc39ea-c1d8-4268-83d7-a2a5ae0e4fbf)



弹出dialog弹窗，弹窗中间分为三列：序号、姓名、IP。如下图所示：
![image-20231115202710777](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/97fe7252-7e49-48c0-bbfb-3eb9937e1ed5)


若此时有其他用户发送“创建房间”信号，列表中会显示序号、姓名、IP信息。如下图所示：
![image-20231115202759832](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/7600ac75-df00-431f-9bfa-8ad2b92b5324)



若未选择“房主”，直接点击“加入”按钮，系统则弹出警告窗口“未选择行数”。
![image-20231115202821773](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/f35604a0-b260-49e1-88db-7c06412c2afe)


选择“房主”，点击“加入”，即可加入房间，等待游戏开始。

## 3.6开始战斗

点击“开始战斗”按钮，如下图所示：
![image-20231115202911993](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/d62b29be-67b2-4ca3-bb4a-3a6604811f6b)



随即进入游戏主界面。

## 3.7游戏主界面

游戏主界面，包含开始游戏按钮、退出按钮、积分、倍数、玩家一姓名、玩家二姓名。

点击“退出”即退出系统，当三个用户都点击“开始游戏”，系统自动发牌，如下图所示：
![image-20231115203029548](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/490a4130-4cfc-41f8-be2b-c26b65492d4b)



## 3.8叫地主界面

房主界面显示“1分”、“2分”、“3分”和“不要”，房主可以优先选择叫几分或是不叫。
![image-20231115203110348](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/cf6c30f8-a0c5-4913-bca2-617343dedfbb)



## 3.9出牌界面

叫到地主后，会有以“猪猪侠”为原型的地主和农民形象显示在用户名旁边，同时地主增加三张地主牌，并且优先选择出牌。之后当轮到用户出牌时，用户界面会显示“出牌”与“不出”两个选项
![image-20231115203209238](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/a6f52fcf-ef6a-4f56-87b5-ba5d4eeb2da3)



点击牌button时，牌像素向上移动40像素。
![image-20231115203611909](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/2e7e00d8-c59c-4f99-b56e-db04ba5b2708)


牌被出出去时，其他牌向左移动30像素。更具观感和美感。
![image-20231115203402398](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/f1501063-3a10-437f-9136-42921fb6a64b)



## 3.10结算界面

对局结束后，弹出结算窗口，相比于单纯的判定输赢，我们根据地主和农民的倍数以及所叫分数，综合计算出地主和农民的得分。使结果更具直观性。
![image-20231115203432578](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/e5acb2ab-3683-4aa0-8d6e-0196cc9796c1)



# 四、软件设计

## 4.1用例模型
![image-20231115210754987](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/607c88c2-a772-4d6e-a126-f4e8118ea7ad)



## 4.2流程设计
![image-20231115210811321](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/15d7521c-e083-48fb-8558-33abd9ae3f5d)


## 4.3 ER图
![image-20231115210904612](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/f6f9f945-15cf-41d3-9c9a-482281dfc780)



## 4.4部分代码框架

### 4.4.1整体框架
![image-20231115211024034](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/467c6246-3a81-40b4-b560-b01931c634da)


### 4.4.2开始游戏
![image-20231115211052108](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/24fa3db4-1f4b-4bde-965e-657b11940b22)



### 4.4.3实现发牌
![image-20231115211109712](https://github.com/yanyanlai/GGB-Fight-the-Landlord/assets/110188868/39421630-2b3e-4d2a-94a7-2a31db45341b)



## 4.5部分关键代码展示

### 4.5.1 mycontrol构造函数，系统初始化

```c++
mycontrol::mycontrol(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<qintptr>("qintptr");//将 qintptr 类型注册到元对象系统中，以便在信号和槽之间传递 qintptr 类型的参数。
    qRegisterMetaType<Use_stu>("Use_stu");

    qRegisterMetaType<QList<paidui>>("QList<paidui>");

    m_wanning = new my_wanning;
    my_result  = new myresult;
    m_player = new player;
    my_popup = new myPopup;

    m_player->bofang_file(1);
    CPU_ID = common::get_CPUID();
    User_name = "小猪猪"+CPU_ID;

//    initfile();
    my_select = new selectkind;
    my_Widget = new Widget;
     //my_select
    connect(my_select,&selectkind::sig_selectkind,this,&mycontrol::starting_items);
    connect(my_select,&selectkind::sig_join_Create,this,&mycontrol::slot_join_Create);
    connect(my_select,&selectkind::sig_myresult_numb,this,&mycontrol::slot_myresult_numb);
    //my_Widget
    connect(my_Widget,&Widget::sig_start_game,this,&mycontrol::slot_start_game);
    connect(my_Widget,&Widget::sig_fenshu_push,this,&mycontrol::slot_fenshu_push);
    connect(my_Widget,&Widget::sig_One_dizhu,this,&mycontrol::slot_One_dizhu);
    connect(my_Widget,&Widget::sig_chupai_card,this,&mycontrol::slot_chupai_card);
    connect(my_Widget,&Widget::sig_win_game,this,&mycontrol::slot_win_game);
    connect(this,&mycontrol::sig_your_is_dizhu,my_Widget,&Widget::slot_your_is_dizhu);
}
```

### 4.5.2点击创建房间，发送信号

```c++
void selectkind::on_pushButton_8_clicked() //创建
{
    ui->label_6->setText("等待连接。。。。");
    emit sig_join_Create(true);
}
void mycontrol::slot_join_Create(bool bol)  // true创建false加入
{
    udp_start = new my_udp_soc;
    udp_start->initsys(bol);
    if(!bol)
        {
        udp_start->show();
        my_Widget->pus_6_show(true);
        xitongfuwuqiORkehuduan = false;
        connect(udp_start,&my_udp_soc::sig_Ipdizhi,this,&mycontrol::slot_Ipdizhi);
    }
    else
    {
        xitongfuwuqiORkehuduan = true;
        my_Widget->pus_6_show(false);
        Tcpserver = new mytcpserver;
        Tcpserver->listen(QHostAddress::Any,6666);
        //将其设置为监听指定的 IP 地址和端口号。QHostAddress::Any 表示监听任意可用的 IP 地址，而 6666 是指定的端口号。
        connect(Tcpserver,&mytcpserver::sig_finish,this,&mycontrol::slot_finish);
        connect(this,&mycontrol::sig_message_TCP,Tcpserver,&mytcpserver::slot_message_TCP);

        //处理接收的消息，仅仅是接收
        connect(Tcpserver,&mytcpserver::sig_message_jiben,this,&mycontrol::slot_message_jiben);
        connect(Tcpserver,&mytcpserver::sig_message_buchu_pai,this,&mycontrol::slot_message_buchu_pai);
        connect(Tcpserver,&mytcpserver::sig_message_choose_score,this,&mycontrol::slot_message_choose_score);
        connect(Tcpserver,&mytcpserver::sig_message_chu_pai,this,&mycontrol::slot_message_chu_pai);
        connect(Tcpserver,&mytcpserver::sig_message_gane_score,this,&mycontrol::slot_message_gane_score);
        connect(Tcpserver,&mytcpserver::sig_message_my_dizhu,this,&mycontrol::slot_message_my_dizhu);
        connect(Tcpserver,&mytcpserver::sig_home_yes,this,&mycontrol::slot_home_yes);
    }
}
```

### 4.5.3点击加入房间，出现弹窗，并选择房间加入

```c++
void selectkind::on_pushButton_9_clicked()//加入
{
    emit sig_join_Create(false);
}
#include "my_udp_soc.h"
#include "ui_my_udp_soc.h"

my_udp_soc::my_udp_soc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::my_udp_soc)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose, true);//表示窗口在关闭时自动删除对象
    zuboinit();
    QStringList lis;
    this->setModal(true);
    lis<<"序号"<<"姓名"<<"IP";
    ui->tableWidget->setColumnCount(lis.size());
    ui->tableWidget->setHorizontalHeaderLabels(lis);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setColumnWidth(0,90);
    ui->tableWidget->setColumnWidth(2,180);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    connect(ui->tableWidget,&QTableWidget::cellClicked,this,&my_udp_soc::slot_cellclick);
}

my_udp_soc::~my_udp_soc()
{
    shuchu<<"haha";
    delete ui;
}
void my_udp_soc::initsys(bool state)  //true是发送也就是服务器
{
    if(state)
    {
        m_time = new QTimer(this);
        m_time->setInterval(4000);
        m_time->start();
        connect(m_time,&QTimer::timeout,this,&my_udp_soc::slot_sendmessage);
        connect(m_udp,&QUdpSocket::readyRead,this,&my_udp_soc::slot_readready);
    }
    else
    {
        connect(m_udp,&QUdpSocket::readyRead,this,&my_udp_soc::slot_readready);
    }
}

void my_udp_soc::zuboinit()
{
     m_udp = new QUdpSocket(this);
     m_udp->bind(9999,QUdpSocket::ShareAddress);
     //将 UDP 套接字绑定到本地的 9999 端口，
     //并指定使用 QUdpSocket::ShareAddress 选项。
     //这个选项表示允许多个套接字绑定到相同的地址和端口，以实现多个套接字共享同一个端口。
}

void my_udp_soc::slot_sendmessage()
{
    QByteArray byt;
    //以下格式构建消息字符串
    QString str = "UDP_Name_IP|"+User_name+"|"+common::get_getIP();
    byt = str.toUtf8();//将字符串转换为UTF-8编码
    m_udp->writeDatagram(byt.data(),QHostAddress::Broadcast,9999);//将消息数据以数据报的形式写入UDP套接字中
}//将消息发送给广播地址，9999 是目标端口号
void my_udp_soc::slot_readready()
{
    QByteArray byt;
    byt.resize(m_udp->pendingDatagramSize());// 获取待接收数据报的大小，并使用 resize() 方法将 byt 调整为相应的大小。
    m_udp->readDatagram(byt.data(),byt.size());//将接收到的UDP数据报读取到 byt 中。byt.data() 返回指向 QByteArray 数据的指针，byt.size() 表示读取的数据大小。
    QString str = QString(byt);
    shuchu<<str;
    QStringList lis = str.split("|");
    if(lis.size()<3)//如果 lis 的大小小于3，说明消息格式不符合预期
    {
        return;
    }
    for(int a=0;a<dou_stulis.size();a++)//循环遍历 dou_stulis列表，检查是否已经存在与接收到的消息中的 lis.at(1) 相同的元素。如果存在，则函数直接返回
    {
        if(dou_stulis.at(a).one==lis.at(1))
        {
            return;
        }
    }
    double_QStringstu doub_string;
    /*double_QStringstu结构体如下：
     * struct double_QStringstu
{
    QString one;
    QString two;
    QString defen;
    double_QStringstu() {
        QString one="";
        QString two="";
        QString defen = "";
    }
};
*/
    doub_string.one = lis.at(1);//姓名
    doub_string.two = lis.at(2);//ip
    dou_stulis.append(doub_string);//添加
    ui->tableWidget->setRowCount(dou_stulis.size());
     for(int a=0;a<dou_stulis.size();a++)
    {
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::number(a)));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(dou_stulis.at(a).one));
        ui->tableWidget->setItem(0,2,new QTableWidgetItem(dou_stulis.at(a).two));
    }
}
//点击加入button
void my_udp_soc::on_pushButton_clicked()
{
    if(roow<0)
    {
        m_wanning->show_wanning("未选择行数");
    }
    else
    {
        emit sig_Ipdizhi(ui->tableWidget->item(roow,2)->text());//&mycontrol::slot_Ipdizhi
        hide();
    }
}
//取列号，元素
void my_udp_soc::slot_cellclick(int ro, int com)
{
    Q_UNUSED(com);
    roow = ro;
}
//点击关闭
void my_udp_soc::on_pushButton_2_clicked()
{
    close();
}
```

### 4.5.4洗牌发牌

```c++
choose mycontrol::xipai_CARD()
{
    QList<paidui> my_list;
    for(int a=3;a<17;a++)
    {
        if(a==15)
            continue;
        for(int i=0;i<4;i++)
        {
            int c=i%4;
            paidui pai;
            switch (c) {
            case 0:{
                pai.huase="fangkuai";
                break;
            }
            case 1:{
                pai.huase="meihua";
                break;
            }
            case 2:{
                pai.huase="hongtao";
                break;
            }
            case 3:{
                pai.huase="heitao";
                break;
            }
            }
            pai.number=a;
            my_list.append(pai);
        }
    }
    paidui pai1;
    pai1.huase="xiaowang";
    pai1.number = 19;
    my_list.append(pai1);
    pai1.huase="dawang";
    pai1.number = 20;
    my_list.append(pai1);

    choose pai_huozong;//存放总牌数
    pai_huozong=my_chose(my_list);
    common::my_sort(pai_huozong.lis1);
    common::my_sort(pai_huozong.lis2);
    common::my_sort(pai_huozong.lis3);

    return pai_huozong;
}

choose mycontrol::my_chose(QList<paidui> my_list)
{
    choose m_choose;
    qsrand((QTime(0,0,0).secsTo(QTime::currentTime())));
    while(my_list.size()>3)
    {
        int rand = qrand()%my_list.size();
        m_choose.lis1.append(my_list.takeAt(rand));
        rand = qrand()%my_list.size();
        m_choose.lis2.append(my_list.takeAt(rand));
        rand = qrand()%my_list.size();
        m_choose.lis3.append(my_list.takeAt(rand));
    }
    while(!my_list.isEmpty())
    {
        m_choose.sanzhang.append(my_list.takeAt(0));
    }
    return  m_choose;
}
```

### 4.5.5出牌功能的实现

```c++
void Widget::slot_paiduilis(QList<paidui> my_paili)
{
    xx = 60;
    pushlis.clear();
    sig_delet_pus_1();
    my_pailist.clear();
    my_pailist.append(my_paili);

    common::my_sort(my_pailist);
    for(int a=0;a<my_pailist.size();a++)
    {
        card_button *pus = new card_button(QString::number(my_pailist.at(a).number),my_pailist.at(a).huase);
        connect(this,&Widget::sig_delet_pus_1,[=](){
            pus->hide();
        });
        pus->setParent(ui->widget_12);
        pus->setGeometry(xx,yy,ww,hh);
        pus->setMaximumSize(ww,hh);
        pus->setMinimumSize(ww,hh);
        push p;
        p.pushptr = pus;
        pushlis.append(p);
        xx+=40;
        pus->show();
        connect(this,&Widget::pus_hide,[=](push pushe,int sisi){
            if(pushe.pushptr==pus)
            {
                push pp;
                pp.pushptr = pus;
                pus->disconnect();
                puslis.append(pp);
                pus->hide();
                for(int a=sisi+1;a<pushlis.size();a++)
                {
                    QRect rec = pushlis.at(a).pushptr->geometry();
                    rec.setX(rec.x()-40);
                    pushlis.at(a).pushptr->setGeometry(rec);
                }
            }
        });
        connect(pus,&card_button::clicked,[=](){
            int sta;
            for(int x=0;x<pushlis.size();x++)
            {
                if(pushlis.at(x).pushptr==pus)
                {
                    sta = x;
                    break;
                }
            }
             QRect rec = pushlis.at(sta).pushptr->geometry();
            if(pushlis.at(sta).bol)
            {
                rec.setY(rec.y()-30);
                pushlis[sta].bol = false;
                paidui kk;
                kk.huase = pus->currhuase();
                kk.number = pus->currnumb().toInt();
                paiduilis1.append(kk);
            }
            else
            {
                rec.setY(rec.y()+30);
                pushlis[sta].bol = true;
                paidui kk;
                kk.huase = pus->currhuase();
                kk.number = pus->currnumb().toInt();

                for(int m=0;m<paiduilis1.size();m++)
                {
                    if((kk.huase==paiduilis1.at(m).huase)&&(kk.number==paiduilis1.at(m).number))
                    {
                        paiduilis1.removeAt(m);
                    }
                }
            }
            pus->setGeometry(rec);
        });
    }
}
```

### 4.5.6分数计算

```c++
void mycontrol::slot_win_game(int co, int mo)
{
    int score = co*mo;
    double_QStringstu syu1;
    double_QStringstu syu2;
    double_QStringstu syu3;
    if(use_stulis.size()>=3)
    {
        if(my_this_dizhu=="3")
        {
            syu1.defen = QString::number(2*score);
            syu1.one = use_stulis.at(2).pic_lujing;
            syu1.two = use_stulis.at(2).name;

            syu3.defen = QString::number(-score);
            syu3.one = use_stulis.at(0).pic_lujing;
            syu3.two = use_stulis.at(0).name;

            syu2.defen = QString::number(-score);
            syu2.one = use_stulis.at(1).pic_lujing;
            syu2.two = use_stulis.at(1).name;
        }
        else
        {
            syu1.defen = QString::number(score);
            syu1.one = use_stulis.at(2).pic_lujing;
            syu1.two = use_stulis.at(2).name;

            if(use_stulis.at(0).dizhu)
            {
                syu2.defen = QString::number(-2*score);
            }
            else
            {
                syu2.defen = QString::number(score);
            }
            syu2.one = use_stulis.at(0).pic_lujing;
            syu2.two = use_stulis.at(0).name;

            if(use_stulis.at(1).dizhu)
            {
                syu3.defen = QString::number(-2*score);
            }
            else
            {
                syu3.defen = QString::number(score);
            }
            syu3.one = use_stulis.at(1).pic_lujing;
            syu3.two = use_stulis.at(1).name;
        }
         my_result->initsys(0);
        my_result->showjiesuan(syu1,syu2,syu3);
    }
    my_result->show();

    init_dizhu(2,"");
    if(xitongfuwuqiORkehuduan)
    {

        Win_Info_TCP *Info1 = new Win_Info_TCP();
        Info1->score = QString::number(score);
        Info1->winuser = my_this_dizhu;
        Info *Kinf1 = (Info *)Info1;
        emit sig_message_TCP(Kinf1,2);

        Win_Info_TCP *Info2 = new Win_Info_TCP();
        Info2->score = QString::number(score);
        Info2->winuser = my_this_dizhu;
        Info *Kinf2 = (Info *)Info2;
        emit sig_message_TCP(Kinf2,3);
    }
    else
    {
        Win_Info_TCP *Info2 = new Win_Info_TCP();
        Info2->score = QString::number(score);
        Info2->winuser = my_this_dizhu;
        Info *Kinf2 = (Info *)Info2;
        emit sig_message_tcpsoc(Kinf2);
    }
}
```

