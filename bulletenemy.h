#ifndef BULLETENEMY_H
#define BULLETENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bulletenemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bulletenemy(QGraphicsItem *parent=0);
public slots:
    void move();
};
#endif // BULLETENEMY_H
