#include "Health.h"
#include <QFont>
#include "Game.h"
#include <QMessageBox>

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    health = 3;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(int amount){
    health -= amount;

    if (health == 0)
    {
        QMessageBox * box = new QMessageBox;
        box->setText("Game over, your record is " + QString::number(game->max_score));
        box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        box->show();
        game->close();
    }

    setPlainText(QString("Health: ") + QString::number(health));

    //game->score->decrease();
}

void Health::increase(int amount)
{
    health += amount;
    setPlainText(QString("Health: ") + QString::number(health));

}

int Health::getHealth(){
    return health;
}

