//
// Created by Sebastiaan on 22/12/2019.
//

#include "Mine.h"
Mine::Mine(int x, int y, int dmg) : Killable(x, y, 0, 0, dmg)
{
    this->setSprite((spriteBuilder
            //This needs to be updated based on type of killable
            .withData(mineTiles, sizeof(mineTiles))
            .withSize(SIZE_8_8)
            .withVelocity(velX, velY)
            .withLocation(x, y)
            .buildPtr()));
    this->x = x;
    this->y = y;
    this->velX = velX;
    this->velY = velY;
    this->dmg = dmg;
}