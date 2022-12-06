#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <Qwidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game (QWidget * parent = 0);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
public slots:
};

#endif // GAME_H
