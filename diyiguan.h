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
#include"QLabel"


namespace Ui {
class diyiguan;
}

class diyiguan : public QWidget
{
    Q_OBJECT

public:
    diyiguan(int);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void settowerposition();
    void painttaken(QPainter &);
    void paintbackground(QPainter &);
    void paintta(QPainter &);
    void paintchoice(QPainter &);
    void paintshengji(QPainter &);
    void paintchaichu(QPainter &);
    void paintzidan(QPainter &);
    void paintskill(QPainter &);
    ~diyiguan();
    void setwaypoint();    //设置路径点
    void paintdiren(QPainter &);    //画敌人
    void painthouse(QPainter &);    //画房子
    int distance(int,int,int,int);  //计算俩点间的距离
    bool costmoney(int);
    void updatelife(int);
    void setlevel(int);
    void updatewave(int);


private:
    int levelnumber;
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
    int money=500;        //初始钱数为500
    int lifehealth=8;     //初始生命值为8
    QLabel *win = new QLabel(this);
    QLabel *lose=new QLabel(this);
    int wave=1;        //波数

private slots:
    void move();           //怪物移动
    void loaddiren();      //初始化敌人
};

#endif // DIYIGUAN_H
