//
// Created by Sebastiaan on 22/12/2019.
//

#include "Mine.h"
Mine::Mine(int x, int y, int dmg) : Killable(x, y, 0, 0, dmg)
{
    this->setSprite((spriteBuilder
            //This needs to be updated based on type of killable
            .withData(mineTiles, sizeof(mineTiles))
            .withSize(SIZE_16_16)
            .withVelocity(velX, velY)
            .withLocation(x, y)
            .buildPtr()));
    this->x = x;
    this->y = y;
    this->velX = velX;
    this->velY = velY;
    this->dmg = dmg;
    this->needsUpdate = false;
    getSprite()->animateToFrame(0);
}

void Mine::tickMine()
{
    if (getCurrentFrame() < amountOfFrames)
    {
        getSprite()->animateToFrame(currentFrame++);
    }
    else
    {
        resetMine();
    }
}

void Mine::resetMine()
{
    needsUpdate = false;
    setDamaged(false);
    getSprite()->animateToFrame(0);
    currentFrame = 0;
    getSprite()->moveTo(-50,-50);
}
