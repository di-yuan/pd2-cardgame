#ifndef HPI_H
#define HPI_H

#include <QGraphicsTextItem>
class Hpi: public QGraphicsTextItem{
public:
    Hpi(QGraphicsItem * parent=0);
    void decrease(int i);
    int gethpi();
//  private:
    int hpI;
};

#endif // HPI_H
