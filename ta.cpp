#include "ta.h"
ta::ta(int x1,int x2,int x3 )
{
    id=x3;
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
void ta::setatt(int x)
{
    attact=x;
}
void ta::setran(int x)
{
    range=x;
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
bool ta::ishere(int x1, int y1)
{
    if((x1>=x)&&(x1<=x+80)&&(y1>=y)&&(y1<=y+80))
        return true;
    else
        return false;
}
bool ta::returnhasaqi()
{
    return hasaqi;
}
void ta::sethasaqi(bool xxx)
{
    hasaqi=xxx;
}
void ta::newbullet()
{

        int gg,hh;
        bool temporary1;
         counter++;
          bullet *lishi=new bullet(x+40,y+40,id);
         if( target->getx()==x||counter<2||!(target->getx()+30-lishi->getx()-10)) //除数为0时
         {
             return;
         }
         if(id==0)
         {
             lishi->settu(QPixmap(":/tu/zidancommon.jpg"));
         }
         if(id==1)
         {
             lishi->settu(QPixmap(":/tu/zidan.jpg"));
         }
         if(id==2)
         {
             lishi->settu(QPixmap(":/tu/zidanpoison.jpg"));
         }
         if(id==3)
         {
             lishi->settu(QPixmap(":/tu/zidanpower.jpg"));
         }
        gg = (target->gety()+30 - lishi->gety()-10)/(target->getx()+30 -lishi->getx()-10);
             lishi->settan(gg); //设置计算路径的k值
        hh = target->gety()+30 - (target->getx()+30) * lishi->returntan();
             lishi->sethosa(hh);  //计算路径的b值
            if(target->getx()+30<lishi->getx()+10)
            {
                temporary1=false;
            }
            else
            {
                temporary1=true;
            }
       lishi->setangle(temporary1);    //设置方向
       bulletvector.push_back(lishi);
       counter=0;

}
void ta::movebullet()
{
    for(auto x1=bulletvector.begin();x1!=bulletvector.end();x1++)
    {
      if(!((*x1)->getdirection()))
      {
          (*x1)->setbullet((*x1)->getx()-rush,(*x1)->gety());
          (*x1)->setbullet((*x1)->getx(),(*x1)->getx()*(*x1)->returntan()+(*x1)->returnhosa());
      }
      else
      {
          (*x1)->setbullet((*x1)->getx()+rush,(*x1)->gety());
          (*x1)->setbullet((*x1)->getx(),(*x1)->getx()*(*x1)->returntan()+(*x1)->returnhosa());
      }
    }

    for(auto x1=bulletvector.begin();x1!=bulletvector.end();)
    {
        if(distance((*x1)->getx()+10,(*x1)->gety()+10)>range)     //如果子弹离开攻击范围消失
        {
            delete *x1;
            x1=bulletvector.erase(x1);
        }
        else
        {
            x1++;
        }
    }
}
/*void ta::updateangle()
{
    if(!target)
    {
        return;
    }
    else
    {
        int gg,hh;
        bool temporary1;
        for(auto x1=bulletvector.begin();x1!=bulletvector.end();x1++)
        {
            gg = (target->gety()+30 - (*x1)->gety()-10)/(target->getx()+30 -(*x1)->getx()-10);
            (*x1)->settan(gg);
            hh = target->gety()+30 - (target->getx()+30) * (*x1)->returntan();
           (*x1)->sethosa(hh);
            if(target->getx()+30<(*x1)->getx()+10)
            {
                temporary1=false;
            }
            else
            {
                temporary1=true;
            }
            (*x1)->setangle(temporary1);
        }
    }
}*/
QVector<bullet*>& ta::getbullet()
{
    return bulletvector;
}
int ta::distance(int x1, int y1)
{
    int temporary;
    double gg=(x1-x-40)*(x1-x-40)+(y1-y-40)*(y1-y-40);
    temporary=(int)sqrt(gg);
    return temporary;
}
/*ta::~ta()
{
    delete target;
    target=NULL;
    for(auto xx=bulletvector.begin();xx!=bulletvector.end();xx++)
    {
        delete *xx;
        *xx=NULL;
    }
}*/
void ta::setchai(bool mm)
{
    chai=mm;
}
bool ta::getchai()
{
    return chai;
}
void ta::shengji()
{
if(id==0)
{
    setpicture(QPixmap(":/tu/first2.jpg"));
    setatt(50);
    setran(350);
}
if(id==1)
{
    setpicture(QPixmap(":/tu/second2.jpg"));
    setatt(45);
    setran(400);
}
if(id==2)
{
    setpicture(QPixmap(":/tu/third2.jpg"));
    setatt(35);
    setran(250);
}
if(id==3)
{
    setpicture(QPixmap(":/tu/fourth2.jpg"));
    setatt(100);
    setran(350);
}
}
int ta::getid()
{
    return id;
}
