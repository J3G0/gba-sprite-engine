#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_bios.h>
#include <cmath>
#include <libgba-sprite-engine/gbavector.h>
#include "Fireball.h"

// https://github.com/J3G0/gba-sprite-engine/blob/master/demos/demo3-foodthrowing/src/bullet.cpp

void Fireball::tick()
{
    if(coords.empty()) {
        return;
    }

    sprite->moveTo(coords.front());
    coords.pop_front();
}