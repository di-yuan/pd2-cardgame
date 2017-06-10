#include "hpy.h"
#include <QFont>
#include "game.h"
extern Game* game;

Hpy::Hpy(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 0
    hpY = 300;

    // draw the text
    setPlainText(QString::number(hpY)); // Health: 3
    setDefaultTextColor(Qt::black);
    setFont(QFont("ubuntu",22));
}

void Hpy::decrease(int i)
{
    hpY = hpY-i;
    setPlainText(QString::number(hpY)); // Health: 2
}
int Hpy::gethpy()
{
    return hpY;
}
