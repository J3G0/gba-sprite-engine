//
// Created by Sebastiaan on 17/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H


#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>

#include <utility>
#include "../src/renderable/Gerard.h"
#include "../src/Data.h"
#include "../src/killable/Killable.h"
#include "../src/renderable/Healthbar.h"

class GenericScene : public Scene
{

private:
    int atTime = 0;
    int deathTime = 0;
protected:
    std::vector<Sprite*> spritesVector;
    std::unique_ptr<Background> background;
    std::unique_ptr<Background> clouds;
    int scrollX = 0;
    std::unique_ptr<Gerard> gerard;
    // No 64x16 possible
    // (see https://www.coranac.com/tonc/text/regobj.htm#tbl-obj-size)
    std::unique_ptr<Healthbar> healthbarGerard;
    std::vector<std::unique_ptr<Healthbar>> healthBarScientist;
    std::vector<std::unique_ptr<Killable>> killables;
    int killablesSize = 0;
    std::vector<std::unique_ptr<Renderable>> walkables;
    int walkablesSize = 0;
    std::vector<std::unique_ptr<Renderable>> nonWalkables;
    int nonWalkablesSize = 0;
    std::shared_ptr<Data> data;
    std::vector<int> walkableBackgroundTiles = {0x001A, 0x001B, 0x001C, 0x001D};
    bool canTransitionToBoss = false;

public:
    GenericScene(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Data> data) : Scene(std::move(engine)), data(std::move(data)){}
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
    void load() override;
    void basicLoad();
    void tick(u16 keys) override;

    VECTOR updateVelocity(Direction d, bool onWalkableTile, int currentTime, int timePassed, u16 keys);
    Direction getCollidingDirection();
    virtual void registerInput(u16 keys);
    bool isOnWalkableTile();
    int getBackgroundTileBlock();
    void updateGerardAnimation();
    int getAtTime() const { return atTime; }
    void setAtTime(int atTime) { this->atTime = atTime; }
    void updateSprites();
    void moveSprites();
    void checkCollisionWithSprites();
    void updateHealthbar();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
