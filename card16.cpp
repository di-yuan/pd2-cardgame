#include "card16.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card16::Card16()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card16::go()
{
    setPos(x(),y()-4);
}
