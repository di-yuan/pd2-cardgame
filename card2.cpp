#include "card2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Card2::Card2()
{
    QTimer * timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
}




void Card2::go()
{
    setPos(x(),y()-4);
}
