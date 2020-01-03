//
// Created by Sebastiaan on 3/01/2020.
//

#include "Flag.h"
Flag::Flag(int x, int y) :  Renderable(x,y,false)
{
    this->setSprite((spriteBuilder
            .withData(flagTiles, sizeof(flagTiles))
            .withSize(SIZE_16_16)
            .withLocation(x,y)
            .buildPtr()));
}