#ifndef CARD19_H
#define CARD19_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card19: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card19();
    Card * black;
    int i=0;
public slots:
    void go();
private:
    int level;
};

#endif // CARD19_H
