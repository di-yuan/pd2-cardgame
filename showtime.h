#ifndef SHOWTIME_H
#define SHOWTIME_H

#include <QObject>
#include <QTime>
#include <QGraphicsTextItem>

class ShowTime: public QGraphicsTextItem
{
    Q_OBJECT
public:
    ShowTime(QGraphicsItem * parent=0);
    int getTime();
private:
    int time;
public slots:
    void decrease();
};

#endif // SHOWTIME_H
