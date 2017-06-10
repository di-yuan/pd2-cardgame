#include "card3.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card3::Card3()
{
    if(game->getscreen()==2)
    {
        QPixmap c3;
        c3.load(":/img/33.png");
        c3 = c3.scaled(c3.width()*1/4,c3.height()*1/4,Qt::KeepAspectRatio);
        this->setPixmap(c3);

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}

void Card3::go()
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
    setPos(x(),y()-5);
}

