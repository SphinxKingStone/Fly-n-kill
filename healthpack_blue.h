#ifndef HEALTHPACK_BLUE_H
#define HEALTHPACK_BLUE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class HealthPack_Blue: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    HealthPack_Blue(int x, int y, QGraphicsItem * parent=0);
};

#endif // HEALTHPACK_BLUE_H
