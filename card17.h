#ifndef CARD17_H
#define CARD17_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card17: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card17();
    Card * black;
    int i=0;
    const int level=17;
public slots:
    void go();
};

#endif // CARD17_H
