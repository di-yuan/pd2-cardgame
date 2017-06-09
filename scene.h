#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <QTime>
#include <QImage>
#include <QPixmap>
#include <QObject>
#include <QCoreApplication>
#include <QKeyEvent>
#include <QList>
#include <stdlib.h>

#include "game.h"
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

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    /* function */
    Scene(QObject *parent = 0);
    void Init(); // For screen initialize
    void bgChange(); // For background change from start to game
    void gameInit(); // Start the game page
    void cardmanage();
    //void changeCard(); //press card then change randomly
    void giveCard_1();
    void giveCard_2();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int getscreen();

    /* Variable */
    Game *game_start;
    Game *game_back;
    int game_w,game_h;
    int game_small_w,game_small_h;
    int sun_w,sun_h;
    int card_w,card_h;
    //for game
    ShowTime *tt;
    Result *result;

    // Use to control the scene page
    int screenMode;
    // For scene boundary
    int upperBound;
    int lowerBound;
    int leftBound;
    int rightBound;
    // For random card
    int ran_card_1;
    int ran_card_2;
    int rand;
    //  QTimer *timer;
    QTimer *timer2;
    QTimer *timer1;

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

/*public slots:
    void enemyCard();
    void collision();
    void over();
    void kill();*/
};

#endif // SCENE_H

