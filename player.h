#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>

class Player
{
public:
    Player();
    void createPlayer();
private:
    QGraphicsRectItem *player;
};

#endif // PLAYER_H
