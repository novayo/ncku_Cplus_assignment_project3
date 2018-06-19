#include "bullet.h"

int Bullet::shootStytle_Player = 0;

Bullet::Bullet()
{

}

int Bullet::getshootStytle_Player()
{
    return shootStytle_Player;
}

void Bullet::setshootStytle_Player(int i)
{
    shootStytle_Player = i;
}
