#ifndef CARD4_H
#define CARD4_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card4: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card4();
    Card * black;
    int i=0;
public slots:
    void go();
private:
    int level;
};

#endif // CARD4_H
