#ifndef DIYIGUAN_H
#define DIYIGUAN_H
#include<QPainter>
#include <QWidget>
#include"taposition.h"
#include"ta.h"
#include <QDebug>
#include"choice.h"
#include"commontower.h"
#include"speedtower.h"
#include"powertower.h"
#include"slowtower.h"
#include <QMediaPlayer>
#include<QMouseEvent>
#include"diren.h"
#include"wayzu.h"
#include"QTimer"


namespace Ui {
class diyiguan;
}

class diyiguan : public QWidget
{
    Q_OBJECT

public:
    explicit diyiguan(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void settowerposition();
    void painttaken(QPainter &);
    void paintbackground(QPainter &);
    void paintta(QPainter &);
    void paintchoice(QPainter &);
    void paintshengji(QPainter &);
    void paintchaichu(QPainter &);
    ~diyiguan();
    void setwaypoint();    //设置路径点
    void paintdiren(QPainter &);    //画敌人
    void painthouse(QPainter &);    //画房子

private:
    Ui::diyiguan *ui;
    QVector<taposition *> takeng;
    QVector<ta*> tower;
    choice * select = new choice;
    bool hasagei=false;     //用于鼠标点击事件
    QVector<diren*> monster;
    QVector<giao*> way;
    int time=0;//用于控制放怪的数量
    fouranniu shengji;
    fouranniu chaichu;

private slots:
    void move();           //怪物移动
    void loaddiren();      //初始化敌人
};

#endif // DIYIGUAN_H
