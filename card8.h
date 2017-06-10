#ifndef CARD8_H
#define CARD8_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card8: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card8();
    Card * black;
    int i=0;
    const int level=8;
public slots:
    void go();
};

#endif // CARD8_H
