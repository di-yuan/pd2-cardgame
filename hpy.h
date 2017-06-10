#ifndef HPY_H
#define HPY_H

#include <QGraphicsTextItem>
class Hpy: public QGraphicsTextItem{
public:
    Hpy(QGraphicsItem * parent=0);
    void decrease(int i);
    int gethpy();
//  private:
    int hpY;
};


#endif // HPY_H
