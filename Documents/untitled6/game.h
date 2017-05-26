#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "healthpack.h"
#include <QTimer>

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    int enemy_speed = 2000;
    int enemy_move_speed = 5;
    int max_score = 0;
    QTimer * timer = new QTimer();
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    HealthPack * healthpack;

};

#endif // GAME_H
