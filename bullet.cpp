#include "bullet.h"
#include <QTimer>
#include <QList>
#include "game.h"

extern Game * game;

Bullet::Bullet()
{
    if(game->getscreen()==2)
    {
    QPixmap b;
    b.load(":/img/20202.png");
    b = b.scaled(b.width()*1/2,b.height()*1/2,Qt::KeepAspectRatio);
    this->setPixmap(b);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
    }
}

void Bullet::move()
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
    setPos(x(),y()-4);
}
