#include "card9.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card9::Card9()
{
    if(game->getscreen()==2)
    {
        QPixmap c9;
        c9.load(":/img/99.png");
        c9 = c9.scaled(c9.width()*1/2,c9.height()*1/2,Qt::KeepAspectRatio);
        this->setPixmap(c9);

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}

void Card9::go()
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

    ballcount++;
        a=10;
        if(ballcount%2==1)
            setPos(x()+a,y()-a);
        if(ballcount%2==0)
            setPos(x()-1/2*a,y()-a);
}
