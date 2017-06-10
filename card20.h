#ifndef CARD20_H
#define CARD20_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "card.h"
#include <QKeyEvent>

class Card20: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card20();
    Card * black;
    int i=0;
    void keyPressEvent(QKeyEvent *event);
    const int level=20;
};

#endif // CARD20_H
