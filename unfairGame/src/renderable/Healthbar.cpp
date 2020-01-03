//
// Created by Sebastiaan on 21/12/2019.
//

#include "Healthbar.h"

Healthbar::Healthbar(int x, int y) : Renderable(x,y,false)
{
    this->setSprite((spriteBuilder
            .withData(HealthBarHeartsTiles, sizeof(HealthBarHeartsTiles))
            .withSize(SIZE_32_16)
            .withLocation(x,y)
            .buildPtr()));
    this->getSprite()->animateToFrame(0);
}
#include "Healthbar.h"
