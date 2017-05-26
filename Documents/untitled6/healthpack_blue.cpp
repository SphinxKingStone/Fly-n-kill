#include "healthpack_blue.h"
#include <QGraphicsScene>
#include <healthpack.h>
#include "Game.h"

HealthPack_Blue::HealthPack_Blue(int x, int y, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/Blue_HP.png"));
    setPos(x, y);
}
