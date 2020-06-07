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
private:
    int x,y;   //按钮的坐标
    QPixmap tu;
    int height,width;

};

#endif // FOURANNIU_H
