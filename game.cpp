#include "game.h"
#include <iostream>
#include <QCoreApplication>
#include <QTime>

Game::Game(QWidget *parent)
{
    //scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,375,667);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screenMode = 0;
    for(int i =0;i<20;i++)
    a[i]=-500;
}

void Game::Init()
{
    QImage bg;
    bg.load(":/img/bg0.png");
    bg = bg.scaled(375,667); // you can also change here
    this->setBackgroundBrush(bg);
    start = new Card();
    QPixmap s;
    s.load(":/img/play.png");
    s = s.scaled(133,44);
    start->setPixmap(s);
    start->setPos(128,550);
    scene->addItem(start);
}


void Game::cardmanage()
{
    scene->clear();
    screenMode = 1;
    QImage bg;
    bg.load(":/img/bg1.png");
    bg = bg.scaled(375,667);
    this->setBackgroundBrush(bg);
    card1 = new Card1();
    QPixmap c1;
    c1.load(":/img/1.png");
    c1 = c1.scaled(70,70);
    card1->setPixmap(c1);
    card1->setPos(22,28);
    scene->addItem(card1);
    card2 = new Card2();
    QPixmap c2;
    c2.load(":/img/2.png");
    c2 = c2.scaled(70,70);
    card2->setPixmap(c2);
    card2->setPos(109,28);
    scene->addItem(card2);
    card3 = new Card3();
    QPixmap c3;
    c3.load(":/img/3.png");
    c3 = c3.scaled(70,70);
    card3->setPixmap(c3);
    card3->setPos(196,28);
    scene->addItem(card3);
    card4 = new Card4();
    QPixmap c4;
    c4.load(":/img/4.png");
    c4 = c4.scaled(70,70);
    card4->setPixmap(c4);
    card4->setPos(283,28);
    scene->addItem(card4);
    card5 = new Card5();
    QPixmap c5;
    c5.load(":/img/5.png");
    c5 = c5.scaled(70,70);
    card5->setPixmap(c5);
    card5->setPos(22,120);
    scene->addItem(card5);
    card6 = new Card6();
    QPixmap c6;
    c6.load(":/img/6.png");
    c6 = c6.scaled(70,70);
    card6->setPixmap(c6);
    card7 = new Card7();
    QPixmap c7;
    c7.load(":/img/7.png");
    c7 = c7.scaled(70,70);
    card7->setPixmap(c7);
    card7->setPos(196,120);
    scene->addItem(card7);
    card8 = new Card8();
    QPixmap c8;
    c8.load(":/img/8.png");
    c8 = c8.scaled(70,70);
    card8->setPixmap(c8);
    card8->setPos(283,120);
    scene->addItem(card8);
    card9 = new Card9();
    QPixmap c9;
    c9.load(":/img/9.png");
    c9 = c9.scaled(70,70);
    card9->setPixmap(c9);
    card9->setPos(22,213);
    scene->addItem(card9);
    card10 = new Card10();
    QPixmap c10;
    c10.load(":/img/10.png");
    c10 = c10.scaled(70,70);
    card10->setPixmap(c10);
    card10->setPos(109,213);
    scene->addItem(card10);
    card11 = new Card11();
    QPixmap c11;
    c11.load(":/img/11.png");
    c11 = c11.scaled(70,70);
    card11->setPixmap(c11);
    card12 = new Card12();
    QPixmap c12;
    c12.load(":/img/12.png");
    c12 = c12.scaled(70,70);
    card12->setPixmap(c12);
    card12->setPos(283,213);
    scene->addItem(card12);
    card13 = new Card13();
    QPixmap c13;
    c13.load(":/img/13.png");
    c13 = c13.scaled(70,70);
    card13->setPixmap(c13);
    card14 = new Card14();
    QPixmap c14;
    c14.load(":/img/14.png");
    c14 = c14.scaled(70,70);
    card14->setPixmap(c14);
    card15 = new Card15();
    QPixmap c15;
    c15.load(":/img/15.png");
    c15 = c15.scaled(70,70);
    card15->setPixmap(c15);
    card16 = new Card16();
    QPixmap c16;
    c16.load(":/img/16.png");
    c16 = c16.scaled(70,70);
    card16->setPixmap(c16);
    card17 = new Card17();
    QPixmap c17;
    c17.load(":/img/17.png");
    c17 = c17.scaled(70,70);
    card17->setPixmap(c17);
    card18 = new Card18();
    QPixmap c18;
    c18.load(":/img/18.png");
    c18 = c18.scaled(70,70);
    card18->setPixmap(c18);
    card19 = new Card19();
    QPixmap c19;
    c19.load(":/img/19.png");
    c19 = c19.scaled(70,70);
    card19->setPixmap(c19);
    card19->setPos(196,397);
    scene->addItem(card19);
    card20 = new Card20();
    QPixmap c20;
    c20.load(":/img/20.png");
    c20 = c20.scaled(70,70);
    card20->setPixmap(c20);

    dbutton = new QPushButton(this);
    dbutton->setGeometry(50,500,70,70);
    dbutton->setIcon(QIcon(":/img/drawcard.png"));
    dbutton->setIconSize(QSize(70,70));
    connect(dbutton,SIGNAL(clicked()),this,SLOT(drawcard()));
    dbutton->show();

    sbutton = new QPushButton(this);
    sbutton->setGeometry(220,600,116,45);
    sbutton->setIcon(QIcon(":/img/start.png"));
    sbutton->setIconSize(QSize(116,45));
    connect(sbutton,SIGNAL(clicked()),this,SLOT(gameInit()));
    sbutton->show();

    cbutton = new QPushButton(this);
    cbutton->setGeometry(30,600,148,45);
    cbutton->setIcon(QIcon(":/img/combine.png"));
    cbutton->setIconSize(QSize(148,45));
    connect(cbutton,SIGNAL(clicked()),this,SLOT(combine()));
    cbutton->show();
}

