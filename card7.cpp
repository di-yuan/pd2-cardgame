#include "card7.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "ee.h"
extern Game * game;
Card7::Card7()
{
    if(game->getscreen()==2)
    {
        QPixmap c7;
        c7.load(":/img/77.png");
        c7 = c7.scaled(c7.width()*1/2,c7.height()*1/2,Qt::KeepAspectRatio);
        this->setPixmap(c7);

        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(go()));

        timer->start(50);
    }
}

void Card7::go()
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
    if (ballcount==99)
        circlecount++;

    if(circlecount==4)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

    if(ballcount%4==1)
        setPos(x()-a,y()-a);
    if(ballcount%4==2)
        setPos(x()-a,y()+a);
    if(ballcount%4==3)
        setPos(x()+a,y()+a);
    if(ballcount%4==0)
        setPos(x()+a,y()-a);

}
