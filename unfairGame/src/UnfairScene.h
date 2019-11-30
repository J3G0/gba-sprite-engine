//
// Created by Sebastiaan on 28/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#include <libgba-sprite-engine/scene.h>

class UnfairScene : public Scene
{
private:
    std::unique_ptr<Sprite> yellowSprite;
    std::unique_ptr<Sprite> redSprite;
    std::unique_ptr<Background> mario_bg;
    std::vector<Sprite*> spriteVector;
    int scrollX, scrollY;
    int rotation;
    int rotationDiff = 128;

public:
    UnfairScene(std::shared_ptr<GBAEngine> engine) : Scene(engine), rotation(0), rotationDiff(128), scrollX(0), scrollY(0) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
    void load() override;
    void tick(u16 keys) override;
    void registerInput(u16 keys);

    //todo: make priv
    int atTime = 0;
    bool isFalling = false;
};

#endif //GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H