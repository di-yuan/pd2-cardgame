#ifndef EE_H
#define EE_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Ee: public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ee();

};
#endif // EE_H
