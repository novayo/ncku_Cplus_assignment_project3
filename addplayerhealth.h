#ifndef ADDPLAYERHEALTH_H
#define ADDPLAYERHEALTH_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class AddPlayerHealth: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    AddPlayerHealth();

public slots:
    void move();

private:
    QTimer* tmrMoveBlood;

};

#endif // ADDPLAYERHEALTH_H
