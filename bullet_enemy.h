#ifndef BULLET_ENEMY_H
#define BULLET_ENEMY_H

#include "bullet.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Bullet_Enemy: public Bullet{
    Q_OBJECT
public:
    Bullet_Enemy();

public slots:
    virtual void move();
};

#endif // BULLET_ENEMY_H
