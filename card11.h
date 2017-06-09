#ifndef CARD11_H
#define CARD11_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card11: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card11();
    Card * black;
    int i=0;
public slots:
    void go();
private:
    int level;
};

#endif // CARD11_H
