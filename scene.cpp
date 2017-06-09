#include "scene.h"
#include "card1.h"
#include <QGraphicsItem>

Scene::Scene(QObject *parent)
{
    screenMode = 0;
}

void Scene::Init()
{
    // start
    game_start = new Game();
    QPixmap start;
    start.load(":/img/start.png");
    game_w = (start.width()*3)/2 - 60;
    game_h = (start.height()*3)/2 - 30;
    game_start->setPixmap(start);
    game_start->setPos(135,500);
    addItem(game_start);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(screenMode == 0)
    {
        //to start game
        if(event->scenePos().x() > game_start->pos().x() && event->scenePos().x() <= game_start->pos().x()+game_w)
        {
            // Now x is in range , judge y
            if(event->scenePos().y() > game_start->pos().y() && event->scenePos().y() <= game_start->pos().y()+game_h)
            {
                // x , y both in button area
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
    //Game Start

}

int Scene::getscreen()
{
 return screenMode;
}


void Scene::bgChange()
{
    QImage bg;
    bg.load(":/img/cover.png");
    bg = bg.scaled(375,667);
    this->setBackgroundBrush(bg);
    this->removeItem(game_start);

}


void Scene::gameInit()
{
    /*// Setting the Arena
    sun = new Arena();
    QPixmap s;
    s.load(":/img/sun.png");
    sun_w = s.width() ;
    sun_h = s.height() ;
    sun->setPixmap(s);
    sun->setPos(140,475);
    this->addItem(sun);

    earth = new Arena();
    QPixmap e;
    e.load(":/img/earth.png");
    earth->setPixmap(e);
    earth->setPos(20,475);
    this->addItem(earth);

    vinus = new Arena();
    QPixmap v;
    v.load(":/img/vinus.png");
    vinus->setPixmap(v);
    vinus->setPos(260,475);
    this->addItem(vinus);

    // Setting Enemy's Arena
    QTransform transform;
    QTransform trans = transform.rotate(180);
    sune = new Enemy();
    QPixmap *se = new QPixmap(":/img/sun.png");
    QPixmap *set = new QPixmap(se->transformed(trans));
    sune->setPixmap(*set);
    sune->setPos(140,5);
    this->addItem(sune);

    earthe = new Enemy();
    QPixmap *ee = new QPixmap(":/img/earth.png");
    QPixmap *eet = new QPixmap(ee->transformed(trans));
    earthe->setPixmap(*eet);
    earthe->setPos(20,5);
    this->addItem(earthe);

    vinuse = new Enemy();
    QPixmap *ve = new QPixmap(":/img/vinus.png");
    QPixmap *vet = new QPixmap(ve->transformed(trans));
    vinuse->setPixmap(*vet);
    vinuse->setPos(260,5);
    this->addItem(vinuse);

    health = new Health();
    QPixmap he;
    he.load(":/img/time.png");
    health->setPixmap(he);
    health->setPos(0,585);
    this->addItem(health);

    eh1 = new EnemyHealth();
    eh1->setPos(43,27);
    this->addItem(eh1);
    eh2 = new EnemyHealth();
    eh2->setPos(160,27);
    this->addItem(eh2);
    eh3 = new EnemyHealth();
    eh3->setPos(280,27);
    this->addItem(eh3);

    mh1 = new MyHealth();
    mh1->setPos(43,500);
    this->addItem(mh1);
    mh2 = new MyHealth();
    mh2->setPos(160,500);
    this->addItem(mh2);
    mh3 = new MyHealth();
    mh3->setPos(280,500);
    this->addItem(mh3);
*/
    tt = new ShowTime();
    tt->setPos(70,590);
    this->addItem(tt);
}

void Scene::cardmanage()
{
    //if(screenMode == 1)
        card1 = new Card1();
        QPixmap c1;
        c1.load(":/img/1.png");
        c1 = c1.scaled(70,70);
        card1->setPixmap(c1);
        card1->setPos(22,28);
        card1->setFlag(QGraphicsItem::ItemIsFocusable);
        card1->setFocus();
        this->addItem(card1);
        card2 = new Card2();
        QPixmap c2;
        c2.load(":/img/2.png");
        c2 = c2.scaled(70,70);
        card2->setPixmap(c2);
        card2->setPos(109,28);
        this->addItem(card2);
        card3 = new Card3();
        QPixmap c3;
        c3.load(":/img/3.png");
        c3 = c3.scaled(70,70);
        card3->setPixmap(c3);
        card3->setPos(196,28);
        this->addItem(card3);
        card4 = new Card4();
        QPixmap c4;
        c4.load(":/img/4.png");
        c4 = c4.scaled(70,70);
        card4->setPixmap(c4);
        card4->setPos(283,28);
        this->addItem(card4);
        card5 = new Card5();
        QPixmap c5;
        c5.load(":/img/5.png");
        c5 = c5.scaled(70,70);
        card5->setPixmap(c5);
        card5->setPos(22,120);
        this->addItem(card5);
        card6 = new Card6();
        QPixmap c6;
        c6.load(":/img/6.png");
        c6 = c6.scaled(70,70);
        card6->setPixmap(c6);
        card6->setPos(109,120);
        this->addItem(card6);
        card7 = new Card7();
        QPixmap c7;
        c7.load(":/img/7.png");
        c7 = c7.scaled(70,70);
        card7->setPixmap(c7);
        card7->setPos(196,120);
        this->addItem(card7);
        card8 = new Card8();
        QPixmap c8;
        c8.load(":/img/8.png");
        c8 = c8.scaled(70,70);
        card8->setPixmap(c8);
        card8->setPos(283,120);
        this->addItem(card8);
        card9 = new Card9();
        QPixmap c9;
        c9.load(":/img/9.png");
        c9 = c9.scaled(70,70);
        card9->setPixmap(c9);
        card9->setPos(22,213);
        this->addItem(card9);
        card10 = new Card10();
        QPixmap c10;
        c10.load(":/img/10.png");
        c10 = c10.scaled(70,70);
        card10->setPixmap(c10);
        card10->setPos(109,213);
        this->addItem(card10);
        card11 = new Card11();
        QPixmap c11;
        c11.load(":/img/11.png");
        c11 = c11.scaled(70,70);
        card11->setPixmap(c11);
        card11->setPos(196,213);
        this->addItem(card11);
        card12 = new Card12();
        QPixmap c12;
        c12.load(":/img/12.png");
        c12 = c12.scaled(70,70);
        card12->setPixmap(c12);
        card12->setPos(283,213);
        this->addItem(card12);
        card13 = new Card13();
        QPixmap c13;
        c13.load(":/img/13.png");
        c13 = c13.scaled(70,70);
        card13->setPixmap(c13);
        card13->setPos(22,305);
        this->addItem(card13);
        card14 = new Card14();
        QPixmap c14;
        c14.load(":/img/14.png");
        c14 = c14.scaled(70,70);
        card14->setPixmap(c14);
        card14->setPos(109,305);
        this->addItem(card14);
        card15 = new Card15();
        QPixmap c15;
        c15.load(":/img/15.png");
        c15 = c15.scaled(70,70);
        card15->setPixmap(c15);
        card15->setPos(196,305);
        this->addItem(card15);
        card16 = new Card16();
        QPixmap c16;
        c16.load(":/img/16.png");
        c16 = c16.scaled(70,70);
        card16->setPixmap(c16);
        card16->setPos(283,305);
        this->addItem(card16);
        card17 = new Card17();
        QPixmap c17;
        c17.load(":/img/17.png");
        c17 = c17.scaled(70,70);
        card17->setPixmap(c17);
        card17->setPos(22,397);
        this->addItem(card17);
        card18 = new Card18();
        QPixmap c18;
        c18.load(":/img/18.png");
        c18 = c18.scaled(70,70);
        card18->setPixmap(c18);
        card18->setPos(109,397);
        this->addItem(card18);
        card19 = new Card19();
        QPixmap c19;
        c19.load(":/img/19.png");
        c19 = c19.scaled(70,70);
        card19->setPixmap(c19);
        card19->setPos(196,397);
        this->addItem(card19);
        card20 = new Card20();
        QPixmap c20;
        c20.load(":/img/20.png");
        c20 = c20.scaled(70,70);
        card20->setPixmap(c20);
        card20->setPos(283,397);
        this->addItem(card20);

}

void Scene::giveCard_1()
{
    card_1 = new Card();
    card_1->setPos(130,500);
    ran_card_1 = (qrand()%4)+1;

    card_11 = new Card();
    QPixmap a;
    a.load(":/img/1.png");
    a = a.scaled(70,70);
    card_w = a.width();
    card_h = a.height();
    card_11->setPixmap(a);

    card_12 = new Card();
    QPixmap b;
    b.load(":/img/2.png");
    b = b.scaled(70,70);
    card_12->setPixmap(b);

    card_13 = new Card();
    QPixmap c;
    c.load(":/img/3.png");
    c = c.scaled(70,70);
    card_13->setPixmap(c);

    card_14 = new Card();
    QPixmap d;
    d.load(":/img/4.png");
    d = d.scaled(70,70);
    card_14->setPixmap(d);

    switch (ran_card_1)
    {
        case 1:
            card_11->setPos(130,500);
            this->addItem(card_11);
            break;
        case 2:
            card_12->setPos(130,500);
            this->addItem(card_12);
            break;
        case 3:
            card_13->setPos(130,500);
            this->addItem(card_13);
            break;
        case 4:
            card_14->setPos(130,500);
            this->addItem(card_14);
            break;
    }
}

void Scene::giveCard_2()
{
    card_2 = new Card();
    card_2->setPos(260,500);
    ran_card_2 = (qrand()%4)+1;

    card_21 = new Card();
    QPixmap aa;
    aa.load(":/img/1.png");
    aa = aa.scaled(70,70);
    card_21->setPixmap(aa);

    card_22 = new Card();
    QPixmap bb;
    bb.load(":/img/2.png");
    bb = bb.scaled(70,70);
    card_22->setPixmap(bb);

    card_23 = new Card();
    QPixmap cc;
    cc.load(":/img/3.png");
    cc = cc.scaled(70,70);
    card_23->setPixmap(cc);

    card_24 = new Card();
    QPixmap dd;
    dd.load(":/img/4.png");
    dd = dd.scaled(70,70);
    card_24->setPixmap(dd);

    switch (ran_card_2)
    {
        case 1:
            card_21->setPos(260,500);
            this->addItem(card_21);
            break;
        case 2:
            card_22->setPos(260,500);
            this->addItem(card_22);
            break;
        case 3:
            card_23->setPos(260,500);
            this->addItem(card_23);
            break;
        case 4:
            card_24->setPos(260,500);
            this->addItem(card_24);
            break;
    }
}
/*
void Scene::over()
{
    if(screenMode==1)
    {
        if((eh1->getHealth()+eh2->getHealth()+eh3->getHealth())==0)
        {
            bgRecover();
            screenMode = 0;
            result = new Result();
            QPixmap win;
            win.load(":/img/win.png");
            result->setPixmap(win);
            result->setPos(90,200);
            this->addItem(result);
            QTime tw;
            tw.start();
            while(tw.elapsed()<5000)
                QCoreApplication::processEvents();
            removeItem(result);
        }
        else if((mh1->getHealth()+mh2->getHealth()+mh3->getHealth())==0)
        {
            bgRecover();
            screenMode = 0;
            result = new Result();
            QPixmap lose;
            lose.load(":/img/lose.png");
            result->setPixmap(lose);
            result->setPos(90,200);
            this->addItem(result);
            QTime tl;
            tl.start();
            while(tl.elapsed()<5000)
                QCoreApplication::processEvents();
            removeItem(result);
        }
        else if(tt->getTime()==0)
        {
            bgRecover();
            screenMode = 0;
            result = new Result();
            QPixmap tie;
            tie.load(":/img/tie.png");
            result->setPixmap(tie);
            result->setPos(90,200);
            this->addItem(result);
            QTime ti;
            ti.start();
            while(ti.elapsed()<5000)
                QCoreApplication::processEvents();
            removeItem(result);
        }
    }
}

void Scene::kill()
{
    if(eh1->getHealth()<0)
    {
        removeItem(earthe);
        removeItem(eh1);
        eh1->tozero();
    }
    if(eh2->getHealth()<0)
    {
        removeItem(sune);
        removeItem(eh2);
        eh2->tozero();
    }
    if(eh3->getHealth()<0)
    {
        removeItem(vinuse);
        removeItem(eh3);
        eh3->tozero();
    }
    if(mh1->getHealth()<0)
    {
        removeItem(earth);
        removeItem(mh1);
        mh1->tozero();
    }
    if(mh2->getHealth()<0)
    {
        removeItem(sun);
        removeItem(mh2);
        mh2->tozero();
    }
    if(mh3->getHealth()<0)
    {
        removeItem(vinus);
        removeItem(mh3);
        mh3->tozero();
    }
}

void Scene::enemyCard()
{
    if(screenMode==1)
    {
        int xx,yy ;
        xx = (qrand()% 4)+1;
        yy = (qrand()% 100)+1;
        QTransform transform;
        QTransform trans = transform.rotate(180);
        if(yy%4==0)
        {
            efireball = new EFireball();
            QPixmap *ef = new QPixmap(":/img/fireball.png");
            QPixmap *eft = new QPixmap(ef->transformed(trans));
            efireball->setPixmap(*eft);
            efireball->setPos(170,63);
            this->addItem(efireball);
        }
        switch (xx)
        {
            case 1:
            {
                espaceman = new ESpaceman();
                QPixmap* esm= new QPixmap(":/img/spaceman.png");
                QPixmap *esmt = new QPixmap(esm->transformed(trans));
                *esmt = esmt->scaled(esmt->width()*2/3,esmt->height()*2/3,Qt::KeepAspectRatio);
                espaceman->setPixmap(*esmt);
                rand = (qrand()% 350)+1;
                espaceman->setPos(rand,65);
                this->addItem(espaceman);
                break;
            }
            case 2:
            {
                emissile1 = new EMissile();
                QPixmap* em1= new QPixmap(":/img/missile.png");
                QPixmap *em1t = new QPixmap(em1->transformed(trans));
                emissile1->setPixmap(*em1t);
                rand = (qrand()% 350)+1;
                emissile1->setPos(rand,65);
                this->addItem(emissile1);
                QTime tm1;
                tm1.start();
                while(tm1.elapsed()<300)
                    QCoreApplication::processEvents();
                emissile2 = new EMissile();
                QPixmap* em2= new QPixmap(":/img/missile.png");
                QPixmap *em2t = new QPixmap(em2->transformed(trans));
                emissile2->setPixmap(*em2t);
                rand = (qrand()% 350)+1;
                emissile2->setPos(rand,65);
                this->addItem(emissile2);
                QTime tm3;
                tm3.start();
                while(tm3.elapsed()<300)
                    QCoreApplication::processEvents();
                emissile3 = new EMissile();
                QPixmap* em3= new QPixmap(":/img/missile.png");
                QPixmap *em3t = new QPixmap(em3->transformed(trans));
                emissile3->setPixmap(*em3t);
                rand = (qrand()% 350)+1;
                emissile3->setPos(rand,65);
                this->addItem(emissile3);
                break;
            }
            case 3:
            {
                eironman = new EIronman();
                QPixmap* eim= new QPixmap(":/img/ironman.png");
                QPixmap *eimt = new QPixmap(eim->transformed(trans));
                eironman->setPixmap(*eimt);
                rand = (qrand()% 350)+1;
                eironman->setPos(rand,65);
                this->addItem(eironman);
                break;
            }
            case 4:
            {
                easteroid = new EAsteroid();
                QPixmap* eas= new QPixmap(":/img/rock.png");
                QPixmap *east = new QPixmap(eas->transformed(trans));
                easteroid->setPixmap(*east);
                rand = (qrand()% 350)+1;
                easteroid->setPos(rand,65);
                this->addItem(easteroid);
                break;
            }
        }
    }
}

*/
