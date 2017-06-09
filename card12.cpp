#include "card12.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card12::Card12()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card12::go()
{
    setPos(x(),y()-4);
}
