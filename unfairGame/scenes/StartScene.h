//
// Created by Sebastiaan on 11/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>

#include <utility>
#include "../src/renderable/Gerard.h"
#include "../src/Data.h"
#include "GenericScene.h"
#include "../src/killable/Plant.h"

class StartScene : public Scene
{
private:
    std::shared_ptr<Data> data;
    std::unique_ptr<Background> background;
    std::unique_ptr<Plant> plant;
    int scrollTextX = 0;
protected:

public:
    StartScene(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Data> data) : Scene(std::move(engine))
    {
        this->data = std::move(data);
    }
    void tick(u16 keys) override;
    void load() override;
    void updateText();
    void playSounds();
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
