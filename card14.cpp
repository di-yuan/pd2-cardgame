#include "card14.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card14::Card14()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card14::go()
{
    setPos(x(),y()-4);
}
