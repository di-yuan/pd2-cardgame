#ifndef CARD6_H
#define CARD6_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card6: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card6();
    Card * black;
    int i=0;
public slots:
    void go();
private:
    int level;
};

#endif // CARD6_H
