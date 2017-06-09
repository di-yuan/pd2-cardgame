#ifndef CARD7_H
#define CARD7_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"

class Card7: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card7();
    Card * black;
    int i=0;
public slots:
    void go();
private:
    int level;
};

#endif // CARD7_H
