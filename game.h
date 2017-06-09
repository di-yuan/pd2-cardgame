#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QTimer>
#include "showtime.h"
#include "result.h"
#include "card.h"
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
#include <QPushButton>
#include <stdio.h>
#include <stdlib.h>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;

    void Init();
    void bgChange();
    void cardmanage();
    void mousePressEvent(QMouseEvent *event);
    int getscreen();

    Card * start;
    Card * draw;
    ShowTime *tt;
    Result *result;
    QPushButton * sbutton;
    QPushButton * cbutton;

    int screenMode;
    int ran_card_1;
    int ran_card_2;
    int rand;
    //  QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;
    Card1 *card1;
    Card2 *card2;
    Card3 *card3;
    Card4 *card4;
    Card5 *card5;
    Card6 *card6;
    Card7 *card7;
    Card8 *card8;
    Card9 *card9;
    Card10 *card10;
    Card11 *card11;
    Card12 *card12;
    Card13 *card13;
    Card14 *card14;
    Card15 *card15;
    Card16 *card16;
    Card17 *card17;
    Card18 *card18;
    Card19 *card19;
    Card20 *card20;

    Card *card_1, *card_2;
    Card *card_11, *card_12, *card_13, *card_14;
    Card *card_21, *card_22, *card_23, *card_24;


public slots:
    void gameInit();
private:
    int i[20];
};

#endif // GAME_H
