#ifndef METEOR_H
#define METEOR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointF>
#include <QMediaPlayer>
class Meteor: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Meteor(QGraphicsItem * parent=0);
public slots:
    void move();
private:
    int hp;
    QMediaPlayer * met;
};
#endif // METEOR_H
