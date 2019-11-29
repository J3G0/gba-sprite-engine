//
// Created by Sebastiaan on 28/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#include <libgba-sprite-engine/scene.h>

class UnfairScene : public Scene
{
private:
    std::unique_ptr<Sprite> itsAMeMario;
    std::unique_ptr<Sprite> testSprite;
    std::unique_ptr<Background> mario_bg;
    bool hasToDoJump = false;
    bool hasToDie = false;
    int scrollX, scrollY;
    int rotation;
    int rotationDiff = 128;

public:
    UnfairScene(std::shared_ptr<GBAEngine> engine) : Scene(engine), rotation(0), rotationDiff(128), scrollX(0), scrollY(0) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
    void jumpAction();
    void performJump();
    void load() override;
    void tick(u16 keys) override;

    //todo: make priv
    int atTime = 0;
    bool isFalling = false;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
