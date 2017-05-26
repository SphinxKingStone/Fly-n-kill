#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    bool can_shoot = true;
    QTimer * reload_timer = new QTimer();

    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void spawn_healthpack();
    void set_reload();
private:
    QMediaPlayer * bulletsound;
};

#endif // PLAYER_H
