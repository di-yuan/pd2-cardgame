#ifndef CARD20_H
#define CARD20_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card20: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card20();
    Card * black;
    int i=0;
public slots:
    void go();
private:
    int level;
};

#endif // CARD20_H
