//
// Created by Sebastiaan on 17/12/2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include "BossScene.h"
#include "../sprite/sprite_data/background_data.h"

void BossScene::load()
{
    basicLoad();
    scientist = (std::unique_ptr<Scientist>(new Scientist(100, 112)));
    engine->getTimer()->start();
}

void BossScene::registerInput(u16 keys)
{
    TextStream::instance().setText(std::to_string(spritesVector.size()), 5 , 1);
    updateTubes(keys);
}

void BossScene::updateTubes(u16 keys)
{

}

std::vector<Sprite*> BossScene::sprites()
{
    spritesVector.clear();

    spritesVector.push_back(scientist->getSprite());

    if( gerard->getSprite() != nullptr)
    {
        spritesVector.push_back(gerard->getSprite());
    }

    for(auto &b: walkables)
    {
        spritesVector.push_back(b->getSprite());
    }

    for(auto &b: killables)
    {
        spritesVector.push_back(b->getSprite());
    }

    return spritesVector;
}