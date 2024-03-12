#include "mypopup.h"
#include "ui_mypopup.h"
#include <QTimer>
#include "mystruct.h"

myPopup::myPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myPopup)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags()| Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);//设置了窗口的标志位，使其成为一个无边框窗口
}

myPopup::~myPopup()
{
    delete ui;
}

void myPopup::Text_show(QString str)
{
    ui->label->setText(str);
    this->show();
    QTimer::singleShot(3000,[=](){this->hide();});
}
