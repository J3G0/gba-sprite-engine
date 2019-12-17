//
// Created by Sebastiaan on 17/12/2019.
//

#include "Scientist.h"
Scientist::Scientist(int x, int y) : Renderable(x,y, false)
{
    this->setSprite((spriteBuilder
            .withData(Mad_Saaientist_WalkingTiles, sizeof(Mad_Saaientist_WalkingTiles))
            .withSize(SIZE_32_32)
            .withLocation(x,y)
            .withAnimated(4, 5)
            .buildPtr()));
}