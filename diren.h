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
private:
    int x,y;
    int height,width;
    int health;
    int speed;
    QPixmap ditu;
    int xuhao;    //序号
    int biaoji=0;   //用于计算所在的固定点
    bool get;     //判断是否到达了终点
};

#endif // DIREN_H
