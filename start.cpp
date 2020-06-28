#include "start.h"
#include "ui_start.h"
#include"diyiguan.h"
#include"QPainter"

start::start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{
    QMediaPlayer * player1=new QMediaPlayer(this);
    player1->setMedia(QUrl("qrc:/music/begin.mp3.mp3"));
    player1->setVolume(10);
    player1->play();
    ui->setupUi(this);
    setFixedSize(1000,600);
    connect(ui->pushButton,&QPushButton::clicked,this,[=]()
    {
        diyiguan *number1 = new diyiguan(1);
        player1->stop();
        number1->show();
    });
    connect(ui->pushButton2,&QPushButton::clicked,this,[=]()
    {
        diyiguan *number = new diyiguan(2);
        player1->stop();
        number->show();
    });
}
void start::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(1,1,this->width(),this->height(),QPixmap(":/tu/cover1.jpg"));

}
start::~start()
{
    delete ui;
}
