#include "card20.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card20::Card20()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card20::go()
{
    setPos(x(),y()-4);
}
