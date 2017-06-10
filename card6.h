#ifndef CARD6_H
#define CARD6_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card6: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card6();
    Card * black;
    int i=0;
    const int level=6;
    int ballcount = 0;
    int a = 40;
    int circlecount;
public slots:
    void go();
};

#endif // CARD6_H
