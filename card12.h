#ifndef CARD12_H
#define CARD12_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card12: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card12();
    Card * black;
    int i=0;
    const int level=12;
public slots:
    void go();
};

#endif // CARD12_H
