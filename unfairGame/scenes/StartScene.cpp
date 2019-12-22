//
// Created by Sebastiaan on 11/12/2019.
//

#include "StartScene.h"
#include "UnfairScene.h"
#include "BossScene.h"
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include "../sprite/StartScreen/startScreen.c"
void StartScene::tick(u16 keys)
{
    TextStream::instance().setText("Amount of deaths:" + std::to_string(data->getAmountOfDeaths()), 0, 6);
    if(keys == KEY_START)
    {
        engine->setScene(new BossScene(engine, GenericScene::data));
    }
}

void StartScene::load()
{
    basicLoad();
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(startScreenPal, sizeof(startScreenPal)));
    background = std::unique_ptr<Background>(new Background(1, startScreenTiles, sizeof(startScreenTiles), startScreenMap, sizeof(startScreenMap)));
    background->useMapScreenBlock(16);
    healthbar->getSprite()->moveTo(-50,-50);
    gerard->getSprite()->moveTo(-50,-50);
    engine->getTimer()->start();
}