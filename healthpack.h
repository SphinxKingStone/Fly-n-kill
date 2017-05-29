#ifndef HEALTHPACK_H
#define HEALTHPACK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class HealthPack: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    HealthPack(QGraphicsItem * parent=0);
};

#endif // HEALTHPACK_H
