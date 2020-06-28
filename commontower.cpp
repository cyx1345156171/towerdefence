#include "commontower.h"

commontower::commontower(int x1,int x2):ta(x1,x2,0)
{
    setpicture(QPixmap(":/tu/first1.jpg"));
    setran(200);
    setatt(30);
}

