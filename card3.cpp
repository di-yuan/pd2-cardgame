#include "card3.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card3::Card3()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card3::go()
{
    setPos(x(),y()-4);
}
