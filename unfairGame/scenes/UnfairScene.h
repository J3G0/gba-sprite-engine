//
// Created by Sebastiaan on 28/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "../src/Killable.h"
#include "../src/Gerard.h"


//Vragen

// Transparancy?
// -- > in orde
// Wie moet bijhouden hoeveel keer doodgegaan, hoe beste overgaan van startscene naar spel scene (heletijd op en af)
// -- > aparte klasse met data
// Gerard een shared ptr? aangezien deze over meerdere scenes hetzelfde zou (moeten) blijven?
// --> niet nodig, wordt opgeruimd bij scene verandering

enum UnfairSceneState {FIREBALL1, FIREBALL2, FIREBALL3};

class UnfairScene : public Scene
{
private:
    std::unique_ptr<Gerard> gerard;
    std::unique_ptr<Background> mario_bg;
    std::vector<std::unique_ptr<Killable>> killables;
    std::vector<std::unique_ptr<Renderable>> walkables;
    std::vector<std::unique_ptr<Renderable>> nonWalkables;

    std::vector<int> walkableBackgroundTiles = {0x005,0x006};

    int scrollX, scrollY;
    int rotation;
    int rotationDiff = 128;
    int atTime = 0;
    UnfairSceneState gameState = FIREBALL1;
public:
    UnfairSceneState getGameState() const;
    void setGameState(UnfairSceneState gameState);

public:
    UnfairScene(std::shared_ptr<GBAEngine> engine) : Scene(engine), rotation(0), rotationDiff(128), scrollX(0), scrollY(0) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
    void load() override;
    void tick(u16 keys) override;
    void registerInput(u16 keys);

    int getAtTime() const;
    void setAtTime(int atTime);
    void updateSprites();
    void moveSprites();
    Direction getCollidingDirection();
    void updateGerardAnimation();
    int getBackgroundTileBlock();
    bool isOnWalkableTile();
    //todo: make priv
    int fireBallTimer = 0;
    bool swap = false;
    Direction d = NOT_MOVING;
};

#endif //GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H