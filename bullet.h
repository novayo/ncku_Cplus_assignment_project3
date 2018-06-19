#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();

    static int getshootStytle_Player();
    static void setshootStytle_Player(int i);

public slots:
    virtual void move() = 0;

protected:
    static int shootStytle_Player;

};

#endif // BULLET_H
