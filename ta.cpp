#include "ta.h"
ta::ta(int x1,int x2)
{
    x=x1;
    y=x2;
}
int ta::getheight()
{
    return height;
}
int ta::getwidth()
{
    return width;
}
int ta::getatt()
{
    return attact;
}
int ta::getmoney()
{
    return costmoney;
}
int ta::getx()
{
    return x;
}
int ta::gety()
{
    return y;
}
int ta::getran()
{
    return range;
}
int ta::getrangle()
{
    return rangle;
}
void ta::setatt(int x)
{
    attact=x;
}
void ta::setran(int x)
{
    range=x;
}
void ta::setrangle(int x)
{
    rangle=x;
}
void ta::settarget(diren * x)
{
    target=x;
}
diren * ta::gettarget()
{
    return target;
}
QPixmap ta::getta()
{
    return tapath;
}
void ta::setpicture(QPixmap x1)
{
    tapath=x1;
}
