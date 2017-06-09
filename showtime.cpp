#include "showtime.h"
#include <QFont>
#include <QTimer>

ShowTime::ShowTime(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    time = 60;
    setPlainText(QString::number(time));
    setDefaultTextColor(Qt::black);
    setFont(QFont("ubuntu",20));

    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(decrease()));

    timer->start(1000);
}

void ShowTime::decrease()
{
    time--;
    setPlainText(QString::number(time));
    setDefaultTextColor(Qt::black);
    setFont(QFont("ubuntu",20));
}

int ShowTime::getTime()
{
    return time;
}
