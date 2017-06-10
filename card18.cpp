#include "card18.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card18::Card18()
{
    if(game->getscreen()==2)
    {
        QPixmap c18;
        c18.load(":/img/1818.png");
        c18 = c18.scaled(c18.width()*1/2,c18.height()*1/2,Qt::KeepAspectRatio);
        this->setPixmap(c18);

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}

void Card18::go()
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
    setPos(x()+6,y());
}


