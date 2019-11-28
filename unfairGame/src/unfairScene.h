//
// Created by Sebastiaan on 28/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#include <libgba-sprite-engine/scene.h>

class unfairScene : public Scene
{
private:
    std::unique_ptr<Sprite> itsAMeMario;

public:
    explicit unfairScene(const std::shared_ptr<GBAEngine> &engine);
    unfairScene(unfairScene& other) = delete;

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
