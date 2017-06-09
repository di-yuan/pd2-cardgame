#include "game.h"
#include <iostream>

Game::Game(QWidget *parent)
{
    //scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,375,667);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screenMode = 0;
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
    start->setPos(135,550);
    scene->addItem(start);
}

void Game::bgChange()
{
    QImage bg;
    bg.load(":/img/bg1.png");
    bg = bg.scaled(375,667);
    this->setBackgroundBrush(bg);
    scene->removeItem(start);
}

void Game::cardmanage()
{
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

    draw = new Card();
    QPixmap dr;
    dr.load(":/img/drawcard.png");
    dr = dr.scaled(70,70);
    draw->setPixmap(dr);
    draw->setPos(50,500);
    scene->addItem(draw);

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
    cbutton->show();
}

void Game::gameInit()
{
    screenMode = 2;
    sbutton->close();
    cbutton->close();
    scene->clear();
    QImage bg;
    bg.load(":/img/bg2.png");
    bg = bg.scaled(375,667); // you can also change here
    this->setBackgroundBrush(bg);
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
            button1->setGeometry(213,569,70,70);
        button1->show();
    }
    if(i[1]%2==1)
    {
        n++;
        button2 = new QPushButton(this);
        button2->setIcon(QIcon(":/img/2.png"));
        button2->setIconSize(QSize(70,70));
        connect(button2,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button2->setGeometry(22,569,70,70);
        if(n==2)
            button2->setGeometry(109,569,70,70);
        if(n==3)
            button2->setGeometry(196,569,70,70);
        if(n==4)
            button2->setGeometry(213,569,70,70);
        button2->show();
    }
    if(i[2]%2==1)
    {
        n++;
        button3 = new QPushButton(this);
        button3->setIcon(QIcon(":/img/3.png"));
        button3->setIconSize(QSize(70,70));
        connect(button3,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button3->setGeometry(22,569,70,70);
        if(n==2)
            button3->setGeometry(109,569,70,70);
        if(n==3)
            button3->setGeometry(196,569,70,70);
        if(n==4)
            button3->setGeometry(213,569,70,70);
        button3->show();
    }
    if(i[3]%2==1)
    {
        n++;
        button4 = new QPushButton(this);
        button4->setIcon(QIcon(":/img/4.png"));
        button4->setIconSize(QSize(70,70));
        connect(button4,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button4->setGeometry(22,569,70,70);
        if(n==2)
            button4->setGeometry(109,569,70,70);
        if(n==3)
            button4->setGeometry(196,569,70,70);
        if(n==4)
            button4->setGeometry(213,569,70,70);
        button4->show();
    }
    if(i[4]%2==1)
    {
        n++;
        button1 = new QPushButton(this);
        button1->setIcon(QIcon(":/img/5.png"));
        button1->setIconSize(QSize(70,70));
        connect(button1,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button1->setGeometry(22,569,70,70);
        if(n==2)
            button1->setGeometry(109,569,70,70);
        if(n==3)
            button1->setGeometry(196,569,70,70);
        if(n==4)
            button1->setGeometry(213,569,70,70);
        button1->show();
    }
    if(i[5]%2==1)
    {
        n++;
        button6 = new QPushButton(this);
        button6->setIcon(QIcon(":/img/6.png"));
        button6->setIconSize(QSize(70,70));
        connect(button6,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button6->setGeometry(22,569,70,70);
        if(n==2)
            button6->setGeometry(109,569,70,70);
        if(n==3)
            button6->setGeometry(196,569,70,70);
        if(n==4)
            button6->setGeometry(213,569,70,70);
        button1->show();
    }
    if(i[6]%2==1)
    {
        n++;
        button7 = new QPushButton(this);
        button7->setIcon(QIcon(":/img/7.png"));
        button7->setIconSize(QSize(70,70));
        connect(button7,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button7->setGeometry(22,569,70,70);
        if(n==2)
            button7->setGeometry(109,569,70,70);
        if(n==3)
            button7->setGeometry(196,569,70,70);
        if(n==4)
            button7->setGeometry(213,569,70,70);
        button7->show();
    }
    if(i[7]%2==1)
    {
        n++;
        button8 = new QPushButton(this);
        button8->setIcon(QIcon(":/img/8.png"));
        button8->setIconSize(QSize(70,70));
        connect(button8,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button8->setGeometry(22,569,70,70);
        if(n==2)
            button8->setGeometry(109,569,70,70);
        if(n==3)
            button8->setGeometry(196,569,70,70);
        if(n==4)
            button8->setGeometry(213,569,70,70);
        button8->show();
    }
    if(i[8]%2==1)
    {
        n++;
        button9 = new QPushButton(this);
        button9->setIcon(QIcon(":/img/9.png"));
        button9->setIconSize(QSize(70,70));
        connect(button9,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button9->setGeometry(22,569,70,70);
        if(n==2)
            button9->setGeometry(109,569,70,70);
        if(n==3)
            button9->setGeometry(196,569,70,70);
        if(n==4)
            button9->setGeometry(213,569,70,70);
        button9->show();
    }
    if(i[9]%2==1)
    {
        n++;
        button10 = new QPushButton(this);
        button10->setIcon(QIcon(":/img/10.png"));
        button10->setIconSize(QSize(70,70));
        connect(button10,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button10->setGeometry(22,569,70,70);
        if(n==2)
            button10->setGeometry(109,569,70,70);
        if(n==3)
            button10->setGeometry(196,569,70,70);
        if(n==4)
            button10->setGeometry(213,569,70,70);
        button10->show();
    }
    if(i[10]%2==1)
    {
        n++;
        button11 = new QPushButton(this);
        button11->setIcon(QIcon(":/img/11.png"));
        button11->setIconSize(QSize(70,70));
        connect(button11,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button11->setGeometry(22,569,70,70);
        if(n==2)
            button11->setGeometry(109,569,70,70);
        if(n==3)
            button11->setGeometry(196,569,70,70);
        if(n==4)
            button11->setGeometry(213,569,70,70);
        button11->show();
    }
    if(i[11]%2==1)
    {
        n++;
        button12 = new QPushButton(this);
        button12->setIcon(QIcon(":/img/12.png"));
        button12->setIconSize(QSize(70,70));
        connect(button12,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button12->setGeometry(22,569,70,70);
        if(n==2)
            button12->setGeometry(109,569,70,70);
        if(n==3)
            button12->setGeometry(196,569,70,70);
        if(n==4)
            button12->setGeometry(213,569,70,70);
        button12->show();
    }
    if(i[12]%2==1)
    {
        n++;
        button13 = new QPushButton(this);
        button13->setIcon(QIcon(":/img/13.png"));
        button13->setIconSize(QSize(70,70));
        connect(button13,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button13->setGeometry(22,569,70,70);
        if(n==2)
            button13->setGeometry(109,569,70,70);
        if(n==3)
            button13->setGeometry(196,569,70,70);
        if(n==4)
            button13->setGeometry(213,569,70,70);
        button13->show();
    }
    if(i[13]%2==1)
    {
        n++;
        button14 = new QPushButton(this);
        button14->setIcon(QIcon(":/img/14.png"));
        button14->setIconSize(QSize(70,70));
        connect(button14,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button14->setGeometry(22,569,70,70);
        if(n==2)
            button14->setGeometry(109,569,70,70);
        if(n==3)
            button14->setGeometry(196,569,70,70);
        if(n==4)
            button14->setGeometry(213,569,70,70);
        button14->show();
    }
    if(i[14]%2==1)
    {
        n++;
        button15 = new QPushButton(this);
        button15->setIcon(QIcon(":/img/15.png"));
        button15->setIconSize(QSize(70,70));
        connect(button15,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button15->setGeometry(22,569,70,70);
        if(n==2)
            button15->setGeometry(109,569,70,70);
        if(n==3)
            button15->setGeometry(196,569,70,70);
        if(n==4)
            button15->setGeometry(213,569,70,70);
        button15->show();
    }
    if(i[15]%2==1)
    {
        n++;
        button16 = new QPushButton(this);
        button16->setIcon(QIcon(":/img/16.png"));
        button16->setIconSize(QSize(70,70));
        connect(button16,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button16->setGeometry(22,569,70,70);
        if(n==2)
            button16->setGeometry(109,569,70,70);
        if(n==3)
            button16->setGeometry(196,569,70,70);
        if(n==4)
            button16->setGeometry(213,569,70,70);
        button16->show();
    }
    if(i[16]%2==1)
    {
        n++;
        button17 = new QPushButton(this);
        button17->setIcon(QIcon(":/img/17.png"));
        button17->setIconSize(QSize(70,70));
        connect(button17,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button17->setGeometry(22,569,70,70);
        if(n==2)
            button17->setGeometry(109,569,70,70);
        if(n==3)
            button17->setGeometry(196,569,70,70);
        if(n==4)
            button17->setGeometry(213,569,70,70);
        button17->show();
    }
    if(i[17]%2==1)
    {
        n++;
        button18 = new QPushButton(this);
        button18->setIcon(QIcon(":/img/18.png"));
        button18->setIconSize(QSize(70,70));
        connect(button18,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button18->setGeometry(22,569,70,70);
        if(n==2)
            button18->setGeometry(109,569,70,70);
        if(n==3)
            button18->setGeometry(196,569,70,70);
        if(n==4)
            button18->setGeometry(213,569,70,70);
        button18->show();
    }
    if(i[18]%2==1)
    {
        n++;
        button19 = new QPushButton(this);
        button19->setIcon(QIcon(":/img/19.png"));
        button19->setIconSize(QSize(70,70));
        connect(button19,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button19->setGeometry(22,569,70,70);
        if(n==2)
            button19->setGeometry(109,569,70,70);
        if(n==3)
            button19->setGeometry(196,569,70,70);
        if(n==4)
            button19->setGeometry(213,569,70,70);
        button19->show();
    }
    if(i[19]%2==1)
    {
        n++;
        button20 = new QPushButton(this);
        button20->setIcon(QIcon(":/img/20.png"));
        button20->setIconSize(QSize(70,70));
        connect(button20,SIGNAL(clicked()),this,SLOT(weapon1()));
        if(n==1)
            button20->setGeometry(22,569,70,70);
        if(n==2)
            button20->setGeometry(109,569,70,70);
        if(n==3)
            button20->setGeometry(196,569,70,70);
        if(n==4)
            button20->setGeometry(213,569,70,70);
        button20->show();
    }
}

void Game::weapon1()
{
    Card1 * c1 = new Card1();
    c1->setPos(20,220);
    scene->addItem(c1);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if(screenMode == 0)
        {
            //to start game
            if(event->pos().x() > 135 && event->pos().x() <= 268)
            {
                // Now x is in range , judge y
                if(event->pos().y() > 550 && event->pos().y() <=594 )
                {
                    screenMode = 1;
                    bgChange();
                    cardmanage();
                    /*gameInit();
                    giveCard_1();
                    giveCard_2();*/
                    //enemy start action
                    timer1 = new QTimer();
                    //connect(timer1,SIGNAL(timeout()),this,SLOT(enemyCard()));
                    timer1->start(2000);
                    //detect if collision, killed the arena, show result
                    /*timer2 = new QTimer();
                    connect(timer2,SIGNAL(timeout()),this,SLOT(collision()));
                    connect(timer2,SIGNAL(timeout()),this,SLOT(over()));
                    connect(timer2,SIGNAL(timeout()),this,SLOT(kill()));
                    timer2->start(10);*/
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
        i[0]=card1->i;i[1]=card2->i;i[2]=card3->i;i[3]=card4->i;i[4]=card5->i;
        i[5]=card6->i;i[6]=card7->i;i[7]=card8->i;i[8]=card9->i;i[9]=card10->i;
        i[10]=card11->i;i[11]=card12->i;i[12]=card13->i;i[13]=card14->i;i[14]=card15->i;
        i[15]=card16->i;i[16]=card17->i;i[17]=card18->i;i[18]=card19->i;i[19]=card20->i;
    }
}

int Game::getscreen()
{
    return screenMode;
}
