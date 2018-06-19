#include "human_enemy.h"
#include "mainwindow.h"

#include <cstdlib>
#include <QDebug>

int Human::healthEnemy = 100;
bool Human::statusEnemy = true;
int Human_Enemy::damageBullet = 1;

Human_Enemy::Human_Enemy()
{
    bulletShootSpeed = 1000;
    EnemyMoveSpeed = 2000;

    setPicture();

    QTimer * timeBulletShootSpeed = new QTimer();
    // connect with Qtimer
    connect(timeBulletShootSpeed, SIGNAL(timeout()), this, SLOT(shoot()));
    // set timer
    timeBulletShootSpeed->start(bulletShootSpeed);

    tmrEnemyMoveSpeed = new QTimer();
    // connect with Qtimer
    connect(tmrEnemyMoveSpeed, SIGNAL(timeout()), this, SLOT(moveEnemy()));
    // set timer
    tmrEnemyMoveSpeed->start(EnemyMoveSpeed);

}

void Human_Enemy::setPicture()
{
    setPixmap(QPixmap(":/picture/img/king of devl.png"));
}

void Human_Enemy::specialSkill()
{

}

void Human_Enemy::setHealth()
{
    if (Score::getScore() >= 0){
        if (Human::getStatusPlayer() == true){
            healthEnemy -= damageBullet;
        }
    }
    else{
        if (Human::getStatusPlayer() == true){
            healthEnemy += damageBullet;
            if (healthEnemy > 100){
                healthEnemy = 100;
            }
        }
    }
}

int Human_Enemy::getHealth()
{
    return healthEnemy;
}

void Human_Enemy::shoot()
{
    if (MainWindow::getstatuspauseGame() == false){
        if (Human::getStatusPlayer() == true){
            int setVisible = 3;
            bullet = new Bullet_Enemy();
            bullet->setPos(this->x() + this->pixmap().width()/2 - setVisible*0, this->y() + this->pixmap().width()/2);
            scene()->addItem(static_cast<QGraphicsPixmapItem*>(bullet));
        }
        else{
            // enemy dont shoot
        }
    }
}

void Human_Enemy::moveEnemy()
{
    if (MainWindow::getstatuspauseGame() == false){
        if (Human::getStatusPlayer() == true){
            int randomRange = scene()->width() - this->pixmap().width();
            long int random_x = random() % randomRange;
            this->setPos(random_x, y());
        }
        else{
            // enemy dont move
        }
    }
}
