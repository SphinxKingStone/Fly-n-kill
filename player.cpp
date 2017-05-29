#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "healthpack.h"
#include <QTimer>
#include <game.h>
#include <QList>
#include <TypeInfo>

extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/Bullet_sound.mp3"));

    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    int SPEED = 15;
    if (event->key() == Qt::Key_Left)
    {        
        if (pos().x() > 0)
        setPos(x()-SPEED,y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + game->player->pixmap().width() < 800)
        setPos(x()+SPEED,y());
    }
    else if (event->key() == Qt::Key_Space)
    {
        if (can_shoot)
        {
            reload_timer->start(500);
            can_shoot = false;

            Bullet * bullet = new Bullet();
            bullet->setPos(x()+45,y());
            scene()->addItem(bullet);

            if (bulletsound->state() == QMediaPlayer::PlayingState)
                bulletsound->setPosition(0);

            else if (bulletsound->state() == QMediaPlayer::StoppedState)
                bulletsound->play();
        }

    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::spawn_healthpack()
{
    //Добавить условие, что если уже существует healthpack, то удалить его и поставить новый, в другом месте
     QList<QGraphicsItem *> items = scene()->items();
     for (int i = 0, n = items.size(); i < n; ++i){
         if (typeid(*(items[i])) == typeid(HealthPack))
                return;
     }

     HealthPack * healthpack = new HealthPack();
     scene()->addItem(healthpack);
}

void Player::set_reload()
{
    reload_timer->stop();
    can_shoot = true;
}
