#ifndef CARD5_H
#define CARD5_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card5: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card5();
    Card * black;
    int i=0;
    const int level=5;
public slots:
    void go();
};

#endif // CARD5_H
