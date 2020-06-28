#include "diyiguan.h"
#include "ui_diyiguan.h"

diyiguan::diyiguan(int x) :levelnumber(x),
    ui(new Ui::diyiguan)
{
    QMediaPlayer * player=new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/music/jojo.mp3"));
    player->setVolume(10);
    player->play();
    ui->setupUi(this);
    setFixedSize(1200,800);
    win->move(200, 300);
    QFont m;
    m.setPointSize(100);
    win->setFont(m);
    win->setStyleSheet("color:red;");
    win->setText(QString("YOU WIN!"));
    lose->setFont(m);
    lose->setStyleSheet("color:red;");
    lose->setText(QString("YOU LOSE!"));
    lose->hide();
    win->hide();
    settowerposition();
    setwaypoint();
    costmoney(0);
    updatelife(0);
    updatewave(0);
    QTimer* jiazai=new QTimer();
    connect(jiazai,SIGNAL(timeout()),this,SLOT(loaddiren()));
    jiazai->start(1000);
    QTimer* first=new QTimer();
    connect(first,SIGNAL(timeout()),this,SLOT(move()));
    first->start(100);

}
int diyiguan::distance(int x1, int y1, int x2, int y2)
{
    int temporary;
    double gg=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    temporary=(int)sqrt(gg);
    return temporary;
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
    paintzidan(pp);
    paintskill(pp);
}
void diyiguan::painthouse(QPainter & x)
{
    x.drawPixmap(720,650,100,100,QPixmap(":/tu/女神.png"));
}
void diyiguan::mousePressEvent(QMouseEvent * kk)    //鼠标点击事件
{
    int x1=kk->pos().x();
    int y1=kk->pos().y();
    //qDebug()<<x1<<" "<<y1;
    if(x1>=200&&x1<=300&&y1>=20&&y1<=120&&costmoney(60))
    {
        for(auto gsr:monster)
        {
            gsr->sethealth(50);
            if(gsr->gethealth()<=0)
            {
                gsr->setget(true);
            }
        }
        return;
    }
    for(auto t1: tower)
    {
        if(t1->ishere(x1,y1)||t1->returnhasaqi())
        {
            if(!shengji.getdisplay())
            {
            shengji.setanniu(t1->getx(),t1->gety()-80,QPixmap(":/tu/upup.jpg"));
            chaichu.setanniu(t1->getx(),t1->gety()+80,QPixmap(":/tu/chaichai.jpg"));
            shengji.setdisplay(true);
            chaichu.setdisplay(true);
            t1->sethasaqi(true);
            update();
            return;
            }
            if(shengji.iscointain(x1,y1)&&costmoney(200))
            {
                t1->shengji();
            }
            if(chaichu.iscointain(x1,y1))
            {
                for(auto ggh:takeng)
                {
                    if(ggh->getpx()==t1->getx()&&ggh->getpy()==t1->gety())
                    {
                        ggh->setista(false);
                        break;
                    }
                }
                t1->setchai(true);
                money=money+100;
                costmoney(0);
            }
            chaichu.setdisplay(false);
            shengji.setdisplay(false);
            t1->sethasaqi(false);
            update();
            return;

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

                   if(select->button[i].iscointain(x1,y1)&&i==0&&costmoney(100))
                   {
                        //常规炮
                           tower.push_back(new commontower(t->getpx(),t->getpy()));
                           t->setista(true);
                           break;
                   }
                   else if(select->button[i].iscointain(x1,y1)&&i==1&&costmoney(120))
                   { //减速他
                            tower.push_back(new slowtower(t->getpx(),t->getpy()));
                             t->setista(true);
                           break;
                   }
                    else if(select->button[i].iscointain(x1,y1)&&i==2&&costmoney(150))
                   {
                        //毒塔
                            tower.push_back(new powertower(t->getpx(),t->getpy()));
                             t->setista(true);
                           break;
                   }
                   else if(select->button[i].iscointain(x1,y1)&&i==3&&costmoney(120))
                   {
                       //重炮塔
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
void diyiguan::paintzidan(QPainter & x)
{
    for(auto t1: tower)
    {
        for(auto x1:t1->bulletvector)
        {
            x.drawPixmap(x1->getx(),x1->gety(),20,20,x1->gettu());
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
    if(levelnumber==1)
    {
        x.drawPixmap(1,1,this->width(),this->height(),QPixmap(":/tu/background.jpg"));
    }
    if(levelnumber==2)
    {
        x.drawPixmap(1,1,this->width(),this->height(),QPixmap(":/tu/back2.png"));
    }
}
void diyiguan::paintta(QPainter & x)   //画塔
{
    for(auto t2 : tower)
    {
        x.drawPixmap(t2->getx(),t2->gety(),80,80,t2->getta());
        if(t2->getid()==0)
        {
        x.setPen(QPen(Qt::yellow, 6, Qt::SolidLine));     //设置画笔
        }
        if(t2->getid()==1)
        {
             x.setPen(QPen(Qt::green, 6, Qt::SolidLine));     //设置画笔
        }
        if(t2->getid()==2)
        {
             x.setPen(QPen(Qt::blue, 6, Qt::SolidLine));     //设置画笔
        }
        if(t2->getid()==3)
        {
             x.setPen(QPen(Qt::red, 6, Qt::SolidLine));     //设置画笔
        }
        x.drawEllipse(t2->getx()+40-t2->getran(),t2->gety()+40-t2->getran(),2* t2->getran(),2* t2->getran());
    }
}
void diyiguan::paintchoice(QPainter & x)   //画选择框
{
    if(select->getplay())
    {
    //x.drawPixmap(select->getx(),select->gety(),240,240,QPixmap(":/tu/mymade.png"));
    for (int i = 0; i<=4; i++)
    {
       x.drawPixmap(select->button[i].getx(),select->button[i].gety(),80,80,select->button[i].gettu());
    }
    }

}
void diyiguan::paintskill(QPainter & x)
{
    x.drawPixmap(200,20,100,100,QPixmap(":/tu/skill.jpg"));
}
void diyiguan::paintdiren(QPainter & x)
{
    for(auto t : monster)
    {
        if(t->getpoision()&&!t->getgod())
        {
            x.drawPixmap(t->getx(),t->gety()-20,60,20,QPixmap(":/tu/poison.jpg"));
        }
        if(t->getice()&&!t->getgod())
        {
            x.drawPixmap(t->getx(),t->gety()+61,60,20,QPixmap(":/tu/ice.jpg"));
        }
        if(t->getgod())
        {
            x.drawPixmap(t->getx(),t->gety()-20,60,20,QPixmap(":/tu/diogod.jpg"));
        }
            x.drawPixmap(t->getx(),t->gety(),60,60,t->gettu());
            x.setPen(Qt::red);
            x.drawRect(t->getx(),t->gety()+60,60,1);
            x.setPen(Qt::green);
            x.drawRect(t->getx(),t->gety()+60,60*t->gethealth()/100,1);
    }
}
void diyiguan::setwaypoint()
{
    if(levelnumber==1)
    {
    way.push_back(new giao(340,450));
    way.push_back(new giao(600,450));
    way.push_back(new giao(600,350));
    way.push_back(new giao(1100,350));
    way.push_back(new giao(1100,650));
    way.push_back(new giao(820,650));
    }
    else
    {
    way.push_back(new giao(50,150));
    way.push_back(new giao(510,150));
    way.push_back(new giao(510,470));
    way.push_back(new giao(910,470));
    way.push_back(new giao(910,190));
    way.push_back(new giao(1170,190));
    }
}
void diyiguan::settowerposition()
{
    if(levelnumber==1)
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
    else
    {
    takeng.push_back(new taposition(30,50));
    takeng.push_back(new taposition(210,590));
    takeng.push_back(new taposition(210,340));
    takeng.push_back(new taposition(400,260));
    takeng.push_back(new taposition(650,380));
    takeng.push_back(new taposition(810,380));
    takeng.push_back(new taposition(910,100));
    takeng.push_back(new taposition(650,150));
    }
}
void diyiguan::move()
{
    for(auto tt=tower.begin();tt!=tower.end();)
    {
        if((*tt)->getchai())
        {
            delete *tt;
            tt=tower.erase(tt);
        }
        else
        {
            tt++;
        }
     }
    for(auto t0: tower)
    {
       if(!t0->gettarget())   //设置攻击目标
       {
           for(auto x1=monster.end()-1;x1>=monster.begin();x1--)
           {
               if(distance(t0->getx()+40,t0->gety()+40,(*x1)->getx()+30,(*x1)->gety()+30)<=t0->getran())
               {
                   t0->settarget(*x1);
                   break;
               }
           }
       }
       else
       {
               t0->newbullet();    //生成子弹
               //超过范围  设置目标为空
               if(distance(t0->getx()+40,t0->gety()+40,t0->gettarget()->getx()+30,t0->gettarget()->gety()+30)>t0->getran())
               {
                   t0->settarget(NULL);
               }
       }
    }
    for(auto t1:tower)
    {
        t1->movebullet();
    }
    for (auto t2 : tower)  //防御塔
    {
        for (auto tutu = monster.begin(); tutu != monster.end();tutu++)
        {
          for (auto linbullet = t2->bulletvector.begin(); linbullet != t2->bulletvector.end();)    //子弹
             {

                //判断是否打中

                if (((*linbullet)->getx() + 10 >= (*tutu)->getx() )&&( (*linbullet)->getx() <= (*tutu)->getx() + 30) && ((*linbullet)->gety() + 10 >= (*tutu)->gety()) &&((*linbullet)->gety() <= (*tutu)->gety() + 30))
                {
                    int mycar=(*linbullet)->getxuhao();
                    delete *linbullet;
                    linbullet=t2->bulletvector.erase(linbullet);     //删除子弹
                    if(mycar==1)
                    {
                        (*tutu)->setstate(false,true);
                    }
                    if(mycar==2)
                    {
                        (*tutu)->setstate(true,false);
                    }
                    (*tutu)->sethealth(t2->getatt());
                    if ((*tutu)->gethealth() <= 0) //生命值为空时
                    {
                        for (auto kk : tower)
                            if (kk->gettarget() == *tutu)
                             {
                                kk->settarget(NULL);
                             }
                          (*tutu)->setget(true);
                        money=money+100;
                        costmoney(0);
                    }
                }
                else
                {
                    linbullet++;
                }
            }
        }
    }
    //怪物的移动
    for(auto t: monster)
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
            updatelife(1);
            if(lifehealth<=0)
            {
                for(auto gg:monster)
                {
                    gg->setget(true);
                }
                lose->show();
             }
            t->setget(true);
        }
        else
        {
        t->setbiao(t->getbiao()+1);
        }   
   }
}
    for(auto yy=monster.begin();yy!=monster.end();yy++)
    {
        if((*yy)->getget())
        {
              delete *yy;
             monster.erase(yy);
             break;
        }
    }
    //判断是否处于中毒状态
    for(auto zz:monster)
    {
        if(zz->getpoision()&&!zz->getgod())
        {
            zz->sethealth(10);    //中毒的话每次掉10滴血
            if(zz->gethealth()<=0)
            {
                zz->setget(true);
            }

        }
        if(zz->getice()&&!zz->getgod())
        {
            if(zz->getxuhao()==0)
            zz->setspeed(2);    //冷冻状态速度减半
            if(zz->getxuhao()==1)
            zz->setspeed(5);    //冷冻状态速度减半
        }
    }

  update();
}
void diyiguan::loaddiren()
{
    time++;
    if(time>=5&&time<=10)
    {
        if(levelnumber==1)
        {
     monster.push_back(new diren(340,750,0));
        }
        else
        {
    monster.push_back(new diren(50,750,0));
        }
    }
    if(time>10&&time<=15)
    {
        if(levelnumber==1)
        {
     monster.push_back(new diren(340,750,1));
        }
        else
        {
    monster.push_back(new diren(50,750,1));
        }
    }
    if(time==18)
    {
    updatewave(1);
    }
    if(time>=18&&time<=25)
    {
         if(levelnumber==1)
         monster.push_back(new diren(340,750,1));
         else
         monster.push_back(new diren(50,750,1));
    }
    if(time==30)
    {
    updatewave(1);
    }
    if(time>29&&time<=35)
    {
         if(levelnumber==1)
         monster.push_back(new diren(340,750,1));
         else
         monster.push_back(new diren(50,750,1));
    }
    if(time>=36&&time<=40)
    {
        if(levelnumber==1)
        {
     monster.push_back(new diren(340,750,2));
        }
        else
        {
    monster.push_back(new diren(50,750,2));
        }
    }
    if(monster.empty()&&time>40&&lifehealth>0)
    {
        win->show();
    }
}
bool diyiguan::costmoney(int g)
{
    if(money<g)
    {
        return false;
    }
    else
    {
        money=money-g;
        QFont font;
        font.setPointSize(18);
        ui->energy->setText(QString("女神能量: %1").arg(money));
        ui->energy->setFont(font);
        ui->energy->setStyleSheet("color:red;");
        return true;
    }
}
void diyiguan::updatelife(int gg)
{
    lifehealth=lifehealth-gg;
    QFont m;
    m.setPointSize(18);
    ui->life->setText(QString("生命值: %1").arg(lifehealth));
    ui->life->setFont(m);
    ui->life->setStyleSheet("color:red;");
}
void diyiguan::updatewave(int x)
{
    wave=wave+x;
    QFont m;
    m.setPointSize(18);
    ui->wave->setText(QString("Wave: %1").arg(wave));
    ui->wave->setFont(m);
    ui->wave->setStyleSheet("color:red;");
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
    for(auto it = way.begin();it!=way.end();it++)
    {
        delete *it;
        *it=NULL;
    }
    delete ui;
}
void diyiguan::setlevel(int x)
{
    levelnumber=x;
}
