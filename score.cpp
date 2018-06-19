#include "score.h"
#include "human.h"

#include <QFont>
#include <cstdlib>

long long int Score::score = 0;
long long int Score::addScore = 0;
Score::Score()
{

}

void Score::setScore(int s)
{
    score = s;
}

void Score::setScoreIncrease()
{
    addScore = random() % 1000000 + 1000000;
    // score increase
    score += addScore;
}

void Score::setScoreDecrease()
{
    addScore = random() % 1000000 + 1000000;
    // score increase
    score += (-addScore);
}

void Score::setScoreDecreaseSkill()
{
    addScore = -Human::getCostTrump();
    score += addScore;
}

int Score::getScore()
{
    return score;
}
