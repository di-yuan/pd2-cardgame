#ifndef FIREBALL_H
#define FIREBALL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Fireball: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Fireball();
public slots:
    void move();
};

#endif // FIREBALL_H
