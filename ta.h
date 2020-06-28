#ifndef TA_H
#define TA_H
#include<QPainter>
#include<diren.h>
#include<QDebug>
#include"bullet.h"
class ta
{
public:
     QVector<bullet*> bulletvector;    //子弹数组
    ta(int,int,int);                // 构造函数
    int getx();          //塔的x坐标 获得
    int gety();         //塔的y坐标  获得
    int getatt();       //塔的攻击力 获得
    int getran();      //塔的范围    获得
    int getmoney();   //塔的钱       获得
    QPixmap getta();  //塔的图片       获得
    int getheight();
    int getwidth();    //塔的宽高获取
    QString getbullettu() const;  //返回防御塔子弹图片路径
    diren *gettarget();     //获取目标怪物
    void setran(int);    //设置攻击范围
    void setatt(int);      //设置攻击力
    void settarget(diren *);  //设置目标怪物
    void newbullet();             //新建子弹
    void movebullet();              //子弹移动函数
    QVector<bullet*>& getbullet();
    void setpicture(QPixmap x1);   //设置图片
    bool ishere(int,int);          //检查是否点击到了这个塔
    void sethasaqi(bool);           //设置 hasaqi (hasaqi是用于鼠标点击事件中俩次点击，且这个hasaqi是用于升级拆除功能)
    bool returnhasaqi();           //返回 hasaqi
    void updateangle();            //每个子弹的角度进行更新
    int distance(int,int);
    //~ta();
    void setchai(bool);
    bool getchai();
    void shengji();
    int getid();

private:
  int x,y;          //坐标
  int counter=0;
  int height,width;  //宽高
  QPixmap tapath;   //塔的图片
  int attact;      //攻击力
  int range;       //攻击范围
  int costmoney;  //花的钱
  diren * target=NULL;   //目标怪物
  int rangle;// 塔的角度
  bool  hasaqi=false;  //用于鼠标点击事件
  int rush=30;    //子弹的速度
  bool chai=false;  //塔是否拆除
  int id;    //子类塔的编号
};

#endif // TA_H
