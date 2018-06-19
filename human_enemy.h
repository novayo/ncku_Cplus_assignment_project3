#ifndef HUMAN_ENEMY_H
#define HUMAN_ENEMY_H

#include "human.h"
#include "bullet_enemy.h"

#include <QTimer>

class Human_Enemy : public Human
{
    Q_OBJECT
public:
    Human_Enemy();
    virtual void setPicture();
    virtual void specialSkill();
    static void setHealth();
    static int getHealth();

public slots:
    virtual void shoot();
    void moveEnemy();

private:
    static int damageBullet;
    int EnemyMoveSpeed;
    QTimer* tmrEnemyMoveSpeed;
};

#endif // HUMAN_ENEMY_H
