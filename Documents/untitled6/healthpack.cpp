#include "healthpack.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include "Game.h"

extern Game * game;

HealthPack::HealthPack(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    int rand_x = rand() % 700;
    int rand_y = rand() % 400;

    setPixmap(QPixmap(":/images/healthpack.png"));
    setPos(rand_x,rand_y);
}
