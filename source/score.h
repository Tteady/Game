#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
    Q_OBJECT
public:
    Score(QGraphicsItem * parent=0);
    void increaseB();
    void increaseE();
    void increaseM();
    void increaseS();
    int getscore();
private:
    int score;
};

#endif // SCORE_H
