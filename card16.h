#ifndef CARD16_H
#define CARD16_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card16: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card16();
    Card * black;
    int i=0;
public slots:
    void go();
private:
    int level;
};

#endif // CARD16_H
