#include "fireball.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"

Fireball::Fireball()
{
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Fireball::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    // move bullet up
    setPos(x(),y()-5);
}
