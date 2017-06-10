#include "card11.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card11::Card11()
{
    if(game->getscreen()==2)
    {
        int x =  (qrand()% 5)+1;
        switch(x)
        {
            case 1:
            {
                QPixmap c11;
                c11.load(":/img/11111.png");
                c11 = c11.scaled(c11.width()*1/2,c11.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c11);
                break;
            }
            case 2:
            {
                QPixmap c11;
                c11.load(":/img/11112.png");
                c11 = c11.scaled(c11.width()*1/2,c11.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c11);
                break;
            }
            case 3:
            {
                QPixmap c11;
                c11.load(":/img/11113.png");
                c11 = c11.scaled(c11.width()*1/2,c11.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c11);
                break;
            }
            case 4:
            {
                QPixmap c11;
                c11.load(":/img/11114.png");
                c11 = c11.scaled(c11.width()*1/2,c11.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c11);
                break;
            }
            case 5:
            {
                QPixmap c11;
                c11.load(":/img/11115.png");
                c11 = c11.scaled(c11.width()*1/2,c11.height()*1/2,Qt::KeepAspectRatio);
                this->setPixmap(c11);
                break;
            }
        }

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }

}

void Card11::go()
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
