//
// Created by Sebastiaan on 7/12/2019.
//

#include "Killable.h"


Killable::Killable(int x, int y, int velX, int velY) : Renderable(x, y)
{
    this->setSprite((spriteBuilder
          .withData(fireballTiles, sizeof(fireballTiles))
          .withSize(SIZE_8_8)
          .withLocation(x, y)
          .buildPtr()));

    Renderable::getSprite()->setVelocity(velX, velY);
}