#include <QGraphicsScene>
#include "player.h"
#include "game.h"
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QFont>
#include <QMediaPlayer>
#include <QImage>

Game::Game(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,1024);

    setBackgroundBrush(QBrush(QImage(":/images/space2.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,1024);

    player = new Player();
    player->setPos(400,924);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x()+650, health->y());
    scene->addItem(health);

    QTimer * timer = new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),player, SLOT(spawn()));
    timer->start(4000);

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/HeatleyBros.mp3"));
    music->setVolume(15);
    music->play();

    show();
}
