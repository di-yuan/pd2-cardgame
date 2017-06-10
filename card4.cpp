#include "card4.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card4::Card4()
{
    if(game->getscreen()==2)
    {
        QPixmap c4;
        c4.load(":/img/44.png");
        c4 = c4.scaled(c4.width()*1/4,c4.height()*1/4,Qt::KeepAspectRatio);
        this->setPixmap(c4);

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}

void Card4::go()
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
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    if(a==1)
            setPos(x(),y()-10);
        else
            setPos(x(),y()+10);
        if(this->y()<220)
            a=-1;
}
