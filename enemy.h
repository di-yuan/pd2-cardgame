#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "card1.h"
#include "card2.h"
#include "card3.h"
#include "card4.h"
#include "card5.h"
#include "card6.h"
#include "card7.h"
#include "card8.h"
#include "card9.h"
#include "card10.h"
#include "card11.h"
#include "card12.h"
#include "card13.h"
#include "card14.h"
#include "card15.h"
#include "card16.h"
#include "card17.h"
#include "card18.h"
#include "card19.h"
#include "card20.h"
#include "csie.h"
#include "bullet.h"

class Enemy: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
public slots:
    void go();
};

#endif // ENEMY_H
