#include "hpi.h"
#include <QFont>
#include "game.h"

extern Game* game;

Hpi::Hpi(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 0
    hpI = 300;

    // draw the text
    setPlainText(QString::number(hpI)); // Health: 3
    setDefaultTextColor(Qt::black);
    setFont(QFont("ubuntu",22));
}

void Hpi::decrease(int i)
{
    hpI = hpI-i;
    setPlainText(QString::number(hpI)); // Health: 2
}

int Hpi::gethpi()
{
    return hpI;
}
