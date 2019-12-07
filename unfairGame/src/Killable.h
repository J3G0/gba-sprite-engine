//
// Created by Sebastiaan on 7/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_KILLABLE_H
#define GBA_SPRITE_ENGINE_PROJECT_KILLABLE_H

#include "../src/Renderable.h"
#include "libgba-sprite-engine/sprites/sprite_builder.h"

class Killable : public Renderable
{
    private:
        int x;
        int y;
        SpriteBuilder<Sprite> spriteBuilder;
    public:
        Killable(int x, int y);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_KILLABLE_H
