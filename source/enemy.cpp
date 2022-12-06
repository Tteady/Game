#include "enemy.h"
#include "player.h"
#include "game.h"
#include "health.h"
#include "bulletenemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include <QWidget>
extern Game * game;
Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    int random_number = rand() % 700;
    int random_number2 = 2000 + rand() % 3000;
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/enemy.png"));
    setScale(0.2);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(100);

    QTimer * timer2 = new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(attack()));

    timer2->start(random_number2);
}

void Enemy::move() {
    setPos(x(),y()+10);
    if (pos().y() > 1024){
        scene()->removeItem(this);
        delete this;
    }

    QList<QGraphicsItem *> col_items=collidingItems();
    for (int i=0,n=col_items.size();i<n;i++){
        if (typeid(*(col_items[i]))==typeid(Player)) {
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
}

void Enemy::attack() {
    Bulletenemy * bullete = new Bulletenemy();
    bullete->setPos(x(),y());
    game->scene->addItem(bullete);

}
