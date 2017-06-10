#ifndef CARD7_H
#define CARD7_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card7: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card7();
    Card * black;
    int i=0;
    int ballcount = 0;
    int a = 50;
    int circlecount;
    const int level=7;
public slots:
    void go();
};

#endif // CARD7_H
