#include "diren.h"

diren::diren(int x, int y, int id):x(x),y(y),xuhao(id)
{
    if(id==0)
    {
        //0号代表铁头怪
        health=100;
        speed=5;
       ditu=QPixmap(":/tu/moster1.jpg");
        get=false;
    }
    if(id==1)
    {
        //1号 楞头怪
        health=100;
        speed=10;
       ditu=QPixmap(":/tu/monster2.jpg");
        get=false;
    }
    if(id==2)
    {
            //2号 楞头怪
        health=100;
           ditu=QPixmap(":/tu/monster3.jpg");
           speed=20;
            get=false;
            setgod(true);

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
int diren::gethealth()
{
    return health;
}
void diren::sethealth(int g)
{
    health=health-g;
}
void diren::setstate(bool x1, bool x2)
{
    poision=x1;
    ice=x2;
}
bool diren::getpoision()
{
    return poision;
}
bool diren::getice()
{
    return ice;
}
void diren::setspeed(int g)
{
    speed=g;
}
void diren::setgod(bool x)
{
    god=x;
}
bool diren::getgod()
{
    return god;
}
int diren::getxuhao()
{
    return xuhao;
}
