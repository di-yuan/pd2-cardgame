#include "card10.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card10::Card10()
{
    if(game->getscreen()==2)
    {
        QPixmap c10;
        c10.load(":/img/1010.png");
        c10 = c10.scaled(c10.width()*1/3,c10.height()*1/3,Qt::KeepAspectRatio);
        this->setPixmap(c10);

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}

void Card10::go()
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
    setPos(x(),y()+18);
}

