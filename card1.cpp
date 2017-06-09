#include "card1.h"
#include <QTimer>
#include <QList>
#include "card.h"
#include "game.h"

extern Game * game;

Card1::Card1()
{
    if(game->getscreen()==2)
    {
    QPixmap c1;
    c1.load(":/img/black.png");
    c1 = c1.scaled(70,70);
    this->setPixmap(c1);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(go()));

    timer->start(50);
    }
}

void Card1::go()
{
    setPos(x(),y()-4);
}
