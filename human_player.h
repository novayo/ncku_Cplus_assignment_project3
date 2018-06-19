#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "human.h"
#include "bullet_player.h"

#include <QObject>
#include <QTimer>

class Human_Player : public Human
{
    Q_OBJECT
public:
    Human_Player();
    virtual void setPicture();
    virtual void specialSkill();
    static void setHealth(int i);
    static int getHealth();
    static bool getPlayIsSparkle();

public slots:
    virtual void shoot();
    void PlayerCheck();
    void playerSparkle();
    void tmrtmrPlayerSparkle_Timeout();

private:
    int numSpecialSkill;
    QTimer* tmrPlayerSparkle;
    QTimer* tmrtmrPlayerSparkle;
    QTimer* tmrPlayerCheck;
    static bool statustmrtmrPlayerSparkle;
    static bool statustmrPlayerSparkle;
    static bool statusPlayerSparkle;
    static bool PlayIsSparkle;

};

#endif // HUMAN_PLAYER_H
