#include "card19.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card19::Card19()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card19::go()
{
    setPos(x(),y()-4);
}
