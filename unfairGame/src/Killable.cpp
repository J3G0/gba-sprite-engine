//
// Created by Sebastiaan on 7/12/2019.
//

#include "Killable.h"
#include "../sprite/sprite_data.h"


Killable::Killable(int x, int y) : Renderable(x, y)
{
    this->setSprite((spriteBuilder
          .withData(fireballTiles, sizeof(fireballTiles))
          .withSize(SIZE_8_8)
          .withLocation(x, y)
          .buildPtr()));
}