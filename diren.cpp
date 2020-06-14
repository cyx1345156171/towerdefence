#include "diren.h"

diren::diren(int x, int y, int id):x(x),y(y)
{
    if(id==0)
    {
        //0号代表铁头怪
        health=100;
        speed=20;
       ditu=QPixmap(":/1号怪.jpg");
        height=80;
        width=60;
        get=false;
    }
    if(id==1)
    {
        //1号 楞头怪
        health=100;
        speed=20;
       ditu=QPixmap(":/2号怪.jpg");
        height=80;
        width=60;
        get=false;
    }
    if(id==2)
    {

            //1号 楞头怪
            health=100;
            speed=20;
           ditu=QPixmap(":/3号怪.jpg");
            height=80;
            width=60;
            get=false;

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
int diren::getbiao()
{
    return biaoji;
}
void diren::setbiao(int x)
{
    biaoji=x;
}
void diren::setget(bool x)
{
    get=x;
}
bool diren::getget()
{
    return get;
}