void Game::gameInit()
{

    screenMode = 2;

    dbutton->close();
    sbutton->close();
    cbutton->close();
    scene->clear();
    QImage bg;
    bg.load(":/img/bg2.png");
    bg = bg.scaled(375,667); // you can also change here
    this->setBackgroundBrush(bg);
    csie = new Csie();
    QPixmap c;
    c.load(":/img/csie.png");
    c = c.scaled(c.width()*1/2,c.height()*1/2,Qt::KeepAspectRatio);
    csie->setPixmap(c);
    csie->setPos(0,380);
    scene->addItem(csie);
    ee = new Ee();
    QPixmap e;
    e.load(":/img/ee.png");
    e = e.scaled(e.width()*1/2,e.height()*1/2,Qt::KeepAspectRatio);
    ee->setPixmap(e);
    ee->setPos(0,50);
    scene->addItem(ee);
    tt = new ShowTime();
    tt->setPos(85,0);
    scene->addItem(tt);
    hpi = new Hpi();
    hpi->setPos(215,0);
    scene->addItem(hpi);
    hpy = new Hpy();
    hpy->setPos(315,0);
    scene->addItem(hpy);
    timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(enemyShot()));
    timer1->start(1000);
    int n=0;
    if(i[0]%2==1)
    {
        n++;
        button1 = new QPushButton(this);
        button1->setIcon(QIcon(":/img/1.png"));
        button1->setIconSize(QSize(70,70));
        connect(button1,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button1->setGeometry(22,569,70,70);
        if(n==2)
            button1->setGeometry(109,569,70,70);
        if(n==3)
            button1->setGeometry(196,569,70,70);
        if(n==4)
            button1->setGeometry(283,569,70,70);
        button1->show();
    }
    if(i[1]%2==1)
    {
        n++;
        button2 = new QPushButton(this);
        button2->setIcon(QIcon(":/img/2.png"));
        button2->setIconSize(QSize(70,70));
        connect(button2,SIGNAL(clicked()),this,SLOT(weapon2()));
        if(n==1)
            button2->setGeometry(22,569,70,70);
        if(n==2)
            button2->setGeometry(109,569,70,70);
        if(n==3)
            button2->setGeometry(196,569,70,70);
        if(n==4)
            button2->setGeometry(283,569,70,70);
        button2->show();
    }
    if(i[2]%2==1)
    {
        n++;
        button3 = new QPushButton(this);
        button3->setIcon(QIcon(":/img/3.png"));
        button3->setIconSize(QSize(70,70));
        connect(button3,SIGNAL(clicked()),this,SLOT(weapon3()));
        if(n==1)
            button3->setGeometry(22,569,70,70);
        if(n==2)
            button3->setGeometry(109,569,70,70);
        if(n==3)
            button3->setGeometry(196,569,70,70);
        if(n==4)
            button3->setGeometry(283,569,70,70);
        button3->show();
    }
    if(i[3]%2==1)
    {
        n++;
        button4 = new QPushButton(this);
        button4->setIcon(QIcon(":/img/4.png"));
        button4->setIconSize(QSize(70,70));
        connect(button4,SIGNAL(clicked()),this,SLOT(weapon4()));
        if(n==1)
            button4->setGeometry(22,569,70,70);
        if(n==2)
            button4->setGeometry(109,569,70,70);
        if(n==3)
            button4->setGeometry(196,569,70,70);
        if(n==4)
            button4->setGeometry(283,569,70,70);
        button4->show();
    }
    if(i[4]%2==1)
    {
        n++;
        button5 = new QPushButton(this);
        button5->setIcon(QIcon(":/img/5.png"));
        button5->setIconSize(QSize(70,70));
        connect(button5,SIGNAL(clicked()),this,SLOT(weapon5()));
        if(n==1)
            button5->setGeometry(22,569,70,70);
        if(n==2)
            button5->setGeometry(109,569,70,70);
        if(n==3)
            button5->setGeometry(196,569,70,70);
        if(n==4)
            button5->setGeometry(283,569,70,70);
        button5->show();
    }
    if(i[5]%2==1)
    {
        n++;
        button6 = new QPushButton(this);
        button6->setIcon(QIcon(":/img/6.png"));
        button6->setIconSize(QSize(70,70));
        connect(button6,SIGNAL(clicked()),this,SLOT(weapon6()));
        if(n==1)
            button6->setGeometry(22,569,70,70);
        if(n==2)
            button6->setGeometry(109,569,70,70);
        if(n==3)
            button6->setGeometry(196,569,70,70);
        if(n==4)
            button6->setGeometry(283,569,70,70);
        button6->show();
    }
    if(i[6]%2==1)
    {
        n++;
        button7 = new QPushButton(this);
        button7->setIcon(QIcon(":/img/7.png"));
        button7->setIconSize(QSize(70,70));
        connect(button7,SIGNAL(clicked()),this,SLOT(weapon7()));
        if(n==1)
            button7->setGeometry(22,569,70,70);
        if(n==2)
            button7->setGeometry(109,569,70,70);
        if(n==3)
            button7->setGeometry(196,569,70,70);
        if(n==4)
            button7->setGeometry(283,569,70,70);
        button7->show();
    }
    if(i[7]%2==1)
    {
        n++;
        button8 = new QPushButton(this);
        button8->setIcon(QIcon(":/img/8.png"));
        button8->setIconSize(QSize(70,70));
        connect(button8,SIGNAL(clicked()),this,SLOT(weapon8()));
        if(n==1)
            button8->setGeometry(22,569,70,70);
        if(n==2)
            button8->setGeometry(109,569,70,70);
        if(n==3)
            button8->setGeometry(196,569,70,70);
        if(n==4)
            button8->setGeometry(283,569,70,70);
        button8->show();
    }
    if(i[8]%2==1)
    {
        n++;
        button9 = new QPushButton(this);
        button9->setIcon(QIcon(":/img/9.png"));
        button9->setIconSize(QSize(70,70));
        connect(button9,SIGNAL(clicked()),this,SLOT(weapon9()));
        if(n==1)
            button9->setGeometry(22,569,70,70);
        if(n==2)
            button9->setGeometry(109,569,70,70);
        if(n==3)
            button9->setGeometry(196,569,70,70);
        if(n==4)
            button9->setGeometry(283,569,70,70);
        button9->show();
    }
    if(i[9]%2==1)
    {
        n++;
        button10 = new QPushButton(this);
        button10->setIcon(QIcon(":/img/10.png"));
        button10->setIconSize(QSize(70,70));
        connect(button10,SIGNAL(clicked()),this,SLOT(weapon10()));
        if(n==1)
            button10->setGeometry(22,569,70,70);
        if(n==2)
            button10->setGeometry(109,569,70,70);
        if(n==3)
            button10->setGeometry(196,569,70,70);
        if(n==4)
            button10->setGeometry(283,569,70,70);
        button10->show();
    }
    if(i[10]%2==1)
    {
        n++;
        button11 = new QPushButton(this);
        button11->setIcon(QIcon(":/img/11.png"));
        button11->setIconSize(QSize(70,70));
        connect(button11,SIGNAL(clicked()),this,SLOT(weapon11()));
        if(n==1)
            button11->setGeometry(22,569,70,70);
        if(n==2)
            button11->setGeometry(109,569,70,70);
        if(n==3)
            button11->setGeometry(196,569,70,70);
        if(n==4)
            button11->setGeometry(283,569,70,70);
        button11->show();
    }
    if(i[11]%2==1)
    {
        n++;
        button12 = new QPushButton(this);
        button12->setIcon(QIcon(":/img/12.png"));
        button12->setIconSize(QSize(70,70));
        connect(button12,SIGNAL(clicked()),this,SLOT(weapon12()));
        if(n==1)
            button12->setGeometry(22,569,70,70);
        if(n==2)
            button12->setGeometry(109,569,70,70);
        if(n==3)
            button12->setGeometry(196,569,70,70);
        if(n==4)
            button12->setGeometry(283,569,70,70);
        button12->show();
    }
    if(i[12]%2==1)
    {
        n++;
        button13 = new QPushButton(this);
        button13->setIcon(QIcon(":/img/13.png"));
        button13->setIconSize(QSize(70,70));
        connect(button13,SIGNAL(clicked()),this,SLOT(weapon13()));
        if(n==1)
            button13->setGeometry(22,569,70,70);
        if(n==2)
            button13->setGeometry(109,569,70,70);
        if(n==3)
            button13->setGeometry(196,569,70,70);
        if(n==4)
            button13->setGeometry(283,569,70,70);
        button13->show();
    }
    if(i[13]%2==1)
    {
        n++;
        button14 = new QPushButton(this);
        button14->setIcon(QIcon(":/img/14.png"));
        button14->setIconSize(QSize(70,70));
        connect(button14,SIGNAL(clicked()),this,SLOT(weapon14()));
        if(n==1)
            button14->setGeometry(22,569,70,70);
        if(n==2)
            button14->setGeometry(109,569,70,70);
        if(n==3)
            button14->setGeometry(196,569,70,70);
        if(n==4)
            button14->setGeometry(283,569,70,70);
        button14->show();
    }
    if(i[14]%2==1)
    {
        n++;
        button15 = new QPushButton(this);
        button15->setIcon(QIcon(":/img/15.png"));
        button15->setIconSize(QSize(70,70));
        connect(button15,SIGNAL(clicked()),this,SLOT(weapon15()));
        if(n==1)
            button15->setGeometry(22,569,70,70);
        if(n==2)
            button15->setGeometry(109,569,70,70);
        if(n==3)
            button15->setGeometry(196,569,70,70);
        if(n==4)
            button15->setGeometry(283,569,70,70);
        button15->show();
    }
    if(i[15]%2==1)
    {
        n++;
        button16 = new QPushButton(this);
        button16->setIcon(QIcon(":/img/16.png"));
        button16->setIconSize(QSize(70,70));
        connect(button16,SIGNAL(clicked()),this,SLOT(weapon16()));
        if(n==1)
            button16->setGeometry(22,569,70,70);
        if(n==2)
            button16->setGeometry(109,569,70,70);
        if(n==3)
            button16->setGeometry(196,569,70,70);
        if(n==4)
            button16->setGeometry(283,569,70,70);
        button16->show();
    }
    if(i[16]%2==1)
    {
        n++;
        button17 = new QPushButton(this);
        button17->setIcon(QIcon(":/img/17.png"));
        button17->setIconSize(QSize(70,70));
        connect(button17,SIGNAL(clicked()),this,SLOT(weapon17()));
        if(n==1)
            button17->setGeometry(22,569,70,70);
        if(n==2)
            button17->setGeometry(109,569,70,70);
        if(n==3)
            button17->setGeometry(196,569,70,70);
        if(n==4)
            button17->setGeometry(283,569,70,70);
        button17->show();
    }
    if(i[17]%2==1)
    {
        n++;
        button18 = new QPushButton(this);
        button18->setIcon(QIcon(":/img/18.png"));
        button18->setIconSize(QSize(70,70));
        connect(button18,SIGNAL(clicked()),this,SLOT(weapon18()));
        if(n==1)
            button18->setGeometry(22,569,70,70);
        if(n==2)
            button18->setGeometry(109,569,70,70);
        if(n==3)
            button18->setGeometry(196,569,70,70);
        if(n==4)
            button18->setGeometry(283,569,70,70);
        button18->show();
    }
    if(i[18]%2==1)
    {
        n++;
        button19 = new QPushButton(this);
        button19->setIcon(QIcon(":/img/19.png"));
        button19->setIconSize(QSize(70,70));
        connect(button19,SIGNAL(clicked()),this,SLOT(weapon19()));
        if(n==1)
            button19->setGeometry(22,569,70,70);
        if(n==2)
            button19->setGeometry(109,569,70,70);
        if(n==3)
            button19->setGeometry(196,569,70,70);
        if(n==4)
            button19->setGeometry(283,569,70,70);
        button19->show();
    }
    if(i[19]%2==1)
    {
        n++;
        button20 = new QPushButton(this);
        button20->setIcon(QIcon(":/img/20.png"));
        button20->setIconSize(QSize(70,70));
        connect(button20,SIGNAL(clicked()),this,SLOT(weapon20()));
        if(n==1)
            button20->setGeometry(22,569,70,70);
        if(n==2)
            button20->setGeometry(109,569,70,70);
        if(n==3)
            button20->setGeometry(196,569,70,70);
        if(n==4)
            button20->setGeometry(283,569,70,70);
        button20->show();
    }
    if(screenMode==2)
    {
        timer2 = new QTimer();
        connect(timer2,SIGNAL(timeout()),this,SLOT(Gameover()));
        timer2->start(500);
    }
}

