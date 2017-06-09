#include "card15.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card15::Card15()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card15::go()
{
    setPos(x(),y()-4);
}
