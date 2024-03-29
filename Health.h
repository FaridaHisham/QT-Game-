#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(int health_, QGraphicsItem * parent=0);
    void decrease();
    int getHealth();
    int health;
};

#endif // HEALTH_H
