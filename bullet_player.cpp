#include "bullet_player.h"
#include "human_enemy.h"
#include "score.h"
#include "mainwindow.h"

#include <QTimer>
#include <QList>
#include <QDebug>

Bullet_Player::Bullet_Player()
{
    // 0 for straight, 1 for S, 2 for triple
    shootTriple_which = -1;
    shootSTime = 0;
    boolshootSTime = false;
    firstShoot = true;
    if (Bullet::getshootStytle_Player() == 0){
        thisShootStyle = 0;
    } else if (Bullet::getshootStytle_Player() == 1){
        thisShootStyle = 1;
    } else if (Bullet::getshootStytle_Player() == 2){
        thisShootStyle = 2;
    }
    // draw a rect
    setPixmap(QPixmap(":/picture/img/yellowball.png"));

    // create Qtimer for bullet
    QTimer * timer = new QTimer();

    // connect with Qtimer
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // set timer
    timer->start(50);
}

Bullet_Player::Bullet_Player(int i)
{
    // 0 for straight, 1 for S, 2 for triple
    shootTriple_which = i;
    shootSTime = 0;
    boolshootSTime = false;
    firstShoot = true;
    if (Bullet::getshootStytle_Player() == 0){
        thisShootStyle = 0;
    } else if (Bullet::getshootStytle_Player() == 1){
        thisShootStyle = 1;
    } else if (Bullet::getshootStytle_Player() == 2){
        thisShootStyle = 2;
    }
    // draw a rect
    setPixmap(QPixmap(":/picture/img/yellowball.png"));

    // create Qtimer for bullet
    QTimer * timer = new QTimer();

    // connect with Qtimer
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // set timer
    timer->start(50);
}


void Bullet_Player::move()
{
    if (MainWindow::getstatuspauseGame() == false){
        // if bullet collide with Player, destroy them
        if (MainWindow::getStatusGame() == true){
            QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i=0, n = colliding_items.size(); i<n; ++i){
                if (typeid(*(colliding_items[i])) == typeid(Human_Enemy)){
                    Human_Enemy::setHealth();
                    // increase the score
                    Score::setScoreIncrease();

                    if (Human_Enemy::getHealth() <= 0){
                        Human::setStatusEnemy(false);
                        // remove them both
                        scene()->removeItem(colliding_items[i]);
                        scene()->removeItem(this);

                        // delete them both
                        delete colliding_items[i];
                        delete this;
                    }
                    else{
                        scene()->removeItem(this);
                        delete this;
                    }
                    // prevent do "delete this;" again down below
                    return;
                }
                else if (typeid(*(colliding_items[i])) == typeid(Trump)){
                    scene()->removeItem(this);
                    delete this;
                    // prevent do "delete this;" again down below
                    return;
                }
            }

            // bullet move up
            // 0 for straight, 1 for S, 2 for triple
            if (thisShootStyle == 0){
                setPos(x(), y() - 10);
            } else if (thisShootStyle == 1){
                if (boolshootSTime == false){
                    ++shootSTime;
                    setPos(x() - 20, y() - 10);
                } else{
                    --shootSTime;
                    setPos(x() + 20, y() - 10);
                }

                if (firstShoot == true){
                    if (shootSTime == 5){
                        boolshootSTime = true;
                        firstShoot = false;
                    }
                } else{
                    if (shootSTime == 5){
                        boolshootSTime = true;
                    } else if (shootSTime == -5){
                        boolshootSTime = false;
                    }
                }
            } else{
                if (shootTriple_which == 1){
                    setPos(x() - 5, y() - 10);
                } else if(shootTriple_which == 0){ // 0 is middle bullet
                    setPos(x() - 0, y() - 10);
                } else if (shootTriple_which == 2){
                    setPos(x() + 5, y() - 10);
                } else{
                    // do nothing
                }
            }

            if (pos().y() < 0){
                //qDebug() << "delete bullet";
                this->scene()->removeItem(this);
                //qDebug() << "Player Bullet Deleted";
                delete this;
            }
        }
        else{
            this->scene()->removeItem(this);
            delete this;
        }
    }
}

