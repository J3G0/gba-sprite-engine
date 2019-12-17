//
// Created by Sebastiaan on 17/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BOSSSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_BOSSSCENE_H


#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>

#include <utility>

#include "../src/Gerard.h"
#include "../src/Data.h"
#include "../src/Scientist.h"

class BossScene : public GenericScene
{
private:

public:
    BossScene(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Data> data) : GenericScene(std::move(engine), data(std::move(data)){}
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BOSSSCENE_H
