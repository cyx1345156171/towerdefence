#include"taposition.h"

taposition::taposition(int x, int y)
{
    this->px=x;
    this->py=y;
    ista=false;
}
void taposition::setista(bool x)
{
    ista=x;
}
bool taposition::returnista()
{
    return ista;
}
int taposition::getpx()
{
    return px;
}
int taposition::getpy()
{
    return py;
}
bool taposition::ifishere(int x, int y)
{
    if((x>=px)&&(x<=px+100)&&(y>=py)&&(y<=py+100))
        return true;
    else
        return false;
}
bool taposition::returnhasa()
{
    return hasagei;
}
void taposition::sethasa(bool x)
{
    hasagei=x;
}
