//
// Created by Sebastiaan on 21/12/2019.
//

#include "Healthbar.h"

Healthbar::Healthbar(int x, int y) : Renderable(x,y,false)
{
    this->setSprite((spriteBuilder
            .withData(HealthBarTiles, sizeof(HealthBarTiles))
            .withSize(SIZE_32_16)
            .withLocation(x,y)
            .buildPtr()));
}
#include "Healthbar.h"
