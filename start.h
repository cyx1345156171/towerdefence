#ifndef START_H
#define START_H

#include <QWidget>
#include<QMediaPlayer>


namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();
    void paintEvent(QPaintEvent *);

private:
    Ui::start *ui;
};

#endif // START_H
