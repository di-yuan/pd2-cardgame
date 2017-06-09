#include "card11.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card11::Card11()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card11::go()
{
    setPos(x(),y()-4);
}
