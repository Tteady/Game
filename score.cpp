#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 24));

}

void Score::increaseB() {
    score = score + 10;
    setPlainText(QString("Score: ") + QString::number(score));
}
void Score::increaseE() {
    score = score + 5;
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::increaseM() {
    score = score + 15;
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::increaseS() {
    score = score + 25;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getscore() {
    return score;
}
