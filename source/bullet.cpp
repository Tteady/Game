#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "speedship.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QMediaPlayer>

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {
    exp = new QMediaPlayer();
    exp->setMedia(QUrl("qrc:/sounds/vz.wav"));
    setPixmap(QPixmap(":/images/bullet.png"));
    setScale(0.06);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move() {
    QList<QGraphicsItem *> col_items=collidingItems();
    for (int i=0,n=col_items.size();i<n;i++){
        if (typeid(*(col_items[i]))==typeid(Enemy)) {
            scene()->removeItem(col_items[i]);
            exp->setVolume(30);
            exp->play();
            game->score->increaseE();
            scene()->removeItem(this);
            delete col_items[i];
            delete this;
            return;
        }
        else if (typeid(*(col_items[i]))==typeid(SpeedShip)) {
            exp->setVolume(30);
            exp->play();
            game->score->increaseS();
            scene()->removeItem(col_items[i]);
            scene()->removeItem(this);
            delete col_items[i];
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