void Game::combine()
{
    int x=0;
    if(i[0]%2==1)
    {
        x=x+card1->level;
        card1->i--;
        scene->removeItem(card1->black);
        scene->removeItem(card1);
    }
    if(i[1]%2==1)
    {
        x=x+card2->level;
        card2->i--;
        scene->removeItem(card2->black);
        scene->removeItem(card2);
    }
    if(i[2]%2==1)
    {
        x=x+card3->level;
        card3->i--;
        scene->removeItem(card3->black);
        scene->removeItem(card3);
    }
    if(i[3]%2==1)
    {
        x=x+card4->level;
        card4->i--;
        scene->removeItem(card4->black);
        scene->removeItem(card4);
    }
    if(i[4]%2==1)
    {
        x=x+card5->level;
        card5->i--;
        scene->removeItem(card5->black);
        scene->removeItem(card5);
    }
    if(i[5]%2==1)
    {
        x=x+card6->level;
        card6->i--;
        scene->removeItem(card6->black);
        scene->removeItem(card6);
    }
    if(i[6]%2==1)
    {
        x=x+card7->level;
        card7->i--;
        scene->removeItem(card7->black);
        scene->removeItem(card7);
    }
    if(i[7]%2==1)
    {
        x=x+card8->level;
        card8->i--;
        scene->removeItem(card8->black);
        scene->removeItem(card8);
    }
    if(i[8]%2==1)
    {
        x=x+card9->level;
        card9->i--;
        scene->removeItem(card9->black);
        scene->removeItem(card9);
    }
    if(i[9]%2==1)
    {
        x=x+card10->level;
        card10->i--;
        scene->removeItem(card10->black);
        scene->removeItem(card10);
    }
    if(i[10]%2==1)
    {
        x=x+card11->level;
        card11->i--;
        scene->removeItem(card11->black);
        scene->removeItem(card11);
    }
    if(i[11]%2==1)
    {
        x=x+card12->level;
        card12->i--;
        scene->removeItem(card12->black);
        scene->removeItem(card12);
    }
    if(i[12]%2==1)
    {
        x=x+card13->level;
        card13->i--;
        scene->removeItem(card13->black);
        scene->removeItem(card13);
    }
    if(i[13]%2==1)
    {
        x=x+card14->level;
        card14->i--;
        scene->removeItem(card14->black);
        scene->removeItem(card14);
    }
    if(i[14]%2==1)
    {
        x=x+card15->level;
        card15->i--;
        scene->removeItem(card15->black);
        scene->removeItem(card15);
    }
    if(i[15]%2==1)
    {
        x=x+card16->level;
        card16->i--;
        scene->removeItem(card16->black);
        scene->removeItem(card16);
    }
    if(i[16]%2==1)
    {
        x=x+card17->level;
        card17->i--;
        scene->removeItem(card17->black);
        scene->removeItem(card17);
    }
    if(i[17]%2==1)
    {
        x=x+card18->level;
        card18->i--;
        scene->removeItem(card18->black);
        scene->removeItem(card18);
    }
    if(i[18]%2==1)
    {
        x=x+card19->level;
        card19->i--;
        scene->removeItem(card19->black);
        scene->removeItem(card19);
    }
    if(i[19]%2==1)
    {
        x=x+card20->level;
        card20->i--;
        scene->removeItem(card20->black);
        scene->removeItem(card20);
    }
    if(x>20 && x<=40)
        x=x-20;
    if(x>40 && x<=60)
        x=x-40;
    if(x==1)
    {
        card1 = new Card1();
        QPixmap c1;
        c1.load(":/img/1.png");
        card1->setPixmap(c1);
        card1->setPos(125,150);
        scene->addItem(card1);
        QTime t1;
        t1.start();
        while(t1.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card1);
        card1 = new Card1();
        QPixmap cc1;
        cc1.load(":/img/1.png");
        cc1 = cc1.scaled(70,70);
        card1->setPixmap(cc1);
        card1->setPos(22,28);
        scene->addItem(card1);
    }
    if(x==2)
    {
        card2 = new Card2();
        QPixmap c2;
        c2.load(":/img/2.png");
        card2->setPixmap(c2);
        card2->setPos(125,150);
        scene->addItem(card2);
        QTime t2;
        t2.start();
        while(t2.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card2);
        card2 = new Card2();
        QPixmap cc2;
        cc2.load(":/img/2.png");
        cc2 = cc2.scaled(70,70);
        card2->setPixmap(cc2);
        card2->setPos(109,28);
        scene->addItem(card2);
    }
    if(x==3)
    {
        card3 = new Card3();
        QPixmap c3;
        c3.load(":/img/3.png");
        card3->setPixmap(c3);
        card3->setPos(125,150);
        scene->addItem(card3);
        QTime t3;
        t3.start();
        while(t3.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card3);
        card3 = new Card3();
        QPixmap cc3;
        cc3.load(":/img/3.png");
        cc3 = cc3.scaled(70,70);
        card3->setPixmap(cc3);
        card3->setPos(196,28);
        scene->addItem(card3);
    }
    if(x==4)
    {
        card4 = new Card4();
        QPixmap c4;
        c4.load(":/img/4.png");
        card4->setPixmap(c4);
        card4->setPos(125,150);
        scene->addItem(card4);
        QTime t4;
        t4.start();
        while(t4.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card4);
        card4 = new Card4();
        QPixmap cc4;
        cc4.load(":/img/4.png");
        cc4 = cc4.scaled(70,70);
        card4->setPixmap(cc4);
        card4->setPos(283,28);
        scene->addItem(card4);
    }
    if(x==5)
    {
        card5 = new Card5();
        QPixmap c5;
        c5.load(":/img/5.png");
        card5->setPixmap(c5);
        card5->setPos(125,150);
        scene->addItem(card5);
        QTime t5;
        t5.start();
        while(t5.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card5);
        card5 = new Card5();
        QPixmap cc5;
        cc5.load(":/img/5.png");
        cc5 = cc5.scaled(70,70);
        card5->setPixmap(cc5);
        card5->setPos(22,120);
        scene->addItem(card5);
    }
    if(x==6)
    {
        card6 = new Card6();
        QPixmap c3;
        c3.load(":/img/6.png");
        card6->setPixmap(c3);
        card6->setPos(125,150);
        scene->addItem(card6);
        QTime t3;
        t3.start();
        while(t3.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card6);
        card6 = new Card6();
        QPixmap cc3;
        cc3.load(":/img/6.png");
        cc3 = cc3.scaled(70,70);
        card6->setPixmap(cc3);
        card6->setPos(109,120);
        scene->addItem(card6);
    }
    if(x==7)
    {
        card7 = new Card7();
        QPixmap c7;
        c7.load(":/img/7.png");
        card7->setPixmap(c7);
        card7->setPos(125,150);
        scene->addItem(card7);
        QTime t7;
        t7.start();
        while(t7.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card7);
        card7 = new Card7();
        QPixmap cc7;
        cc7.load(":/img/7.png");
        cc7 = cc7.scaled(70,70);
        card7->setPixmap(cc7);
        card7->setPos(196,120);
        scene->addItem(card7);
    }
    if(x==8)
    {
        card8 = new Card8();
        QPixmap c8;
        c8.load(":/img/8.png");
        card8->setPixmap(c8);
        card8->setPos(125,150);
        scene->addItem(card8);
        QTime t8;
        t8.start();
        while(t8.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card8);
        card8 = new Card8();
        QPixmap cc8;
        cc8.load(":/img/8.png");
        cc8 = cc8.scaled(70,70);
        card8->setPixmap(cc8);
        card8->setPos(283,120);
        scene->addItem(card8);
    }
    if(x==9)
    {
        card9 = new Card9();
        QPixmap c9;
        c9.load(":/img/9.png");
        card9->setPixmap(c9);
        card9->setPos(125,150);
        scene->addItem(card9);
        QTime t9;
        t9.start();
        while(t9.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card9);
        card9 = new Card9();
        QPixmap cc9;
        cc9.load(":/img/9.png");
        cc9 = cc9.scaled(70,70);
        card9->setPixmap(cc9);
        card9->setPos(22,213);
        scene->addItem(card9);
    }
    if(x==10)
    {
        card10 = new Card10();
        QPixmap c10;
        c10.load(":/img/10.png");
        card10->setPixmap(c10);
        card10->setPos(125,150);
        scene->addItem(card10);
        QTime t10;
        t10.start();
        while(t10.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card10);
        card10 = new Card10();
        QPixmap cc10;
        cc10.load(":/img/10.png");
        cc10 = cc10.scaled(70,70);
        card10->setPixmap(cc10);
        card10->setPos(109,213);
        scene->addItem(card10);
    }
    if(x==11)
    {
        card11 = new Card11();
        QPixmap c;
        c.load(":/img/11.png");
        card11->setPixmap(c);
        card11->setPos(125,150);
        scene->addItem(card11);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card11);
        card11 = new Card11();
        QPixmap cc;
        cc.load(":/img/11.png");
        cc = cc.scaled(70,70);
        card11->setPixmap(cc);
        card11->setPos(196,213);
        scene->addItem(card11);
    }
    if(x==12)
    {
        card12 = new Card12();
        QPixmap c;
        c.load(":/img/12.png");
        card12->setPixmap(c);
        card12->setPos(125,150);
        scene->addItem(card12);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card12);
        card12 = new Card12();
        QPixmap cc;
        cc.load(":/img/12.png");
        cc = cc.scaled(70,70);
        card12->setPixmap(cc);
        card12->setPos(283,213);
        scene->addItem(card12);
    }
    if(x==13)
    {
        card13 = new Card13();
        QPixmap c;
        c.load(":/img/13.png");
        card13->setPixmap(c);
        card13->setPos(125,150);
        scene->addItem(card13);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card13);
        card13 = new Card13();
        QPixmap cc;
        cc.load(":/img/13.png");
        cc = cc.scaled(70,70);
        card13->setPixmap(cc);
        card13->setPos(22,305);
        scene->addItem(card13);
    }
    if(x==14)
    {
        card14 = new Card14();
        QPixmap c;
        c.load(":/img/14.png");
        card14->setPixmap(c);
        card14->setPos(125,150);
        scene->addItem(card14);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card14);
        card14 = new Card14();
        QPixmap cc;
        cc.load(":/img/14.png");
        cc = cc.scaled(70,70);
        card14->setPixmap(cc);
        card14->setPos(109,305);
        scene->addItem(card14);
    }
    if(x==15)
    {
        card15 = new Card15();
        QPixmap c;
        c.load(":/img/15.png");
        card15->setPixmap(c);
        card15->setPos(125,150);
        scene->addItem(card15);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card15);
        card15 = new Card15();
        QPixmap cc;
        cc.load(":/img/15.png");
        cc = cc.scaled(70,70);
        card15->setPixmap(cc);
        card15->setPos(196,305);
        scene->addItem(card15);
    }
    if(x==16)
    {
        card16 = new Card16();
        QPixmap c;
        c.load(":/img/16.png");
        card16->setPixmap(c);
        card16->setPos(125,150);
        scene->addItem(card16);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card16);
        card16 = new Card16();
        QPixmap cc;
        cc.load(":/img/16.png");
        cc = cc.scaled(70,70);
        card16->setPixmap(cc);
        card16->setPos(283,305);
        scene->addItem(card16);
    }
    if(x==17)
    {
        card17 = new Card17();
        QPixmap c;
        c.load(":/img/17.png");
        card17->setPixmap(c);
        card17->setPos(125,150);
        scene->addItem(card17);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card17);
        card17 = new Card17();
        QPixmap cc;
        cc.load(":/img/17.png");
        cc = cc.scaled(70,70);
        card17->setPixmap(cc);
        card17->setPos(22,397);
        scene->addItem(card17);
    }
    if(x==18)
    {
        card18 = new Card18();
        QPixmap c;
        c.load(":/img/18.png");
        card18->setPixmap(c);
        card18->setPos(125,150);
        scene->addItem(card18);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card18);
        card18 = new Card18();
        QPixmap cc;
        cc.load(":/img/18.png");
        cc = cc.scaled(70,70);
        card18->setPixmap(cc);
        card18->setPos(109,397);
        scene->addItem(card18);
    }
    if(x==19)
    {
        card19 = new Card19();
        QPixmap c;
        c.load(":/img/19.png");
        card19->setPixmap(c);
        card19->setPos(125,150);
        scene->addItem(card19);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card19);
        card19 = new Card19();
        QPixmap cc;
        cc.load(":/img/19.png");
        cc = cc.scaled(70,70);
        card19->setPixmap(cc);
        card19->setPos(196,397);
        scene->addItem(card19);
    }
    if(x==20)
    {
        card20 = new Card20();
        QPixmap c;
        c.load(":/img/20.png");
        card20->setPixmap(c);
        card20->setPos(125,150);
        scene->addItem(card20);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card20);
        card20 = new Card20();
        QPixmap cc;
        cc.load(":/img/20.png");
        cc = cc.scaled(70,70);
        card20->setPixmap(cc);
        card20->setPos(283,397);
        scene->addItem(card20);
    }
}

