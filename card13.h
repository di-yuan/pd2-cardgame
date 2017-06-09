#ifndef CARD13_H
#define CARD13_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card13: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card13();
    Card * black;
    int i=0;
public slots:
    void go();
private:
    int level;
};

#endif // CARD13_H
