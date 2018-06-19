#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
    Q_OBJECT
public:
    Score();
    static void setScore(int s);
    static void setScoreIncrease();
    static void setScoreDecrease();
    static void setScoreDecreaseSkill();
    static int getScore();

private:
    static long long int score;
    static long long int addScore;
};

#endif // SCORE_H