void Game::drawcard()
{
    int x = (qrand()% 20)+1;
    if(x==1)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card1 = new Card1();
        QPixmap c1;
        c1.load(":/img/1.png");
        card1->setPixmap(c1);
        card1->setPos(125,150);
        scene->addItem(card1);
        QTime t1;
        t1.start();
        while(t1.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card1);
        scene->removeItem(con);
        card1 = new Card1();
        QPixmap cc1;
        cc1.load(":/img/1.png");
        cc1 = cc1.scaled(70,70);
        card1->setPixmap(cc1);
        card1->setPos(22,28);
        scene->addItem(card1);
    }
    if(x==2)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card2 = new Card2();
        QPixmap c2;
        c2.load(":/img/2.png");
        card2->setPixmap(c2);
        card2->setPos(125,150);
        scene->addItem(card2);
        QTime t2;
        t2.start();
        while(t2.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card2);
        scene->removeItem(con);
        card2 = new Card2();
        QPixmap cc2;
        cc2.load(":/img/2.png");
        cc2 = cc2.scaled(70,70);
        card2->setPixmap(cc2);
        card2->setPos(109,28);
        scene->addItem(card2);
    }
    if(x==3)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card3 = new Card3();
        QPixmap c3;
        c3.load(":/img/3.png");
        card3->setPixmap(c3);
        card3->setPos(125,150);
        scene->addItem(card3);
        QTime t3;
        t3.start();
        while(t3.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card3);
        scene->removeItem(con);
        card3 = new Card3();
        QPixmap cc3;
        cc3.load(":/img/3.png");
        cc3 = cc3.scaled(70,70);
        card3->setPixmap(cc3);
        card3->setPos(196,28);
        scene->addItem(card3);
    }
    if(x==4)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card4 = new Card4();
        QPixmap c4;
        c4.load(":/img/4.png");
        card4->setPixmap(c4);
        card4->setPos(125,150);
        scene->addItem(card4);
        QTime t4;
        t4.start();
        while(t4.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card4);
        scene->removeItem(con);
        card4 = new Card4();
        QPixmap cc4;
        cc4.load(":/img/4.png");
        cc4 = cc4.scaled(70,70);
        card4->setPixmap(cc4);
        card4->setPos(283,28);
        scene->addItem(card4);
    }
    if(x==5)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card5 = new Card5();
        QPixmap c5;
        c5.load(":/img/5.png");
        card5->setPixmap(c5);
        card5->setPos(125,150);
        scene->addItem(card5);

        QTime t5;
        t5.start();
        while(t5.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card5);
        scene->removeItem(con);
        card5 = new Card5();
        QPixmap cc5;
        cc5.load(":/img/5.png");
        cc5 = cc5.scaled(70,70);
        card5->setPixmap(cc5);
        card5->setPos(22,120);
        scene->addItem(card5);
    }
    if(x==6)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card6 = new Card6();
        QPixmap c3;
        c3.load(":/img/6.png");
        card6->setPixmap(c3);
        card6->setPos(125,150);
        scene->addItem(card6);
        QTime t3;
        t3.start();
        while(t3.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card6);
        scene->removeItem(con);
        card6 = new Card6();
        QPixmap cc3;
        cc3.load(":/img/6.png");
        cc3 = cc3.scaled(70,70);
        card6->setPixmap(cc3);
        card6->setPos(109,120);
        scene->addItem(card6);
    }
    if(x==7)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card7 = new Card7();
        QPixmap c7;
        c7.load(":/img/7.png");
        card7->setPixmap(c7);
        card7->setPos(125,150);
        scene->addItem(card7);
        QTime t7;
        t7.start();
        while(t7.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card7);
        scene->removeItem(con);
        card7 = new Card7();
        QPixmap cc7;
        cc7.load(":/img/7.png");
        cc7 = cc7.scaled(70,70);
        card7->setPixmap(cc7);
        card7->setPos(196,120);
        scene->addItem(card7);
    }
    if(x==8)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card8 = new Card8();
        QPixmap c8;
        c8.load(":/img/8.png");
        card8->setPixmap(c8);
        card8->setPos(125,150);
        scene->addItem(card8);
        QTime t8;
        t8.start();
        while(t8.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card8);
        scene->removeItem(con);
        card8 = new Card8();
        QPixmap cc8;
        cc8.load(":/img/8.png");
        cc8 = cc8.scaled(70,70);
        card8->setPixmap(cc8);
        card8->setPos(283,120);
        scene->addItem(card8);
    }
    if(x==9)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card9 = new Card9();
        QPixmap c9;
        c9.load(":/img/9.png");
        card9->setPixmap(c9);
        card9->setPos(125,150);
        scene->addItem(card9);
        QTime t9;
        t9.start();
        while(t9.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card9);
        scene->removeItem(con);
        card9 = new Card9();
        QPixmap cc9;
        cc9.load(":/img/9.png");
        cc9 = cc9.scaled(70,70);
        card9->setPixmap(cc9);
        card9->setPos(22,213);
        scene->addItem(card9);
    }
    if(x==10)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card10 = new Card10();
        QPixmap c10;
        c10.load(":/img/10.png");
        card10->setPixmap(c10);
        card10->setPos(125,150);
        scene->addItem(card10);
        QTime t10;
        t10.start();
        while(t10.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card10);
        scene->removeItem(con);
        card10 = new Card10();
        QPixmap cc10;
        cc10.load(":/img/10.png");
        cc10 = cc10.scaled(70,70);
        card10->setPixmap(cc10);
        card10->setPos(109,213);
        scene->addItem(card10);
    }
    if(x==11)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card11 = new Card11();
        QPixmap c;
        c.load(":/img/11.png");
        card11->setPixmap(c);
        card11->setPos(125,150);
        scene->addItem(card11);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card11);
        scene->removeItem(con);
        card11 = new Card11();
        QPixmap cc;
        cc.load(":/img/11.png");
        cc = cc.scaled(70,70);
        card11->setPixmap(cc);
        card11->setPos(196,213);
        scene->addItem(card11);
    }
    if(x==12)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card12 = new Card12();
        QPixmap c;
        c.load(":/img/12.png");
        card12->setPixmap(c);
        card12->setPos(125,150);
        scene->addItem(card12);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card12);
        scene->removeItem(con);
        card12 = new Card12();
        QPixmap cc;
        cc.load(":/img/12.png");
        cc = cc.scaled(70,70);
        card12->setPixmap(cc);
        card12->setPos(283,213);
        scene->addItem(card12);
    }
    if(x==13)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card13 = new Card13();
        QPixmap c;
        c.load(":/img/13.png");
        card13->setPixmap(c);
        card13->setPos(125,150);
        scene->addItem(card13);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card13);
        scene->removeItem(con);
        card13 = new Card13();
        QPixmap cc;
        cc.load(":/img/13.png");
        cc = cc.scaled(70,70);
        card13->setPixmap(cc);
        card13->setPos(22,305);
        scene->addItem(card13);
    }
    if(x==14)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card14 = new Card14();
        QPixmap c;
        c.load(":/img/14.png");
        card14->setPixmap(c);
        card14->setPos(125,150);
        scene->addItem(card14);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card14);
        scene->removeItem(con);
        card14 = new Card14();
        QPixmap cc;
        cc.load(":/img/14.png");
        cc = cc.scaled(70,70);
        card14->setPixmap(cc);
        card14->setPos(109,305);
        scene->addItem(card14);
    }
    if(x==15)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card15 = new Card15();
        QPixmap c;
        c.load(":/img/15.png");
        card15->setPixmap(c);
        card15->setPos(125,150);
        scene->addItem(card15);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card15);
        scene->removeItem(con);
        card15 = new Card15();
        QPixmap cc;
        cc.load(":/img/15.png");
        cc = cc.scaled(70,70);
        card15->setPixmap(cc);
        card15->setPos(196,305);
        scene->addItem(card15);
    }
    if(x==16)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card16 = new Card16();
        QPixmap c;
        c.load(":/img/16.png");
        card16->setPixmap(c);
        card16->setPos(125,150);
        scene->addItem(card16);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card16);
        scene->removeItem(con);
        card16 = new Card16();
        QPixmap cc;
        cc.load(":/img/16.png");
        cc = cc.scaled(70,70);
        card16->setPixmap(cc);
        card16->setPos(283,305);
        scene->addItem(card16);
    }
    if(x==17)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card17 = new Card17();
        QPixmap c;
        c.load(":/img/17.png");
        card17->setPixmap(c);
        card17->setPos(125,150);
        scene->addItem(card17);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card17);
        scene->removeItem(con);
        card17 = new Card17();
        QPixmap cc;
        cc.load(":/img/17.png");
        cc = cc.scaled(70,70);
        card17->setPixmap(cc);
        card17->setPos(22,397);
        scene->addItem(card17);
    }
    if(x==18)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card18 = new Card18();
        QPixmap c;
        c.load(":/img/18.png");
        card18->setPixmap(c);
        card18->setPos(125,150);
        scene->addItem(card18);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card18);
        scene->removeItem(con);
        card18 = new Card18();
        QPixmap cc;
        cc.load(":/img/18.png");
        cc = cc.scaled(70,70);
        card18->setPixmap(cc);
        card18->setPos(109,397);
        scene->addItem(card18);
    }
    if(x==19)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card19 = new Card19();
        QPixmap c;
        c.load(":/img/19.png");
        card19->setPixmap(c);
        card19->setPos(125,150);
        scene->addItem(card19);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card19);
        scene->removeItem(con);
        card19 = new Card19();
        QPixmap cc;
        cc.load(":/img/19.png");
        cc = cc.scaled(70,70);
        card19->setPixmap(cc);
        card19->setPos(196,397);
        scene->addItem(card19);
    }
    if(x==20)
    {
        con = new Card();
        QPixmap cn;
        cn.load(":/img/showcard.png");
        cn = cn.scaled(cn.width()*1/2,cn.height()*1/2,Qt::KeepAspectRatio);
        con->setPixmap(cn);
        con->setPos(70,45);
        scene->addItem(con);
        card20 = new Card20();
        QPixmap c;
        c.load(":/img/20.png");
        card20->setPixmap(c);
        card20->setPos(125,150);
        scene->addItem(card20);
        QTime t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
        scene->removeItem(card20);
        scene->removeItem(con);
        card20 = new Card20();
        QPixmap cc;
        cc.load(":/img/20.png");
        cc = cc.scaled(70,70);
        card20->setPixmap(cc);
        card20->setPos(283,397);
        scene->addItem(card20);
    }
}

