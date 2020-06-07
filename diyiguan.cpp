#include "diyiguan.h"
#include "ui_diyiguan.h"

diyiguan::diyiguan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diyiguan)
{
    ui->setupUi(this);
    setFixedSize(1200,800);
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl(":/../../hdl.mp3"));
    player->setVolume(60);
    player->play();
    settowerposition();
}
void diyiguan::paintEvent(QPaintEvent *)
{
    QPainter pp(this);
    paintbackground(pp);
    painttaken(pp);
    paintta(pp);
    paintchoice(pp);

}
void diyiguan::mousePressEvent(QMouseEvent * kk)
{
    int x1=kk->pos().x();
    int y1=kk->pos().y();
    //qDebug()<<x1<<" "<<y1;
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
                           break;
                   }
                   else if(select->button[i].iscointain(x1,y1)&&i==1)
                   { //减速炮
                            tower.push_back(new slowtower(t->getpx(),t->getpy()));
                           break;
                   }
                    else if(select->button[i].iscointain(x1,y1)&&i==2)
                   {
                        //威力巨炮
                            tower.push_back(new powertower(t->getpx(),t->getpy()));
                           break;
                   }
                   else if(select->button[i].iscointain(x1,y1)&&i==3)
                   {
                       //加特林炮弹(速度快)
                            tower.push_back(new speedtower(t->getpx(),t->getpy()));
                           break;
                   }
                }
                t->sethasa(false);
                t->setista(true);
                select->setdisplay();  // 将选择框再次变为 不显示
                update();
                return;
            }

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
/*bool diyiguan::move()
{
    if(way.empty())
    {
        return true;
    }
    if(way.at(0)->x>x)
    {
        x=x+speed;
        return false;
    }
    if(way.at(0)->x<x)
    {
        x=x-speed;
        return false;
    }
    if(way.at(0)->y>y)
    {
        y=y+speed;
        return false;
    }
    if(way.at(0)->y<y)
    {
        y=y-speed;
    }
    if (way.at(0)->y == y && way.at(0)->x == x)
    {
        delete way.begin();                //释放坐标点内存
        way.erase(way.begin());       //从数组中删除

      return false;
    }






















}*/
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
    delete ui;
}
