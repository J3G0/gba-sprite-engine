//
// Created by Sebastiaan on 7/12/2019.
//

#include "Renderable.h"
#include "libgba-sprite-engine/gba/tonc_math.h"
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

int Renderable::getIsLeftOfRightOf(Sprite &other)
{
    // If this object is left of other object, return -1 else return 1
    // Used for spawning dynamic killables to throw to Gerard
    int thisX = this->getX();
    int otherX = other.getX();

    return thisX < otherX? -1 : 1;
}

VECTOR Renderable::getVectorToHitOtherSprite(VECTOR otherSpriteCoord)
{
    u32 otherX = otherSpriteCoord.x;
    u32 otherY = otherSpriteCoord.y;
    u32 thisX = getX();
    u32 thisY = getY();

    u32 ricoY = thisY - otherY;
    u32 ricoX = thisX - otherX;
    u32 slope = ricoY / ricoX;

    VECTOR v;
    v.x = 1;
    v.y = min(3,slope);
    return v;
}