void Game::weapon1()
{
    Card1 * c1 = new Card1();
    rand = (qrand()% 350)+1;
    c1->setPos(rand,480);
    scene->addItem(c1);
}
void Game::weapon2()
{
    Card2 * c2 = new Card2();
    rand = (qrand()% 350)+1;
    c2->setPos(rand,480);
    scene->addItem(c2);
}
void Game::weapon3()
{
    Card3 * c3 = new Card3();
    rand = (qrand()% 350)+1;
    c3->setPos(rand,480);
    scene->addItem(c3);
}
void Game::weapon4()
{
    Card4 * c4 = new Card4();
    rand = (qrand()% 350)+1;
    c4->setPos(rand,480);
    scene->addItem(c4);
}
void Game::weapon5()
{
    Card5 * c5 = new Card5();
    c5->setPos(20,200);
    scene->addItem(c5);
    QTime t1;
    t1.start();
    while(t1.elapsed()<2500)
        QCoreApplication::processEvents();
    scene->removeItem(c5);
}
void Game::weapon6()
{
    Card6 * c6 = new Card6();
    rand = (qrand()% 350)+1;
    c6->setPos(rand,480);
    scene->addItem(c6);
}
void Game::weapon7()
{
    Card7 * c7 = new Card7();
    rand = (qrand()% 350)+1;
    c7->setPos(rand,480);
    scene->addItem(c7);
}
void Game::weapon8()
{
    Card8 * c81 = new Card8();
    randx = (qrand()% 340)+1;
    randy = (qrand()% 200)+200;
    c81->setPos(randx+10,randy);
    scene->addItem(c81);
    Card8 * c82 = new Card8();
    randx = (qrand()% 340)+1;
    randy = (qrand()% 200)+200;
    c82->setPos(randx+10,randy);
    scene->addItem(c82);
    Card8 * c83 = new Card8();
    randx = (qrand()% 340)+1;
    randy = (qrand()% 200)+200;
    c83->setPos(randx+10,randy);
    scene->addItem(c83);
    QTime t2;
    t2.start();
    while(t2.elapsed()<2500)
        QCoreApplication::processEvents();
    scene->removeItem(c81);scene->removeItem(c82);scene->removeItem(c83);
}
void Game::weapon9()
{
    Card9 * c9 = new Card9();
    randx = (qrand()% 360)+1;
    randy = (qrand()% 450)+1;
    c9->setPos(randx+10,randy+100);
    scene->addItem(c9);

}
void Game::weapon10()
{
    Card10 * c10 = new Card10();
    rand = (qrand()% 350)+1;
    c10->setPos(rand,0);
    scene->addItem(c10);
}
void Game::weapon11()
{
    Card11 * c11 = new Card11();
    rand = (qrand()% 350)+1;
    c11->setPos(rand,480);
    scene->addItem(c11);
}
void Game::weapon12()
{
    Card12 * c12 = new Card12();
    c12->setPos(50,480);
    scene->addItem(c12);
}
void Game::weapon13()
{
    Card13 * c13 = new Card13();
    rand = (qrand()% 350)+1;
    c13->setPos(rand,480);
    scene->addItem(c13);
}
void Game::weapon14()
{
    Card14 * c14 = new Card14();
    rand = (qrand()% 350)+1;
    c14->setPos(rand,480);
    scene->addItem(c14);
}
void Game::weapon15()
{
    Card15 * c151 = new Card15();
    rand = (qrand()% 340)+1;
    c151->setPos(rand,480);
    scene->addItem(c151);
    Card15 * c152 = new Card15();
    rand = (qrand()% 340)+1;
    c152->setPos(rand,480);
    scene->addItem(c152);
    Card15 * c153 = new Card15();
    rand = (qrand()% 340)+1;
    c153->setPos(rand,480);
    scene->addItem(c153);
}
void Game::weapon16()
{
    Card16 * c16 = new Card16();
    rand = (qrand()% 350)+1;
    c16->setPos(rand,480);
    scene->addItem(c16);
}
void Game::weapon17()
{
    Card17 * c17 = new Card17();
    rand = (qrand()% 350)+1;
    c17->setPos(rand,480);
    scene->addItem(c17);
}
void Game::weapon18()
{
    Card18 * c18 = new Card18();
    rand = (qrand()% 200)+200;
    c18->setPos(0,rand);
    scene->addItem(c18);
}
void Game::weapon19()
{
    Card19 * c19 = new Card19();
    randx = (qrand()% 340)+1;
    randy = (qrand()% 450)+1;
    c19->setPos(randx+10,randy+100);
    scene->addItem(c19);
}
void Game::weapon20()
{
    Card20 * c20 = new Card20();
    rand = (qrand()% 350)+1;
    c20->setPos(rand,480);
    c20->setFlag(QGraphicsItem::ItemIsFocusable);
    c20->setFocus();
    scene->addItem(c20);
}
void Game::mousePressEvent(QMouseEvent *event)
{
    if(screenMode == 0)
        {
            //to start game
            if(event->pos().x() > 128 && event->pos().x() <= 261)
            {
                // Now x is in range , judge y
                if(event->pos().y() > 550 && event->pos().y() <=594 )
                {
                    screenMode = 1;
                    cardmanage();
                }
            }
    }
    if(screenMode == 1)
    {
        if(event->pos().x() > 22 && event->pos().x() <= 92)
        {
            if(event->pos().y() > 28 && event->pos().y() <= 98)
            {
                card1->i++;
                if(card1->i%2==1)
                {
                    card1->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card1->black->setPixmap(ct);
                    card1->black->setPos(22,28);
                    scene->addItem(card1->black);
                }
                else
                    scene->removeItem(card1->black);
            }
        }
        if(event->pos().x() > 109 && event->pos().x() <= 179)
        {
            if(event->pos().y() > 28 && event->pos().y() <= 98)
            {
                card2->i++;
                if(card2->i%2==1)
                {
                    card2->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card2->black->setPixmap(ct);
                    card2->black->setPos(109,28);
                    scene->addItem(card2->black);
                }
                else
                    scene->removeItem(card2->black);
            }
        }
        if(event->pos().x() > 196 && event->pos().x() <= 266)
        {
            if(event->pos().y() > 28 && event->pos().y() <= 98)
            {
                card3->i++;
                if(card3->i%2==1)
                {
                    card3->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card3->black->setPixmap(ct);
                    card3->black->setPos(196,28);
                    scene->addItem(card3->black);
                }
                else
                    scene->removeItem(card3->black);
            }
        }
        if(event->pos().x() > 283 && event->pos().x() <= 353)
        {
            if(event->pos().y() > 28 && event->pos().y() <= 98)
            {
                card4->i++;
                if(card4->i%2==1)
                {
                    card4->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card4->black->setPixmap(ct);
                    card4->black->setPos(283,28);
                    scene->addItem(card4->black);
                }
                else
                    scene->removeItem(card4->black);
            }
        }
        if(event->pos().x() > 22 && event->pos().x() <= 92)
        {
            if(event->pos().y() > 120 && event->pos().y() <= 190)
            {
                card5->i++;
                if(card5->i%2==1)
                {
                    card5->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card5->black->setPixmap(ct);
                    card5->black->setPos(22,120);
                    scene->addItem(card5->black);
                }
                else
                    scene->removeItem(card5->black);
            }
        }
        if(event->pos().x() > 109 && event->pos().x() <= 179)
        {
            if(event->pos().y() > 120 && event->pos().y() <= 190)
            {
                card6->i++;
                if(card6->i%2==1)
                {
                    card6->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card6->black->setPixmap(ct);
                    card6->black->setPos(109,120);
                    scene->addItem(card6->black);
                }
                else
                    scene->removeItem(card6->black);
            }
        }
        if(event->pos().x() > 196 && event->pos().x() <= 266)
        {
            if(event->pos().y() > 120 && event->pos().y() <= 190)
            {
                card7->i++;
                if(card7->i%2==1)
                {
                    card7->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card7->black->setPixmap(ct);
                    card7->black->setPos(196,120);
                    scene->addItem(card7->black);
                }
                else
                    scene->removeItem(card7->black);
            }
        }
        if(event->pos().x() > 283 && event->pos().x() <= 353)
        {
            if(event->pos().y() > 120 && event->pos().y() <= 190)
            {
                card8->i++;
                if(card8->i%2==1)
                {
                    card8->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card8->black->setPixmap(ct);
                    card8->black->setPos(283,120);
                    scene->addItem(card8->black);
                }
                else
                    scene->removeItem(card8->black);
            }
        }
        if(event->pos().x() > 22 && event->pos().x() <= 92)
        {
            if(event->pos().y() > 213 && event->pos().y() <= 283)
            {
                card9->i++;
                if(card9->i%2==1)
                {
                    card9->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card9->black->setPixmap(ct);
                    card9->black->setPos(22,213);
                    scene->addItem(card9->black);
                }
                else
                    scene->removeItem(card9->black);
            }
        }
        if(event->pos().x() > 109 && event->pos().x() <= 179)
        {
            if(event->pos().y() > 213 && event->pos().y() <= 283)
            {
                card10->i++;
                if(card10->i%2==1)
                {
                    card10->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card10->black->setPixmap(ct);
                    card10->black->setPos(109,213);
                    scene->addItem(card10->black);
                }
                else
                    scene->removeItem(card10->black);
            }
        }
        if(event->pos().x() > 196 && event->pos().x() <= 266)
        {
            if(event->pos().y() > 213 && event->pos().y() <= 283)
            {
                card11->i++;
                if(card11->i%2==1)
                {
                    card11->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card11->black->setPixmap(ct);
                    card11->black->setPos(196,213);
                    scene->addItem(card11->black);
                }
                else
                    scene->removeItem(card11->black);
            }
        }
        if(event->pos().x() > 283 && event->pos().x() <= 353)
        {
            if(event->pos().y() > 213 && event->pos().y() <= 283)
            {
                card12->i++;
                if(card12->i%2==1)
                {
                    card12->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card12->black->setPixmap(ct);
                    card12->black->setPos(283,213);
                    scene->addItem(card12->black);
                }
                else
                    scene->removeItem(card12->black);
            }
        }
        if(event->pos().x() > 22 && event->pos().x() <= 92)
        {
            if(event->pos().y() > 305 && event->pos().y() <= 375)
            {
                card13->i++;
                if(card13->i%2==1)
                {
                    card13->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card13->black->setPixmap(ct);
                    card13->black->setPos(22,305);
                    scene->addItem(card13->black);
                }
                else
                    scene->removeItem(card13->black);
            }
        }
        if(event->pos().x() > 109 && event->pos().x() <= 179)
        {
            if(event->pos().y() > 305 && event->pos().y() <= 375)
            {
                card14->i++;
                if(card14->i%2==1)
                {
                    card14->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card14->black->setPixmap(ct);
                    card14->black->setPos(109,305);
                    scene->addItem(card14->black);
                }
                else
                    scene->removeItem(card14->black);
            }
        }
        if(event->pos().x() > 196 && event->pos().x() <= 266)
        {
            if(event->pos().y() > 305 && event->pos().y() <= 375)
            {
                card15->i++;
                if(card15->i%2==1)
                {
                    card15->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card15->black->setPixmap(ct);
                    card15->black->setPos(196,305);
                    scene->addItem(card15->black);
                }
                else
                    scene->removeItem(card15->black);
            }
        }
        if(event->pos().x() > 283 && event->pos().x() <= 353)
        {
            if(event->pos().y() > 305 && event->pos().y() <= 375)
            {
                card16->i++;
                if(card16->i%2==1)
                {
                    card16->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card16->black->setPixmap(ct);
                    card16->black->setPos(283,305);
                    scene->addItem(card16->black);
                }
                else
                    scene->removeItem(card16->black);
            }
        }
        if(event->pos().x() > 22 && event->pos().x() <= 92)
        {
            if(event->pos().y() > 397 && event->pos().y() <= 467)
            {
                card17->i++;
                if(card17->i%2==1)
                {
                    card17->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card17->black->setPixmap(ct);
                    card17->black->setPos(22,397);
                    scene->addItem(card17->black);
                }
                else
                    scene->removeItem(card17->black);
            }
        }
        if(event->pos().x() > 109 && event->pos().x() <= 179)
        {
            if(event->pos().y() > 397 && event->pos().y() <= 467)
            {
                card18->i++;
                if(card18->i%2==1)
                {
                    card18->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card18->black->setPixmap(ct);
                    card18->black->setPos(109,397);
                    scene->addItem(card18->black);
                }
                else
                    scene->removeItem(card18->black);
            }
        }
        if(event->pos().x() > 196 && event->pos().x() <= 266)
        {
            if(event->pos().y() > 397 && event->pos().y() <= 467)
            {
                card19->i++;
                if(card19->i%2==1)
                {
                    card19->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card19->black->setPixmap(ct);
                    card19->black->setPos(196,397);
                    scene->addItem(card19->black);
                }
                else
                    scene->removeItem(card19->black);
            }
        }
        if(event->pos().x() > 283 && event->pos().x() <= 353)
        {
            if(event->pos().y() > 397 && event->pos().y() <= 467)
            {
                card20->i++;
                if(card20->i%2==1)
                {
                    card20->black = new Card();
                    QPixmap ct;
                    ct.load(":/img/black.png");
                    ct = ct.scaled(70,70);
                    card20->black->setPixmap(ct);
                    card20->black->setPos(283,397);
                    scene->addItem(card20->black);
                }
                else
                    scene->removeItem(card20->black);
            }
        }
        i[0]=card1->i;i[1]=card2->i;i[2]=card3->i;i[3]=card4->i;i[4]=card5->i;
        i[5]=card6->i;i[6]=card7->i;i[7]=card8->i;i[8]=card9->i;i[9]=card10->i;
        i[10]=card11->i;i[11]=card12->i;i[12]=card13->i;i[13]=card14->i;i[14]=card15->i;
        i[15]=card16->i;i[16]=card17->i;i[17]=card18->i;i[18]=card19->i;i[19]=card20->i;
    }
    if(screenMode == 2)
    {
        if(event->pos().x() > 100 && event->pos().x() <= 200)
                {
                    if(event->pos().y() > 400 && event->pos().y() <= 600)
                    {
                        fireball = new Fireball();
                        QPixmap f;
                        f.load(":/img/csiecsie.png");
                        fireball->setPixmap(f);
                        fireball->setPos(170,480);
                        scene->addItem(fireball);
                    }
                }
    }
}

