#include "card20.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "bullet.h"

extern Game * game;

Card20::Card20()
{
    if(game->getscreen()==2)
    {
        QPixmap c1;
        c1.load(":/img/20201.png");
        c1 = c1.scaled(c1.width()*1/2,c1.height()*1/2,Qt::KeepAspectRatio);
        this->setPixmap(c1);
    }
}

void Card20::keyPressEvent(QKeyEvent *event)
{
    if(game->getscreen()==2)
    {
        if(event->key() == Qt::Key_Left)
        {
            setPos(x()-10,y());
        }
        else if(event->key() == Qt::Key_Right)
        {
            setPos(x()+10,y());
        }
        else if(event->key() == Qt::Key_Up)
        {
            setPos(x(),y()-10);
        }
        else if(event->key() == Qt::Key_Down)
        {
            setPos(x(),y()+10);
        }
        else if(event->key() == Qt::Key_Space)
        {
            Bullet * bullet = new Bullet();
            bullet->setPos(x(),y());
            game->scene->addItem(bullet);
        }
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
    }
}
