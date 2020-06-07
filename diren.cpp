#include "diren.h"

diren::diren(int x, int y, int id, int number):x(x),y(y)
{
    int i=0;
    /*for(i=0;i<number;i++)
    {
        way.push_back(x1[i]);
    }*/
    if(id==0)
    {
        //0号代表铁头怪
        health=100;
        speed=5;
       // ditu="image";
        height=80;
        width=60;
    }
}
int diren::getx()
{
    return x;
}
int diren::gety()
{
    return y;
}
void diren::setx(int x1)
{
    x=x1;
}
void diren::sety(int y1)
{
    y=y1;
}
int diren::getspeed()
{
    return speed;
}
QPixmap diren::gettu()
{
    return ditu;
}
