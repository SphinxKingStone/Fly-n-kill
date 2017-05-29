#include "healthpack_yellow.h"
#include <QGraphicsScene>
#include <healthpack.h>
#include "Game.h"

HealthPack_Yellow::HealthPack_Yellow(int x, int y, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Yellow_HP.png"));
    setPos(x, y);
}
