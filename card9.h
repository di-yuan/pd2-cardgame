#ifndef CARD9_H
#define CARD9_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card9: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card9();
    Card * black;
    int i=0;
    int ballcount = 0;
    int a = 0;
    int circlecount;
    const int level=9;
public slots:
    void go();
};

#endif // CARD9_H
