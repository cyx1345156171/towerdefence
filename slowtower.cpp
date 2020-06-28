#include "slowtower.h"

slowtower::slowtower(int x1,int x2):ta(x1,x2,1)
{
   setpicture(QPixmap(":/tu/second1.jpg"));
   setran(200);
   setatt(30);
}
