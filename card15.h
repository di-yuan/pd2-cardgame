#ifndef CARD15_H
#define CARD15_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card15: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card15();
    Card * black;
    int i=0;
    const int level=15;
public slots:
    void go();
};

#endif // CARD15_H
