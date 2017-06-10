#include "card12.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card12::Card12()
{
    if(game->getscreen()==2)
    {
        QPixmap c12;
        c12.load(":/img/1212.png");
        c12 = c12.scaled(c12.width()*1/2,c12.height()*1/2,Qt::KeepAspectRatio);
        this->setPixmap(c12);

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}

void Card12::go()
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
    setPos(x(),y()-14);
}
