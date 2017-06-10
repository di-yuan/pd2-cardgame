#ifndef CARD18_H
#define CARD18_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card18: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card18();
    Card * black;
    int i=0;
    const int level=18;
public slots:
    void go();
};

#endif // CARD18_H

