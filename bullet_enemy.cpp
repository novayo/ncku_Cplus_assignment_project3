#include "bullet_enemy.h"
#include "human_player.h"
#include "score.h"
#include "mainwindow.h"

#include <QTimer>
#include <QList>
#include <QDebug>

Bullet_Enemy::Bullet_Enemy()
{
    // draw a rect
    setPixmap(QPixmap(":/picture/img/fireball.png"));

    // create Qtimer for bullet
    QTimer * timer = new QTimer();
    // connect with Qtimer
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    // set timer
    timer->start(50);
}


void Bullet_Enemy::move()
{
    if (MainWindow::getstatuspauseGame() == false){
        // if bullet collide with enemy, destroy them
        if (MainWindow::getStatusGame() == true){
            QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i=0, n = colliding_items.size(); i<n; ++i){
                if (typeid(*(colliding_items[i])) == typeid(Human_Player)){
                    Human_Player::setHealth(-1);

                    // decrease the score
                    if (Human_Player::getPlayIsSparkle() == false){
                        Score::setScoreDecrease();
                    }
                    else{
                        // player is in god mode
                    }

                    if (Human_Player::getHealth() <= 0){
                        Human::setStatusPlayer(false);
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

            // bullet move down
            setPos(x(), y() + 10);
            if (pos().y() > scene()->height()){
                //qDebug() << "delete bullet";
                this->scene()->removeItem(this);
                //qDebug() << "Enemy Bullet Deleted";
                delete this;
            }
        }
        else{
            this->scene()->removeItem(this);
            delete this;
        }
    }
}

