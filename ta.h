#ifndef TA_H
#define TA_H
#include<QPainter>
#include<diren.h>
#include<bulletzu.h>
class ta
{
public:
    ta(int,int);                // 构造函数
    int getx();          //塔的x坐标 获得
    int gety();         //塔的y坐标  获得
    int getatt();       //塔的攻击力 获得
    int getran();      //塔的范围    获得
    int getmoney();   //塔的钱       获得
    QPixmap getta();  //塔的图片       获得
    int getheight();
    int getrangle();  //塔的角度     获得
    int getwidth();    //塔的宽高获取
    QString getbullettu() const;  //返回防御塔子弹图片路径
    QVector<diren*>& getbulletvector();//返回子弹数组
    diren *gettarget();     //获取目标怪物
    void setrangle(int);   //设置旋转角度
    void setran(int);    //设置攻击范围
    void setatt(int);      //设置攻击力
    void settarget(diren *);  //设置目标怪物
    void newbullet();             //新建子弹
    void movebullet();              //子弹移动函数
    void setpicture(QPixmap x1);
    bool ishere(int,int);
    void sethasaqi(bool);
    bool returnhasaqi();

private:
  int x,y;          //坐标
  int height,width;  //宽高
  QPixmap tapath;   //塔的图片
  int attact;      //攻击力
  int range;       //攻击范围
  int costmoney;  //花的钱
  diren * target;   //目标怪物
  QString bullet;  //子弹的图片
  QVector<zidan*> bulletvector;    //子弹数组
  int rangle;// 塔的角度
  bool  hasaqi=false;  //用于鼠标点击事件
};

#endif // TA_H
