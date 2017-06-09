#include "card5.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card5::Card5()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card5::go()
{
    setPos(x(),y()-4);
}
