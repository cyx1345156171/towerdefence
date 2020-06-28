#include "bullet.h"
bullet::bullet(int x1, int x2,int x3)
{
    x=x1;
    y=x2;
    xuhao=x3;
}
int bullet::getx()
{
    return x;
}
int bullet::gety()
{
    return y;
}
void bullet::setbullet(int x1, int y1)
{
    x=x1;
    y=y1;
}
bool bullet::getdirection()
{
    return direction;
}
void bullet::setangle(bool m)
{
    direction=m;
}
void bullet::sethosa(int h)
{
    hosa=h;
}
void bullet::settan(int g)
{
    tan=g;
}
int bullet::returnhosa()
{
    return hosa;
}
int bullet::returntan()
{
    return tan;
}
int bullet::getxuhao()
{
    return xuhao;
}
void bullet::settu(QPixmap s)
{
    zidantu=s;
}
QPixmap bullet::gettu()
{
    return zidantu;
}
