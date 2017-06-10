#include "card6.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "ee.h"
extern Game * game;
Card6::Card6()
{
    if(game->getscreen()==2)
    {
        QPixmap c6;
        c6.load(":/img/66.png");
        c6 = c6.scaled(c6.width()*1/3,c6.height()*1/3,Qt::KeepAspectRatio);
        this->setPixmap(c6);

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}

void Card6::go()
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

            if(ballcount%4==1)
                setPos(x()-a,y()-a-10);
            if(ballcount%4==2)
                setPos(x()-a,y()+a-10);
            if(ballcount%4==3)
                setPos(x()+a,y()+a-10);
            if(ballcount%4==0)
                setPos(x()+a,y()-a-10);
}
