#include "card8.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
#include<iostream>
extern Game * game;
Card8::Card8()
{
    if(game->getscreen()==2)
    {
        QPixmap c8;
        c8.load(":/img/88.png");
        c8 = c8.scaled(c8.width()*1/3,c8.height()*1/3,Qt::KeepAspectRatio);
        this->setPixmap(c8);

    /*    QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);*/
    }
}

void Card8::go()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            game->hpy->decrease(1);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    //setPos(x(),y()-4);
}

