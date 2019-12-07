//
// Created by Sebastiaan on 7/12/2019.
//

#include "Renderable.h"
void Renderable::setSprite(std::unique_ptr<Sprite> sprite)
{
    Renderable::sprite = std::move(sprite);
}