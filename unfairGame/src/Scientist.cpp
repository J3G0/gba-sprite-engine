//
// Created by Sebastiaan on 17/12/2019.
//

#include "Scientist.h"
#include "libgba-sprite-engine/gba/tonc_math.h"

Scientist::Scientist(int x, int y) : Renderable(x,y, false)
{
    this->setSprite((spriteBuilder
            .withData(Mad_Saaientist_WalkingTiles, sizeof(Mad_Saaientist_WalkingTiles))
            .withSize(SIZE_32_32)
            .withLocation(x,y)
            .withAnimated(4, 5)
            .buildPtr()));
}

std::vector<std::unique_ptr <Testtube>>  Scientist::tubeBomb(int dx)
{
    std::vector<std::unique_ptr <Testtube>> tubes;
    u32 scientistX = this->getX();
    u32 scientistY = this->getY();

    for(int i = 0; i < 5; i++)
    {
        short rDx = rand() % 3 + 1;
        tubes.push_back(std::unique_ptr<Testtube>(new Testtube(scientistX,scientistY,dx * rDx,-2 +  i,10)));
    }
    return tubes;
}

int Scientist::generateXDestination()
{
    u32 currentXPos = getX();
    u32 generatedXPos = randomX();
    while( abs( generatedXPos - currentXPos ) < 50)
    {
        generatedXPos = randomX();
    }
    return generatedXPos;
}

int Scientist::randomX()
{
    return rand() % GBA_SCREEN_WIDTH - (getSprite()->getWidth() / 2);
}