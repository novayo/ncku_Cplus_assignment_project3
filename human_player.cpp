#include "human_player.h"
#include "mainwindow.h"

#include <cstdlib>
#include <QTimer>
#include <QDebug>

int Human::healthPlayer = 5;
bool Human::statusPlayer = true;
bool Human_Player::statusPlayerSparkle = false;
bool Human_Player::statustmrPlayerSparkle = false;
bool Human_Player::statustmrtmrPlayerSparkle = false;
bool Human_Player::PlayIsSparkle = false;

Human_Player::Human_Player()
{
    bulletShootSpeed = 500;

    setPicture();

    tmrPlayerSparkle = new QTimer();
    connect(tmrPlayerSparkle, SIGNAL(timeout()), this, SLOT(playerSparkle()));
    tmrtmrPlayerSparkle = new QTimer();
    connect(tmrtmrPlayerSparkle, SIGNAL(timeout()), this, SLOT(tmrtmrPlayerSparkle_Timeout()));

    tmrPlayerCheck = new QTimer();
    connect(tmrPlayerCheck, SIGNAL(timeout()), this, SLOT(PlayerCheck()));
    tmrPlayerCheck->start(100);
}

void Human_Player::setPicture()
{
    setPixmap(QPixmap(":/picture/img/raiden3.ico"));
}

void Human_Player::setHealth(int i)
{
    if (i < 0){
        if (Human::getStatusEnemy() == true && statustmrPlayerSparkle == false){
            --healthPlayer;
            statustmrPlayerSparkle = true;
        }
    } else{
        healthPlayer += i;
        if (healthPlayer > 5){
            healthPlayer = 5;
        }
    }
}

void Human_Player::PlayerCheck()
{
    if (MainWindow::getstatuspauseGame() == false){
        if (statustmrPlayerSparkle == true && statustmrtmrPlayerSparkle == false){
            tmrPlayerSparkle->start(100);
            tmrtmrPlayerSparkle->start(2000);
            statustmrtmrPlayerSparkle = !statustmrtmrPlayerSparkle;
            PlayIsSparkle = true;
        }
    }
}

void Human_Player::playerSparkle()
{
    if (MainWindow::getstatuspauseGame() == false){
        if (statusPlayerSparkle == true){
            setPixmap(QPixmap(":/picture/img/raiden3.ico"));
            statusPlayerSparkle = !statusPlayerSparkle;
        }
        else{
            setPixmap(QPixmap(":/picture/img/transparently.png"));
            statusPlayerSparkle = !statusPlayerSparkle;
        }
    }
}

void Human_Player::tmrtmrPlayerSparkle_Timeout()
{
    if (MainWindow::getstatuspauseGame() == false){
        statustmrPlayerSparkle = false;
        statustmrtmrPlayerSparkle = false;
        PlayIsSparkle = false;
        tmrPlayerSparkle->stop();
        tmrtmrPlayerSparkle->stop();
        setPixmap(QPixmap(":/picture/img/raiden3.ico"));
    }
}

int Human_Player::getHealth()
{
    return healthPlayer;
}

bool Human_Player::getPlayIsSparkle()
{
    return PlayIsSparkle;
}

void Human_Player::specialSkill()
{
    if (Score::getScore() > costTrump && Human::getNumTrump() > 0){
        trump = new Trump();
        trump->setPos(scene()->width()/2 - trump->pixmap().width()/2, scene()->height());
        scene()->addItem(static_cast<QGraphicsPixmapItem*>(trump));
        Score::setScoreDecreaseSkill();
        Human::setNumTrumpDecrease();
    }
}

void Human_Player::shoot()
{
    if (Human::getStatusEnemy() == true){
        int setVisible = 3;

        if (Bullet::getshootStytle_Player() == 0){
            bullet = new Bullet_Player();
        } else if (Bullet::getshootStytle_Player() == 1){
            bullet = new Bullet_Player();
        } else if (Bullet::getshootStytle_Player() == 2){
            bullet = new Bullet_Player(0);
            bullet1 = new Bullet_Player(1); // left bullet
            bullet2 = new Bullet_Player(2); // right bullet
            bullet1->setPos(this->x() + this->pixmap().width()/2 - setVisible*4, this->y() + this->pixmap().width()/2);
            bullet2->setPos(this->x() + this->pixmap().width()/2 - setVisible*4, this->y() + this->pixmap().width()/2);
            scene()->addItem(static_cast<QGraphicsPixmapItem*>(bullet1));
            scene()->addItem(static_cast<QGraphicsPixmapItem*>(bullet2));
        }
        bullet->setPos(this->x() + this->pixmap().width()/2 - setVisible*4, this->y() + this->pixmap().width()/2);
        scene()->addItem(static_cast<QGraphicsPixmapItem*>(bullet));
    }
    else{
        // boss destroyed
    }
}



