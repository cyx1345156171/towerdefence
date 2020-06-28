#ifndef DIREN_H
#define DIREN_H
#include<QVector>
#include<QString>
#include<QPainter>
class diren
{
public:
    diren(int x,int y,int id);
    int getx();
    int gety();
    int getspeed();
    void setx(int);
    void sety(int);
    QPixmap gettu();
    int getbiao();
    void setbiao(int);
    bool getget();
    void setget(bool);
    int gethealth();
    void sethealth(int);
    void setstate(bool,bool);
    void setspeed(int);
    bool getpoision();
    bool getice();
    bool getgod();
    void setgod(bool);
    int getxuhao();
private:
    int x,y;
    int height,width;
    int health;
    int speed;
    QPixmap ditu;
    int xuhao;    //序号
    int biaoji=0;   //用于计算当前的目标
    bool get=false;     //判断是否到达了终点 或者 死亡
    bool poision=false;     //判断是否中毒
    bool ice=false;        //判断是否冰冻，减速
    bool god=false;        //判断是否是dio  无敌状态  免疫毒与冰冻
};

#endif // DIREN_H