int Game::getscreen()
{
    return screenMode;
}

void Game::Gameover()
{
    int ncku = hpi->hpI;
    int ee = hpy->hpY;
    int time = tt->time;
    QString mm;
    if(time<=0)
    {
        screenMode = 3;
        timer1->stop();
        timer2->stop();
        if(ncku>ee)
        {
            mm = "WIN!" ;
            change();
            Displaygameoverwindow(mm,ncku);
            qbutton = new QPushButton(this);
            qbutton->setGeometry(135,600,116,25);
            qbutton->setIcon(QIcon(":/img/back.png"));
            qbutton->setIconSize(QSize(116,45));
            connect(qbutton,SIGNAL(clicked()),this,SLOT(closebutton()));
            qbutton->show();
        }
        else if(ncku<ee)
        {
            mm = "LOSE!" ;
            change();
            Displaygameoverwindow(mm,-ee);
            qbutton = new QPushButton(this);
            qbutton->setGeometry(135,600,116,25);
            qbutton->setIcon(QIcon(":/img/back.png"));
            qbutton->setIconSize(QSize(116,45));
            connect(qbutton,SIGNAL(clicked()),this,SLOT(closebutton()));
            qbutton->show();
        }
        else if(ncku==ee)
        {
            mm = "TIE!" ;
            change();
            Displaygameoverwindow(mm,2);
            qbutton = new QPushButton(this);
            qbutton->setGeometry(135,600,116,25);
            qbutton->setIcon(QIcon(":/img/back.png"));
            qbutton->setIconSize(QSize(116,45));
            connect(qbutton,SIGNAL(clicked()),this,SLOT(closebutton()));
            qbutton->show();
        }
    }
    else if(time>0)
    {
        if(ncku <= 0 && ee <= 0)
        {
            timer1->stop();
            timer2->stop();
            screenMode = 3;
            mm = "TIE!";
            change();
            Displaygameoverwindow(mm,2);
            qbutton = new QPushButton(this);
            qbutton->setGeometry(135,600,116,25);
            qbutton->setIcon(QIcon(":/img/back.png"));
            qbutton->setIconSize(QSize(116,45));
            connect(qbutton,SIGNAL(clicked()),this,SLOT(closebutton()));
            qbutton->show();
        }
        else if(ncku <= 0 && ee >0)
        {
            timer1->stop();
            timer2->stop();
            screenMode = 3;
            mm = "LOSE!";
            change();
            Displaygameoverwindow(mm,-ee);
            qbutton = new QPushButton(this);
            qbutton->setGeometry(135,600,116,25);
            qbutton->setIcon(QIcon(":/img/back.png"));
            qbutton->setIconSize(QSize(116,45));
            connect(qbutton,SIGNAL(clicked()),this,SLOT(closebutton()));
            qbutton->show();
        }
        else if(ncku > 0 && ee <= 0)
        {
            timer1->stop();
            timer2->stop();
            screenMode = 3;
            mm = "WIN!" ;
            change();
            Displaygameoverwindow(mm,ncku);
            qbutton = new QPushButton(this);
            qbutton->setGeometry(135,600,116,25);
            qbutton->setIcon(QIcon(":/img/back.png"));
            qbutton->setIconSize(QSize(116,45));
            connect(qbutton,SIGNAL(clicked()),this,SLOT(closebutton()));
            qbutton->show();
        }
    }
}

