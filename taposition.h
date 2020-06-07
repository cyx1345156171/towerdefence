#ifndef TAPOSITION_H
#define TAPOSITION_H

#endif // TAPOSITION_H
#include<QPixmap>
#include<QSize>
class taposition
{
public:
    taposition(int,int);
     void setista(bool);
     bool returnista();
     int   getpx();
     int  getpy();
     bool ifishere(int ,int );
     void sethasa(bool);
     bool returnhasa();
private:
   int px;           //塔坑的坐标（左上角）
    int py;
    bool ista;      //是否有塔
     bool hasagei=false;     //用于鼠标点击事件

};
