#ifndef SPEEDSHIP_H
#define SPEEDSHIP_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointF>
#include <QMediaPlayer>
class SpeedShip: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    SpeedShip(QGraphicsItem *parent=0);
public slots:
    void move();
};
#endif // SPEEDSHIP_H
