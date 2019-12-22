//
// Created by Sebastiaan on 22/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ENDSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_ENDSCENE_H


#include "StartScene.h"

class EndScene : public StartScene
{
public:
    EndScene(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Data> data) : StartScene(std::move(engine), std::move(data)){}
protected:
private:
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENDSCENE_H
