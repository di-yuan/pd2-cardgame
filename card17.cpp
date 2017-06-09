#include "card17.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card17::Card17()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card17::go()
{
    setPos(x(),y()-4);
}
