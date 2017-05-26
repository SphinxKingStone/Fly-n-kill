#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    void decrease(int amount = 1);
    void increase(int amount = 1);
    int getHealth();
private:
    int health;
};

#endif // HEALTH_H
