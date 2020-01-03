//
// Created by Sebastiaan on 11/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "../src/renderable/Gerard.h"
#include "../src/Data.h"
#include "GenericScene.h"

class StartScene : public GenericScene
{
private:

protected:

public:
    StartScene(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Data> data) : GenericScene(std::move(engine), std::move(data)){}
    void tick(u16 keys) override;
    void load() override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
