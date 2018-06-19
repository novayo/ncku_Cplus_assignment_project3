#include "mainwindow.h"
#include "mushroom.h"

#include <QTimer>
#include <QList>
#include <QDebug>
#include <cstdlib>

Mushroom::Mushroom()
{
    while(true){
        kindOfMushroom = rand()%3;
        // draw a rect
        if (kindOfMushroom == Bullet::getshootStytle_Player()){
            continue;
        }

        if (kindOfMushroom == 0){
            setPixmap(QPixmap(":/picture/img/mushroom.png")); // shoot straight
        } else if(kindOfMushroom == 1) {
            setPixmap(QPixmap(":/picture/img/Gold_Mushroom.png")); // shoot s
        } else if(kindOfMushroom == 2) {
            setPixmap(QPixmap(":/picture/img/TripleMushroomMK.png")); // shoot triple
        }
        break;
    }

    // create Qtimer for bullet
    tmrMoveMushroom = new QTimer();
    connect(tmrMoveMushroom, SIGNAL(timeout()), this, SLOT(move()));
    tmrMoveMushroom->start(50);
}

void Mushroom::move()
{
    // if bullet collide with enemy, destroy them
    if (MainWindow::getstatuspauseGame() == false){
        if (MainWindow::getStatusGame() == true){
            QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i=0, n = colliding_items.size(); i<n; ++i){
                if (typeid(*(colliding_items[i])) == typeid(Human_Player)){
                    Bullet::setshootStytle_Player(kindOfMushroom);
                    MainWindow::setStatusMushroom();
                    // remove them both
                    scene()->removeItem(this);

                    // delete them both
                    delete this;
                    return;
                }
            }

            // bullet move down
            setPos(x(), y() + 5);
            if (pos().y() > scene()->height()){
                this->scene()->removeItem(this);
                delete this;
            }
        }
        else{
            this->scene()->removeItem(this);
            delete this;
        }
    }
}
