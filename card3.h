#ifndef CARD3_H
#define CARD3_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card3: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card3();
    Card * black;
    int i=0;
    const int level=3;
public slots:
    void go();
};

#endif // CARD3_H
