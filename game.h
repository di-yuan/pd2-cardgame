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
#include "enemy.h"
#include "fireball.h"
#include "csie.h"
#include "ee.h"
#include "hpi.h"
#include "hpy.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;

    void Init();
    void mousePressEvent(QMouseEvent *event);
    int getscreen();
    void Displaygameoverwindow(QString texttodisplay,int k);

    int numberofresult=0;
    QString scoretodisplay1 = " ";
    QString scoretodisplay2 = " ";
    QString scoretodisplay3 = " ";
    QString scoretodisplay4 = " ";
    QString scoretodisplay5 = " ";
    QString scoretodisplay6 = " ";
    QString scoretodisplay7 = " ";
    QString scoretodisplay8 = " ";
    int a[20];

    Hpi * hpi;
    Hpy * hpy;

    Card * start;
    Card * recordboard;
    Csie * csie;
    Ee * ee;
    Card * con;
    ShowTime *tt;
    Result *result;
    QPushButton * sbutton;
    QPushButton * cbutton;
    QPushButton * dbutton;
    QPushButton * qbutton;

    Fireball * fireball;

    int screenMode;
    int rand,randx,randy;
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

    QPushButton * button1;
    QPushButton * button2;
    QPushButton * button3;
    QPushButton * button4;
    QPushButton * button5;
    QPushButton * button6;
    QPushButton * button7;
    QPushButton * button8;
    QPushButton * button9;
    QPushButton * button10;
    QPushButton * button11;
    QPushButton * button12;
    QPushButton * button13;
    QPushButton * button14;
    QPushButton * button15;
    QPushButton * button16;
    QPushButton * button17;
    QPushButton * button18;
    QPushButton * button19;
    QPushButton * button20;

    Enemy * enemy1;
    Enemy * enemy2;
    Enemy * enemy3;
    Enemy * enemy4;

public slots:
    void cardmanage();
    void gameInit();
    void combine();
    void drawcard();
    void enemyShot();
    void Gameover();
    void change();
    void closebutton();
    void weapon1();
    void weapon2();
    void weapon3();
    void weapon4();
    void weapon5();
    void weapon6();
    void weapon7();
    void weapon8();
    void weapon9();
    void weapon10();
    void weapon11();
    void weapon12();
    void weapon13();
    void weapon14();
    void weapon15();
    void weapon16();
    void weapon17();
    void weapon18();
    void weapon19();
    void weapon20();

private:
    int i[20];
};

#endif // GAME_H
