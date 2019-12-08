//
// Created by Sebastiaan on 7/12/2019.
//

#include "Gerard.h"
Gerard::Gerard(int xLocation, int yLocation, Direction direction) : Renderable(xLocation, yLocation, false)
{
    this->xLocation = xLocation;
    this->yLocation = yLocation;
    this->direction = direction;
    this->setSprite((spriteBuilder
        .withData(Walking_Gerard_RightTiles, sizeof(Walking_Gerard_RightTiles))
        .withSize(SIZE_16_32)
        .withLocation(xLocation, yLocation)
        .withAnimated(8, 10)
        .buildPtr()));
}

Gerard::~Gerard()
{

}


void Gerard::setDirection(Direction newDirection)
{
    direction = newDirection;
}
bool Gerard::isJumping() const
{
    return jumping;
}

void Gerard::setIsJumping(bool isJumping)
{
    Gerard::jumping = isJumping;
}

void Gerard::setVelocity(int velX, int velY)
{
    Renderable::getSprite()->setVelocity(velX, velY);
}

int Gerard::getHealth() const
{
    return health;
}

void Gerard::setHealth(int health)
{
    Gerard::health = health;
}

void Gerard::setCharacterDirection(int dx, int dy)
{
    if(dx > 0)
    {
        if(dy == 0)
        {
            setDirection(RIGHT);
        }
        else if(dy > 0)
        {
            setDirection(RIGHT_DOWN);
        }
        else
        {
            setDirection(RIGHT_UP);
        }
    }
    else if (dx < 0)
    {
        if(dy == 0)
        {
            setDirection(LEFT);
        }
        else if(dy > 0)
        {
            setDirection(LEFT_DOWN);
        }
        else
        {
            setDirection(LEFT_UP);
        }
    }
    else
    {
        if(dy > 0)
        {
            setDirection(DOWN);
        }
        else if(dy < 0)
        {
            setDirection(UP);
        }
        else
        {
            setDirection(NOT_MOVING);
        }
    }
}
