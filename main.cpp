#include "start.h"
#include"taposition.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start w;
    w.show();

    return a.exec();
}
