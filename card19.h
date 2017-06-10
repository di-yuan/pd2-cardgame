#ifndef CARD19_H
#define CARD19_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "card.h"

class Card19: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card19();
    Card * black;
    int i=0;
    QPixmap c19;
    QTimer * timer;
    const int level=19;
public slots:
    void go();
};

#endif // CARD19_H
