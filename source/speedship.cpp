#include "speedship.h"
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
SpeedShip::SpeedShip(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {
    QTimer * timer = new QTimer();

    if(game->score->getscore()>250){
        int random_number = rand() % 700;
        setPos(random_number,0);

        setPixmap(QPixmap(":/images/speedship.png"));
        setScale(0.1);

        connect(timer, SIGNAL(timeout()), this, SLOT(move()));

        timer->start(50);
    }
}

void SpeedShip::move() {
    setPos(x(),y()+20);
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
