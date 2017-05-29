#ifndef HEALTHPACK_YELLOW_H
#define HEALTHPACK_YELLOW_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class HealthPack_Yellow: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    HealthPack_Yellow(int x, int y, QGraphicsItem * parent=0);
};

#endif // HEALTHPACK_YELLOW_H
