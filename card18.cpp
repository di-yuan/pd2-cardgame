#include "card18.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card18::Card18()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card18::go()
{
    setPos(x(),y()-4);
}
