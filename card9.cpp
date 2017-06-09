#include "card9.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card9::Card9()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card9::go()
{
    setPos(x(),y()-4);
}
