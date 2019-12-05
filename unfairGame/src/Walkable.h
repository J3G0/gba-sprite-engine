//
// Created by Sebastiaan on 1/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_WALKABLE_H
#define GBA_SPRITE_ENGINE_PROJECT_WALKABLE_H
#include <libgba-sprite-engine/sprites/sprite.h>
#ifdef CODE_COMPILED_AS_PART_OF_TEST
#include <libgba-sprite-engine/gba/tonc_math_stub.h>
#else
#include <libgba-sprite-engine/gba/tonc_math.h>
#endif
#include <deque>

class Walkable
{
    private:
        std::unique_ptr<Sprite> sprite;
        std::deque<VECTOR> coords;
        VECTOR dest;
    public:
        Sprite* getSprite() { return sprite.get(); }
        void tick();
        bool isOffScreen() { return sprite->isOffScreen(); }
};



#endif //GBA_SPRITE_ENGINE_PROJECT_WALKABLE_H
