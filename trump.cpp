#include "trump.h"
#include "mainwindow.h"

#include <QDebug>

Trump::Trump()
{
    moveSpeed = 20;
    rotateSpeed = 10;

    setPixmap(QPixmap(":/picture/img/trump.png"));

    tmrMoveTrump = new QTimer();
    connect(tmrMoveTrump, SIGNAL(timeout()), this, SLOT(moveTrump()));
    tmrMoveTrump->start(100);

}

void Trump::moveTrump()
{
    if (MainWindow::getstatuspauseGame() == false){
        setPos(x(), y() - moveSpeed);
        setTransformOriginPoint(this->pixmap().width()/2, this->pixmap().height()/2);
        setRotation(rotateSpeed+=10);
        if (y() < 0 - this->pixmap().height()){
            //qDebug() << "delete Trump";
            scene()->removeItem(this);
            delete this;
        }
    }
}
