#ifndef CARD14_H
#define CARD14_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card14: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card14();
    Card * black;
    int i=0;
public slots:
    void go();
private:
    int level;
};

#endif // CARD14_H

