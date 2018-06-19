#include "human.h"

int Human::costTrump = 30000000;
int Human::numTrump = 3;
Human::Human()
{

}

void Human::setStatusPlayer(bool b)
{
    statusPlayer = b;
}

bool Human::getStatusPlayer()
{
    return statusPlayer;
}

void Human::setStatusEnemy(bool b)
{
    statusEnemy = b;
}

bool Human::getStatusEnemy()
{
    return statusEnemy;
}

void Human::setHealthPlayer(int i)
{
    healthPlayer = i;
}

int Human::getHealthPlayer()
{
    return healthPlayer;
}

void Human::setHealthEnemy(int i)
{
    healthEnemy = i;
}

int Human::getHealthEnemy()
{
    return healthEnemy;
}

int Human::getCostTrump()
{
    return costTrump;
}

void Human::setNumTrump(int i)
{
    numTrump = i;
}

void Human::setNumTrumpDecrease()
{
    --numTrump;
}

int Human::getNumTrump()
{
    return numTrump;
}
