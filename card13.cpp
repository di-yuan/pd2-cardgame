#include "card13.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card13::Card13()
{
    if(game->getscreen()==2)
    {
        int x =  (qrand()% 3)+1;
        switch(x)
        {
            case 1:
            {
                QPixmap c13;
                c13.load(":/img/13131.png");
                c13 = c13.scaled(c13.width()*1/2,c13.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c13);
                break;
            }
            case 2:
            {
                QPixmap c13;
                c13.load(":/img/13132.png");
                c13 = c13.scaled(c13.width()*1/2,c13.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c13);
                break;
            }
            case 3:
            {
                QPixmap c13;
                c13.load(":/img/13133.png");
                c13= c13.scaled(c13.width()*1/2,c13.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c13);
                break;
            }

        }
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}

void Card13::go()
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
