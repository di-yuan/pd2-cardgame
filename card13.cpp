#include "card13.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card13::Card13()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card13::go()
{
    setPos(x(),y()-4);
}
