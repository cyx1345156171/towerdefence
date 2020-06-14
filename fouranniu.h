#ifndef FOURANNIU_H
#define FOURANNIU_H
#include"QPainter"

class fouranniu
{
public:
    fouranniu();
    bool iscointain(int,int);
    void setanniu(int,int,QPixmap);
    int getx();
    int gety();
    QPixmap gettu();
    bool getdisplay();
    void setdisplay(bool);
private:
    int x,y;   //按钮的坐标
    QPixmap tu;
    int height,width;
    bool display=false;
};

#endif // FOURANNIU_H
