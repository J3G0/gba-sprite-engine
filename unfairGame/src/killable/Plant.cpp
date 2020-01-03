//
// Created by Sebastiaan on 3/01/2020.
//

#include "Plant.h"
#include "../../sprite/sprite_data/combined_data.h"

Plant::Plant(int x, int y, int velX, int velY, int dmg) : Killable(x, y, velX, velY, dmg)
{
    this->setSprite((spriteBuilder
            .withData(plantTiles, sizeof(plantTiles))
            .withSize(SIZE_16_16)
            .withVelocity(velX, velY)
            .withLocation(x, y)
            .buildPtr()));
    this->x = x;
    this->y = y;
    this->velX = velX;
    this->velY = velY;
    this->dmg = dmg;

}