//
// Created by Sebastiaan on 30/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_FIREBALL_H
#define GBA_SPRITE_ENGINE_PROJECT_FIREBALL_H

#include <libgba-sprite-engine/sprites/sprite.h>
#ifdef CODE_COMPILED_AS_PART_OF_TEST
#include <libgba-sprite-engine/gba/tonc_math_stub.h>
#else
#include <libgba-sprite-engine/gba/tonc_math.h>
#endif
#include <deque>

// based on https://github.com/J3G0/gba-sprite-engine/blob/master/demos/demo3-foodthrowing/src/bullet.h

class Fireball
{
private:
    std::unique_ptr<Sprite> sprite;
    std::deque<VECTOR> coords;
    VECTOR dest;

public:
    Fireball(std::unique_ptr<Sprite> sprite) : sprite(std::move(sprite)), dest(VECTOR()) {}

    void tick();
    bool isOffScreen() { return sprite->isOffScreen(); }
    Sprite* getSprite() { return sprite.get(); }
};


#endif //GBA_SPRITE_ENGINE_PROJECT_FIREBALL_H
