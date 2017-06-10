#ifndef CARD10_H
#define CARD10_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card10: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card10();
    Card * black;
    int i=0;
    const int level=10;
public slots:
    void go();
};

#endif // CARD10_H
