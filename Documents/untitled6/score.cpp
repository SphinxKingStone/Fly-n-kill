#include "Score.h"
#include <QFont>
#include <game.h>

extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    if (score > game->max_score)
        game->max_score = score;

    setPlainText(QString("Score: ") + QString::number(score));

    if (score == 20)
    {
        game->enemy_speed = 1800;
        game->enemy_move_speed++;
        game->timer->start(game->enemy_speed);
    }
    else if (score == 40)
    {
        game->enemy_speed = 1500;
        game->enemy_move_speed++;
        game->timer->start(game->enemy_speed);
    }
    else if (score == 65)
    {
        game->enemy_speed = 1300;
        game->enemy_move_speed++;
        game->timer->start(game->enemy_speed);
    }
    else if (score == 80)
    {
        game->enemy_speed = 1100;
        game->enemy_move_speed++;
        game->timer->start(game->enemy_speed);
    }
    else if (score == 100)
    {
        game->enemy_speed = 950;
        game->enemy_move_speed++;
        game->timer->start(game->enemy_speed);
    }
    else if (score == 125)
    {
        game->enemy_speed = 700;
        game->enemy_move_speed++;
        game->timer->start(game->enemy_speed);
    }
}

void Score::decrease(int amount)
{
    score -= amount;

    if (score < 0)
        score = 0;

    setPlainText(QString("Score: ") + QString::number(score));

}

int Score::getScore(){
    return score;
}
