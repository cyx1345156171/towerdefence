#include "speedtower.h"

speedtower::speedtower(int x1,int y1):ta(x1,y1,3)
{
  setpicture(QPixmap(":/tu/four1.jpg"));
  setran(200);
  setatt(25);
}
