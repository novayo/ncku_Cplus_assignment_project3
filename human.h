#ifndef HUMAN_H
#define HUMAN_H

#include "bullet.h"
#include "trump.h"
#include "score.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Human :public QObject, public QGraphicsPixmapItem
{
public:
    Human();
    virtual void setPicture() = 0;
    virtual void specialSkill() = 0;
    static void setStatusPlayer(bool b);
    static bool getStatusPlayer();
    static void setStatusEnemy(bool b);
    static bool getStatusEnemy();
    static void setHealthPlayer(int i);
    static int getHealthPlayer();
    static void setHealthEnemy(int i);
    static int getHealthEnemy();
    static int getCostTrump();
    static void setNumTrump(int i);
    static void setNumTrumpDecrease();
    static int getNumTrump();


public slots:
    virtual void shoot() = 0;

protected:
    static bool statusPlayer;
    static bool statusEnemy;
    static int healthEnemy;
    static int healthPlayer;
    static int costTrump;
    static int numTrump;
    int bulletShootSpeed;
    Bullet* bullet;
    Bullet* bullet1;
    Bullet* bullet2;
    Trump* trump;
};

#endif // HUMAN_H
