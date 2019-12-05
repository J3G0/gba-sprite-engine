//
// Created by Sebastiaan on 1/12/2019.
//

#include "Walkable.h"

void Walkable::tick()
{
    if(coords.empty())
    {
        return;
    }

    sprite->moveTo(coords.front());
    coords.pop_front();
}