#ifndef BULLET_PLAYER_H
#define BULLET_PLAYER_H

#include "bullet.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Bullet_Player: public Bullet{
    Q_OBJECT
public:
    Bullet_Player();
    Bullet_Player(int i);

public slots:
    virtual void move();

private:
    int thisShootStyle;
    int shootSTime;
    int shootTriple_which;
    bool boolshootSTime;
    bool firstShoot;
};

#endif // BULLET_Player_H
