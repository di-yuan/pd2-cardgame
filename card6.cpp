#include "card6.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card6::Card6()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card6::go()
{
    setPos(x(),y()-4);
}
