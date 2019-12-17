//
// Created by Sebastiaan on 11/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "../src/Gerard.h"
#include "../src/Data.h"

class StartScene : public Scene
{
private:
    std::unique_ptr<Gerard> g;
    std::unique_ptr<Background> mario_bg;
    std::shared_ptr<Data> data;

public:
    StartScene(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Data> data) : Scene(engine), data(data){}
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
