#include "card1.h"
#include <QTimer>
#include <QList>
#include "card.h"
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card1::Card1()
{
    if(game->getscreen()==2)
    {
        QPixmap c1;
        c1.load(":/img/11(1).png");
        c1 = c1.scaled(c1.width()*1/4,c1.height()*1/4,Qt::KeepAspectRatio);
        this->setPixmap(c1);

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}

void Card1::go()
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
    setPos(x(),y()-7);
}
