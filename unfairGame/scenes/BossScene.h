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
#include "GenericScene.h"
#include "../src/killable/Mine.h"

class BossScene : public GenericScene
{
public:
    BossScene(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Data> data) : GenericScene(std::move(engine), std::move(data)){}
    void load() override;
    void registerInput(u16 keys) override;
    std::vector<Sprite*> sprites() override;
    void spawnTubeBomb();
    void spawnFireBall();
    void spawnFireBalls();
    void handleScientistActions(u32 currentTime);
    void handleMine(u32 currentTime);
    void updateMine();
    bool isMineHittingScientist();
    void updateScientistHealthbar();

protected:

private:
    std::unique_ptr<Scientist> scientist;
    std::unique_ptr<Mine> mine;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BOSSSCENE_H
