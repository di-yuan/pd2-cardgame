#include "card2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card2::Card2()
{
    if(game->getscreen()==2)
    {
        QPixmap c2;
        c2.load(":/img/22.png");
        c2 = c2.scaled(c2.width()*1/4,c2.height()*1/4,Qt::KeepAspectRatio);
        this->setPixmap(c2);

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}


void Card2::go()
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
        if (typeid(*(colliding_items[i])) == typeid(Ee))
        {
            game->hpy->decrease(2);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(),y()-6);
}