void Game::change()
{
    if(i[0]%2==1)
        button1->close();
    if(i[1]%2==1)
        button2->close();
    if(i[2]%2==1)
        button3->close();
    if(i[3]%2==1)
        button4->close();
    if(i[4]%2==1)
        button5->close();
    if(i[5]%2==1)
        button6->close();
    if(i[6]%2==1)
        button7->close();
    if(i[7]%2==1)
        button8->close();
    if(i[8]%2==1)
        button9->close();
    if(i[9]%2==1)
        button10->close();
    if(i[10]%2==1)
        button11->close();
    if(i[11]%2==1)
        button12->close();
    if(i[12]%2==1)
        button13->close();
    if(i[13]%2==1)
        button14->close();
    if(i[14]%2==1)
        button15->close();
    if(i[15]%2==1)
        button16->close();
    if(i[16]%2==1)
        button17->close();
    if(i[17]%2==1)
        button18->close();
    if(i[18]%2==1)
        button19->close();
    if(i[19]%2==1)
        button20->close();
}

void Game::closebutton()
{
    qbutton->close();
    cardmanage();
}

void Game::Displaygameoverwindow(QString texttodisplay, int k)
{
    recordboard = new Card();
    QPixmap rd;
    rd.load(":/img/bg3.png");
    rd = rd.scaled(375,667);
    recordboard->setPixmap(rd);
    recordboard->setPos(0,0);
    scene->addItem(recordboard);
    //put each score into array
        numberofresult++;
        a[numberofresult]=k;
        //rank the score
        for(int s=1;s<19;s++)
        {
            for(int j=s+1;j<20;j++)
            {
                if(a[j]>a[s])
                {
                    int y=a[j];
                    a[j]=a[s];
                    a[s]=y;
                }
            }
        }
        //your rank ; whether the score in the rank
           for(int b = 1;b < 20;b++)
           {
               if(a[b]==k)
               {
                   if(b>8)
                   {
                       QGraphicsTextItem* Nranktext = new QGraphicsTextItem("Not in rank!");
                       Nranktext->setPos(92,205);
                       Nranktext->setFont(QFont("freemono",17));
                       scene->addItem(Nranktext);
                       break;
                   }
                   if(b<9)
                   {
                       QString rankmes = QString::number(b);
                       rankmes.prepend(QString("You are rank "));
                       QGraphicsTextItem* Nranktext = new QGraphicsTextItem(rankmes);
                       Nranktext->setPos(92,205);
                       Nranktext->setFont(QFont("freemono",17));
                       scene->addItem(Nranktext);
                       break;
                   }
               }
           }
           //invert int to QString
              if(a[1]!=-500) scoretodisplay1 = QString::number(a[1]);
              if(a[2]!=-500) scoretodisplay2 = QString::number(a[2]);
              if(a[3]!=-500) scoretodisplay3 = QString::number(a[3]);
              if(a[4]!=-500) scoretodisplay4 = QString::number(a[4]);
              if(a[5]!=-500) scoretodisplay5 = QString::number(a[5]);
              if(a[6]!=-500) scoretodisplay6 = QString::number(a[6]);
              if(a[7]!=-500) scoretodisplay7 = QString::number(a[7]);
              if(a[8]!=-500) scoretodisplay8 = QString::number(a[8]);
              //show score
              QGraphicsTextItem* scorText1 = new QGraphicsTextItem(scoretodisplay1);
              scorText1->setPos(165,280);
              if(a[1]==k) scorText1->setFont(QFont("string",16, QFont::Bold));
              else scorText1->setFont(QFont("string",16));
              scene->addItem(scorText1);
              QGraphicsTextItem* scorText2 = new QGraphicsTextItem(scoretodisplay2);
              scorText2->setPos(165,313);
              if(a[2]==k) scorText2->setFont(QFont("string",16, QFont::Bold));
              else scorText2->setFont(QFont("string",16));
              scene->addItem(scorText2);
              QGraphicsTextItem* scorText3 = new QGraphicsTextItem(scoretodisplay3);
              scorText3->setPos(165,347);
              if(a[3]==k) scorText3->setFont(QFont("string",16, QFont::Bold));
              else scorText3->setFont(QFont("string",16));
              scene->addItem(scorText3);
              QGraphicsTextItem* scorText4 = new QGraphicsTextItem(scoretodisplay4);
              scorText4->setPos(165,380);
              if(a[4]==k) scorText4->setFont(QFont("string",16, QFont::Bold));
              else scorText4->setFont(QFont("string",16));
              scene->addItem(scorText4);
              QGraphicsTextItem* scorText5 = new QGraphicsTextItem(scoretodisplay5);
              scorText5->setPos(165,413);
              if(a[5]==k) scorText5->setFont(QFont("string",16, QFont::Bold));
              else scorText5->setFont(QFont("string",16));
              scene->addItem(scorText5);
              QGraphicsTextItem* scorText6 = new QGraphicsTextItem(scoretodisplay6);
              scorText6->setPos(165,446);
              if(a[6]==k) scorText6->setFont(QFont("string",16, QFont::Bold));
              else scorText6->setFont(QFont("string",16));
              scene->addItem(scorText6);
              QGraphicsTextItem* scorText7 = new QGraphicsTextItem(scoretodisplay7);
              scorText7->setPos(165,479);
              if(a[7]==k) scorText7->setFont(QFont("string",16, QFont::Bold));
              else scorText7->setFont(QFont("string",16));
              scene->addItem(scorText7);
              QGraphicsTextItem* scorText8 = new QGraphicsTextItem(scoretodisplay8);
              scorText8->setPos(165,513);
              if(a[8]==k) scorText8->setFont(QFont("string",16, QFont::Bold));
              else scorText8->setFont(QFont("string",16));
              scene->addItem(scorText8);
              //show win lose tie
                 QGraphicsTextItem* overText = new QGraphicsTextItem(texttodisplay);
                 overText->setPos(138,136);
                 overText->setFont(QFont("purisa",25,QFont::Bold));
                 scene->addItem(overText);

                 for (size_t i = 0, n = scene->items().size(); i < n; i++){
                         scene->items()[i]->setEnabled(false);
                     }

                     // pop up record board

}

