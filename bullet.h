#ifndef BULLET_H
#define BULLET_H
#include"QPainter"

class bullet
{
public:
    bullet(int,int,int);
    int getx();
    int gety();
    QPixmap gettu();
    void setbullet(int,int);
    void settu(QPixmap);
    void setangle(bool);
    bool getdirection();
    int returntan();
    int returnhosa();
    void settan(int);
    void sethosa(int);
    int getxuhao();

private:
    QPixmap zidantu;
    int x;
    int y;
    bool direction=false;// 用于子弹x轴方向 false代表左方向
    int tan;         //角度
    int hosa;        //用于计算y值
    int xuhao;       //用来标记子弹的种类
};

#endif // BULLET_H
