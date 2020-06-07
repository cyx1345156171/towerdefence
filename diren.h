#ifndef DIREN_H
#define DIREN_H
#include<QVector>
#include<QString>
#include<QPainter>
class diren
{
public:
    diren(int x,int y,int id,int number);
    int getx();
    int gety();
    void setx(int);
    void sety(int);
    int getspeed();
    QPixmap gettu();
private:
    int x,y;
    int height,width;
    int health;
    int speed;
    QPixmap ditu;
    int xuhao;    //序号

};

#endif // DIREN_H
