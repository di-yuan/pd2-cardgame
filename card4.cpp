#include "card4.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card4::Card4()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card4::go()
{
    setPos(x(),y()-4);
}
