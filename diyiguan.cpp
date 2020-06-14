#include "diyiguan.h"
#include "ui_diyiguan.h"

diyiguan::diyiguan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diyiguan)
{
    ui->setupUi(this);
    setFixedSize(1200,800);
    settowerposition();
    setwaypoint();
    QTimer* jiazai=new QTimer();
    connect(jiazai,SIGNAL(timeout()),this,SLOT(loaddiren()));
    jiazai->start(2000);
    QTimer* first=new QTimer();
    connect(first,SIGNAL(timeout()),this,SLOT(move()));
    first->start(200);
}
void diyiguan::paintEvent(QPaintEvent *)
{
    QPainter pp(this);
    paintbackground(pp);
    painttaken(pp);
    paintta(pp);
    paintchoice(pp);
    paintdiren(pp);
    paintchaichu(pp);
    paintshengji(pp);
    painthouse(pp);
}
void diyiguan::painthouse(QPainter & x)
{
    x.drawPixmap(720,650,100,100,QPixmap(":/女神.png"));
}
void diyiguan::mousePressEvent(QMouseEvent * kk)
{
    int x1=kk->pos().x();
    int y1=kk->pos().y();
    //qDebug()<<x1<<" "<<y1;
    for(auto t1: tower)
    {
        if(t1->ishere(x1,y1)||t1->returnhasaqi())
        {
            if(!shengji.getdisplay())
            {
            shengji.setanniu(t1->getx(),t1->gety()-80,QPixmap(":/upup.jpg"));
            chaichu.setanniu(t1->getx(),t1->gety()+80,QPixmap(":/chaichai.jpg"));
            shengji.setdisplay(true);
            chaichu.setdisplay(true);
            t1->sethasaqi(true);
            update();
            return;
            }
            if(shengji.iscointain(x1,y1))
            {
                shengji.setdisplay(false);
                chaichu.setdisplay(false);
                t1->sethasaqi(false);
                update();
                return;
            }
            if(chaichu.iscointain(x1,y1))
            {
                chaichu.setdisplay(false);
                shengji.setdisplay(false);
                t1->sethasaqi(false);
                update();
                return;
              //  tower.erase(t1);
            }



        }
    }
    for(auto t : takeng)
    {
            if((!t->returnista()&&t->ifishere(x1,y1))||t->returnhasa())
            {
                if(!select->getplay())
                {
                select->setchoice(t->getpx(),t->getpy());
                update();
                t->sethasa(true);
                return;
                }
                for(int i=0;i<4;i++)
                {

                   if(select->button[i].iscointain(x1,y1)&&i==0)
                   {
                        //常规炮
                           tower.push_back(new commontower(t->getpx(),t->getpy()));
                           t->setista(true);
                           break;
                   }
                   else if(select->button[i].iscointain(x1,y1)&&i==1)
                   { //减速炮
                            tower.push_back(new slowtower(t->getpx(),t->getpy()));
                             t->setista(true);
                           break;
                   }
                    else if(select->button[i].iscointain(x1,y1)&&i==2)
                   {
                        //威力巨炮
                            tower.push_back(new powertower(t->getpx(),t->getpy()));
                             t->setista(true);
                           break;
                   }
                   else if(select->button[i].iscointain(x1,y1)&&i==3)
                   {
                       //加特林炮弹(速度快)
                            tower.push_back(new speedtower(t->getpx(),t->getpy()));
                             t->setista(true);
                           break;
                   }
                }
                t->sethasa(false);
                select->setdisplay();  // 将选择框再次变为 不显示
                update();
                return;
            }

    }
}
void diyiguan::paintchaichu(QPainter & x)
{
    if(chaichu.getdisplay())
    {
        x.drawPixmap(chaichu.getx(),chaichu.gety(),80,80,chaichu.gettu());
    }
}
void diyiguan::paintshengji(QPainter & x)
{
    if(shengji.getdisplay())
    {
        x.drawPixmap(shengji.getx(),shengji.gety(),80,80,shengji.gettu());
    }
}
void diyiguan::painttaken(QPainter & x)
{
    for(auto t1: takeng)
    {
        x.drawPixmap(t1->getpx(),t1->getpy(),80,80,QPixmap(":/tu/takeng.png"));
    }

}
void diyiguan::paintbackground(QPainter & x)
{

        x.drawPixmap(1,1,this->width(),this->height(),QPixmap(":/背景.jpg"));
}
void diyiguan::paintta(QPainter & x)   //画塔
{
    for(auto t2 : tower)
    {
        x.drawPixmap(t2->getx(),t2->gety(),80,80,t2->getta());
    }
}
void diyiguan::paintchoice(QPainter & x)   //画选择框
{
    if(select->getplay())
    {
    x.drawPixmap(select->getx(),select->gety(),240,240,QPixmap(":/coose.png"));
    for (int i = 0; i<=4; i++)
    {
       x.drawPixmap(select->button[i].getx(),select->button[i].gety(),80,80,select->button[i].gettu());
    }
    }

}
void diyiguan::paintdiren(QPainter & x)
{
    for(auto t : monster)
    {
        if(!t->getget())
        {
            x.drawPixmap(t->getx(),t->gety(),60,60,t->gettu());
        }
    }
}
void diyiguan::setwaypoint()
{
    way.push_back(new giao(340,450));
    way.push_back(new giao(600,450));
    way.push_back(new giao(600,350));
    way.push_back(new giao(1100,350));
    way.push_back(new giao(1100,650));
    way.push_back(new giao(820,650));
}
void diyiguan::settowerposition()
{
    takeng.push_back(new taposition(520,370));
    takeng.push_back(new taposition(430,560));
    takeng.push_back(new taposition(250,690));
    takeng.push_back(new taposition(250,460));
    takeng.push_back(new taposition(1000,560));
    takeng.push_back(new taposition(1100,250));
    takeng.push_back(new taposition(720,460));
    takeng.push_back(new taposition(1000,460));
    takeng.push_back(new taposition(750,270));
}
void diyiguan::move()
{
    for(auto t: monster)
 {
   if(!t->getget())
   {
     if(way.at(t->getbiao())->x>t->getx())
    {
        t->setx(t->getx()+t->getspeed());
    }
    else if(way.at(t->getbiao())->x<t->getx())
    {
         t->setx(t->getx()-t->getspeed());
    }
    else if(way.at(t->getbiao())->y>t->gety())
    {
        t->sety(t->gety()+t->getspeed());
    }
    else if(way.at(t->getbiao())->y<t->gety())
    {
        t->sety(t->gety()-t->getspeed());
    }
    else if (way.at(t->getbiao())->y ==t->gety()&& way.at(t->getbiao())->x == t->getx())
    {
        if(t->getbiao()==5)
        {
            t->setget(true);
        }
        else
        {
        t->setbiao(t->getbiao()+1);
        }

    }
   }
}
  update();
}
void diyiguan::loaddiren()
{
    time++;
    if(time<=3)
    {
    monster.push_back(new diren(340,750,0));
    }
    if(time>3&&time<=6)
    {
         monster.push_back(new diren(340,750,1));
    }
    if(time>6&&time<=9)
    {
         monster.push_back(new diren(340,750,2));
    }
}
diyiguan::~diyiguan()
{
    for (auto it =tower.begin(); it != tower.end(); it++)
    {
        delete *it;
        *it = NULL;
    }

    //释放选择框类SelBox
    delete select;
    select = NULL;

    //释放防御塔父类指针数组DefeTowerVec
    for (auto it = takeng.begin(); it != takeng.end(); it++)
    {
        delete *it;
        *it = NULL;
    }
    for (auto it = monster.begin(); it != monster.end(); it++)
    {
        delete *it;
        *it = NULL;
    }
    delete ui;
}
