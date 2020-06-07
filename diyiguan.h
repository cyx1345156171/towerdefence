#ifndef DIYIGUAN_H
#define DIYIGUAN_H
#include<QPainter>
#include <QWidget>
#include"taposition.h"
#include"ta.h"
#include <QDebug>
#include"choice.h"
#include"commontower.h"
#include"speedtower.h"
#include"powertower.h"
#include"slowtower.h"
#include <QMediaPlayer>
#include<QMouseEvent>
#include"diren.h"
#include"wayzu.h"


namespace Ui {
class diyiguan;
}

class diyiguan : public QWidget
{
    Q_OBJECT

public:
    explicit diyiguan(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void settowerposition();
    void painttaken(QPainter &);
    void paintbackground(QPainter &);
    void paintta(QPainter &);
    void paintchoice(QPainter &);
    bool move();
    ~diyiguan();

private:
    Ui::diyiguan *ui;
    QVector<taposition *> takeng;
    QVector<ta*> tower;
    choice * select = new choice;
    bool hasagei=false;     //用于鼠标点击事件
    QVector<diren*> monster;
    QVector<giao*> way;
};

#endif // DIYIGUAN_H
