//
// Created by Sebastiaan on 17/12/2019.
//

#include "Testtube.h"
Testtube::Testtube(int x, int y, int velX, int velY, int dmg) : Killable(x, y, velX, velY, dmg)
{
    this->setSprite((spriteBuilder
            //This needs to be updated based on type of killable
            .withData(TestTubeTiles, sizeof(TestTubeTiles))
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