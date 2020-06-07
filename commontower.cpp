#include "commontower.h"

commontower::commontower(int x1,int x2):ta(x1,x2)
{
    setpicture(QPixmap(":/common.png"));
    setran(100);
    setatt(15);
}
