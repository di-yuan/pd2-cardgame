#include "card19.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card19::Card19()
{
    if(game->getscreen()==2)
    {
        c19.load(":/img/1919.png");
        c19 = c19.scaled(200,200,Qt::KeepAspectRatio);
        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}

void Card19::go()
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
            game->hpy->decrease(2);
    }
    c19 = c19.scaled(c19.width()+5,c19.height()+5,Qt::KeepAspectRatio);
    this->setPixmap(c19);
    if(c19.width()>300)
    {
        timer->stop();
        scene()->removeItem(this);
    }
}
