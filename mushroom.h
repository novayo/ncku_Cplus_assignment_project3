#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "bullet.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Mushroom: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Mushroom();

public slots:
    void move();

private:
    QTimer* tmrMoveMushroom;
    int kindOfMushroom;

};

#endif // MUSHROOM_H
