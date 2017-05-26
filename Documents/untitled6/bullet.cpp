#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include "healthpack.h"
#include "healthpack_blue.h"
#include "healthpack_yellow.h"

#include <typeinfo>

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/bullet.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            if (1 + rand() % 100 > 95)
            {
                // 25 - это половина healthpack_blue по X
                // 75 - это половина colliding_items[i] aka enemy по X
                // 50 - это половина colliding_items[i] aka enemy по Y
                HealthPack_Blue * healthpack_blue = new HealthPack_Blue(colliding_items[i]->x() + 75 - 25, colliding_items[i]->y() + 50 - 25);
                scene()->addItem(healthpack_blue);
            }
            else if (1 + rand() % 100 > 98)
            {
                HealthPack_Yellow * healthpack_yellow = new HealthPack_Yellow(colliding_items[i]->x() + 75 - 25, colliding_items[i]->y() + 50 - 25);
                scene()->addItem(healthpack_yellow);
            }

            game->score->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(HealthPack))
        {
            game->health->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(HealthPack_Blue))
        {
            game->health->increase(3);

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(HealthPack_Yellow))
        {
            game->health->increase(5);

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        }

    }

    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
