#include "Score.h"
#include <QFont>
#include <game.h>
#include <math.h>

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

    if (div(score, 20).rem == 0)
    {
        game->enemy_speed -= 250;
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
