#include "choice.h"


void choice::setchoice(int m1, int n1)
{
      x1=m1-80;
      y1=n1-80;
      QPixmap s= QPixmap(":/tu/first1.jpg");
      button[0].setanniu(x1+80,y1,s);
           //上面的按钮
      button[1].setanniu(x1,y1+80,QPixmap(":/tu/second1.jpg"));
            //左边的按钮
      button[2].setanniu(x1+160,y1+80,QPixmap(":/tu/third1.jpg"));
              //右边的按钮
      button[3].setanniu(x1+80,y1+160,QPixmap(":/tu/four1.jpg"));
             //下面的按钮
      display=true;
}
int choice::getheight1()
{
    return height1;
}
int choice::getwidth1()
{
    return width1;
}
int choice::getx()
{
    return x1;
}
int choice::gety()
{
    return y1;
}
void choice::setdisplay()
{
    display=false;
}
bool choice::getplay()
{
    return display;
}
