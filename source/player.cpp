#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "health.h"
#include "meteor.h"
#include "speedship.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
extern Game * game;
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/lz.wav"));

    vzp = new QMediaPlayer();
    vzp->setMedia(QUrl("qrc:/sounds/vzplayer.wav"));

    setPixmap(QPixmap(":/images/spaceship.png"));
     setScale(0.3);
}

void Player::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Left){
        if(pos().x() > 0) {
            setPos(x()-15,y());
        }
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800){
            setPos(x()+15,y());
        }
    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0) {
            setPos(x(),y()-15);
        }
    }
    else if (event->key() == Qt::Key_Down) {
        if (pos().y() + 100 < 1024){
            setPos(x(),y()+15);
        }
    }
    else if (event->key() == Qt::Key_Space){
        if(event->isAutoRepeat()==false) {
            event->ignore();
            Bullet * bullet = new Bullet();
            bullet->setPos(x(),y());
            scene()->addItem(bullet);

            if (bulletsound->state() == QMediaPlayer::PlayingState){
                bulletsound->setPosition(0);
            }
            else if (bulletsound->state() == QMediaPlayer::StoppedState){
                bulletsound->setVolume(200);
                bulletsound->play();
            }
        }
    }
}

void Player::spawn() {
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
    Meteor * meteor = new Meteor();
    scene()->addItem(meteor);
    SpeedShip * speedship = new SpeedShip();
    scene()->addItem(speedship);
}






