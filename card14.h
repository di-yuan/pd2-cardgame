#ifndef CARD14_H
#define CARD14_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card14: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card14();
    Card * black;
    int i=0;
    int ballcount = 0;
    int a = 50;
    int circlecount;
    const int level=14;
public slots:
    void go();
};

#endif // CARD14_H

