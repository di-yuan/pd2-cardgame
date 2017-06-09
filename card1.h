#ifndef CARD1_H
#define CARD1_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card1: public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card1();
    Card * black;
    int i=0;
public slots:
    void go();
private:
    int level;  
};

#endif // CARD1_H