void Game::enemyShot()
{
    if(screenMode==2)
       {
           int x;
           x = (qrand()% 4)+1;
           switch (x)
           {
               case 1:
               {
                   enemy1 = new Enemy();
                   QPixmap e1;
                   e1.load(":/img/enemy1.png");
                   e1 = e1.scaled(e1.width()*1/3,e1.height()*1/3,Qt::KeepAspectRatio);
                   enemy1->setPixmap(e1);
                   rand = (qrand()% 350)+1;
                   enemy1->setPos(rand,50);
                   scene->addItem(enemy1);
                   break;
               }
               case 2:
               {
                   enemy2 = new Enemy();
                   QPixmap e2;
                   e2.load(":/img/enemy2.png");
                   e2 = e2.scaled(e2.width()*1/3,e2.height()*1/3,Qt::KeepAspectRatio);
                   enemy2->setPixmap(e2);
                   rand = (qrand()% 350)+1;
                   enemy2->setPos(rand,50);
                   scene->addItem(enemy2);
                   break;
               }
               case 3:
               {
                   enemy3 = new Enemy();
                   QPixmap e3;
                   e3.load(":/img/enemy3.png");
                   e3 = e3.scaled(e3.width()*1/3,e3.height()*1/3,Qt::KeepAspectRatio);
                   enemy3->setPixmap(e3);
                   rand = (qrand()% 350)+1;
                   enemy3->setPos(rand,50);
                   scene->addItem(enemy3);
                   break;
               }
               case 4:
               {
                   enemy4 = new Enemy();
                   QPixmap e4;
                   e4.load(":/img/enemy4.png");
                   e4 = e4.scaled(e4.width()*1/3,e4.height()*1/3,Qt::KeepAspectRatio);
                   enemy4->setPixmap(e4);
                   rand = (qrand()% 350)+1;
                   enemy4->setPos(rand,50);
                   scene->addItem(enemy4);
                   break;
               }
           }
       }
}
