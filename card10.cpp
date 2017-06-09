#include "card10.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card10::Card10()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}

void Card10::go()
{
    setPos(x(),y()-4);
}
