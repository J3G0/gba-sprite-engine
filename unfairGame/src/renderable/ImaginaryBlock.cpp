//
// Created by Sebastiaan on 3/01/2020.
//

#include "ImaginaryBlock.h"
ImaginaryBlock::ImaginaryBlock(int x, int y) :  Renderable(x,y,false)
{
    this->setSprite((spriteBuilder
            .withData(blockTiles, sizeof(blockTiles))
            .withSize(SIZE_16_16)
            .withLocation(x,y)
            .buildPtr()));
}