//
// Created by Sebastiaan on 7/12/2019.
//

#include "Gerard.h"
Gerard::Gerard(int xLocation, int yLocation, Direction direction) : Renderable(xLocation, yLocation)
{
    this->xLocation = xLocation;
    this->yLocation = yLocation;
    this->direction = direction;
    this->setSprite((spriteBuilder
        .withData(yellow_tempTiles, sizeof(yellow_tempTiles))
        .withSize(SIZE_32_32)
        .withLocation(xLocation, yLocation)
        .buildPtr()));
}

void Gerard::setDirection(Direction newDirection)
{
    direction = newDirection;
    switch(direction)
    {
        case LEFT:
    }
}