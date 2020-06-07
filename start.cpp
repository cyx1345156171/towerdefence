#include "start.h"
#include "ui_start.h"
#include"diyiguan.h"
#include"QPainter"

start::start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,[=]()
    {
        diyiguan *number1 = new diyiguan;


        number1->show();
    });
    connect(ui->pushButton2,&QPushButton::clicked,[=]()
    {
        diyiguan *number2 = new diyiguan;


        number2->show();
    });
}
void start::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(1,1,this->width(),this->height(),QPixmap(":/tu/Bg.png"));

}
start::~start()
{
    delete ui;
}
