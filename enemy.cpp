#include "enemy.h"

#include <QTimer>
#include <QDebug>

Enemy::Enemy()
{
    // draw a rect
    setPixmap(QPixmap(":/picture/img/king of devl.png"));

    // create Qtimer for bullet
    QTimer * timer = new QTimer();

    // connect with Qtimer
    connect(timer, SIGNAL(timeout()), this, SLOT(shoot()));

    // set timer
    timer->start(50);
}

void Enemy::shoot()
{
    //qDebug() << "enemy shoot";
}
