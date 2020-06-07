#include "fouranniu.h"

fouranniu::fouranniu()
{

}
bool fouranniu::iscointain(int x1, int y1)
{
    if((x1>=x)&&(x1<=x+100)&&(y1>=y)&&(y1<=y+100))
        return true;
    else
        return false;
}
void fouranniu::setanniu(int x2, int y2, QPixmap s)
{
    x=x2;
    y=y2;
    tu=s;
}
int fouranniu::getx()
{
    return x;
}
int fouranniu::gety()
{
    return y;
}
QPixmap fouranniu::gettu()
{
    return tu;
}
