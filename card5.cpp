#include "card5.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card5::Card5()
{
    if(game->getscreen()==2)
    {
        QPixmap c5;
        c5.load(":/img/55.png");
        c5 = c5.scaled(c5.width()*1/2,c5.height()*1/2,Qt::KeepAspectRatio);
        this->setPixmap(c5);

   /*     QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);*/
    }
}

void Card5::go()
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
    setPos(x(),y()-4);
}
