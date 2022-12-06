#include "meteor.h"
#include "player.h"
#include "game.h"
#include "health.h"
#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include <QWidget>
#include <QMediaPlayer>
extern Game * game;
Meteor::Meteor(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {
    met = new QMediaPlayer();
    QTimer * timer = new QTimer();

    if(game->score->getscore()>100){
    met->setMedia(QUrl("qrc:/sounds/vzm.wav"));
    hp=6;

    int random_number = rand() % 700;
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/meteor.png"));
    setScale(0.2);

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(100);
    }
}

void Meteor::move() {
    setPos(x(),y()+5);
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
        else if (typeid(*(col_items[i]))==typeid(Bullet)) {
            hp--;
            scene()->removeItem(col_items[i]);
            delete col_items[i];
            if (hp==0){
                met->setVolume(10);
                met->play();
                game->score->increaseM();
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }
}
