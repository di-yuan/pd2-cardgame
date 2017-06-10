#include "card14.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card14::Card14()
{
    if(game->getscreen()==2)
    {
        int x =  (qrand()% 4)+1;
        switch(x)
        {
            case 1:
            {
                QPixmap c14;
                c14.load(":/img/14141.png");
                c14 = c14.scaled(c14.width()*1/2,c14.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c14);
                break;
            }
            case 2:
            {
                QPixmap c14;
                c14.load(":/img/14142.png");
                c14 = c14.scaled(c14.width()*1/2,c14.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c14);
                break;
            }
            case 3:
            {
                QPixmap c14;
                c14.load(":/img/14143.png");
                c14= c14.scaled(c14.width()*1/2,c14.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c14);
                break;
            }
            case 4:
            {
                QPixmap c14;
                c14.load(":/img/14144.png");
                c14= c14.scaled(c14.width()*1/2,c14.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c14);
                break;
            }

        }

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);

    }
}

void Card14::go()
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

    setPos(x(),y()-6);
}
