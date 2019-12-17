//
// Created by Sebastiaan on 17/12/2019.
//

#include "BossScene.h"
#include "../sprite/sprite_data/background_data.h"

std::vector<Background *> BossScene::backgrounds()
{
    return { mario_bg.get() };
}

std::vector<Sprite*> BossScene::sprites()
{
    std::vector<Sprite*> sprites;

    if( gerard.get()->getSprite() != nullptr)
    {
        sprites.push_back(gerard->getSprite());
    }

    if(scientist.get()->getSprite() != nullptr)
    {
        sprites.push_back(scientist->getSprite());
    }

    return sprites;
}

void BossScene::load()
{
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_palette, sizeof(bg_palette)));

    gerard = std::unique_ptr<Gerard>(new Gerard(0,112, NOT_MOVING));
    gerard->getSprite()->setStayWithinBounds(true);

    scientist = std::unique_ptr<Scientist>(new Scientist(50,112));
    scientist.get()->getSprite()->moveTo(GBA_SCREEN_WIDTH - scientist.get()->getSprite()->getWidth(), scientist->getStartY());

    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg.get()->useMapScreenBlock(16);

}

void BossScene::tick(u16 keys)
{
    switch(keys)
    {

    }
}