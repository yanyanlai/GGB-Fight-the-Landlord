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
