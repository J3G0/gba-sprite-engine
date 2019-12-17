//
// Created by Sebastiaan on 17/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H


#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "../src/Gerard.h"
#include "../src/Data.h"
#include "../src/killable/Killable.h"

class GenericScene : public Scene
{

private:
protected:
    std::unique_ptr<Background> mario_bg;
    int atTime = 0;
    int scrollX;
    std::unique_ptr<Gerard> gerard;
    std::vector<std::unique_ptr<Killable>> killables;
    std::vector<std::unique_ptr<Renderable>> walkables;
    std::vector<std::unique_ptr<Renderable>> nonWalkables;
    std::shared_ptr<Data> data;
    std::vector<int> walkableBackgroundTiles = {0x005,0x006};

public:
    GenericScene(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Data> data) : Scene(engine), data(data){}
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



};


#endif //GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
