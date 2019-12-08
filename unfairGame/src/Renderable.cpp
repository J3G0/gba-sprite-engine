//
// Created by Sebastiaan on 7/12/2019.
//

#include "Renderable.h"
void Renderable::setSprite(std::unique_ptr<Sprite> sprite)
{
    Renderable::sprite = std::move(sprite);
}

Renderable::Renderable(int x, int y, bool walkable)
{
    this->setSprite((spriteBuilder
            .withData(walkableTiles, sizeof(walkableTiles))
            .withSize(SIZE_32_32)
            .withLocation(x, y)
            .buildPtr()));
    this->walkable = walkable;
}

bool Renderable::isWalkable() const
{
    return walkable;
}

void Renderable::setWalkable(bool walkable)
{
    Renderable::walkable = walkable;
}
