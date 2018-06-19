#include "addplayerhealth.h"
#include "mainwindow.h"
#include "human.h"

AddPlayerHealth::AddPlayerHealth()
{
    setPixmap(QPixmap(":/picture/img/blood.png"));
    tmrMoveBlood = new QTimer();
    connect(tmrMoveBlood, SIGNAL(timeout()), this, SLOT(move()));
    tmrMoveBlood->start(50);
}

void AddPlayerHealth::move()
{
    // if bullet collide with enemy, destroy them
    if (MainWindow::getstatuspauseGame() == false){
        if (MainWindow::getStatusGame() == true){
            QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i=0, n = colliding_items.size(); i<n; ++i){
                if (typeid(*(colliding_items[i])) == typeid(Human_Player)){
                    Human_Player::setHealth(+1);

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
