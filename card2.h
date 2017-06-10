#ifndef CARD2_H
#define CARD2_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card2: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card2();
    Card * black;
    int i=0;
    const int level=2;
public slots:
    void go();
};

#endif // CARD2_H
