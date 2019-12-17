//
// Created by Sebastiaan on 17/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BOSSSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_BOSSSCENE_H


#include <libgba-sprite-engine/scene.h>
#include "../src/Gerard.h"

class BossScene : public Scene
{
    std::unique_ptr <Gerard> gerard;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_BOSSSCENE_H
