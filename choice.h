#ifndef CHOICE_H
#define CHOICE_H
#include"QPainter"
#include"fouranniu.h"
class choice
{
public:
    void setchoice(int,int);
    int getx();
    int gety();
    int getwidth1();
    int getheight1();
    QString  gettu();
    void setdisplay();
    bool ifhere(int,int);
    bool getplay();
    fouranniu button[4];
private:
    bool display = false;   //是否显示
    int x1 = 0, y1 = 0;     //最左上角坐标
    int width1, height1; //整体宽高
    QPixmap choicetu;//选择框图片路径
};

#endif // CHOICE_H
