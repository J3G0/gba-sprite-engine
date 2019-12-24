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
    //interaction with player on startscreen
    TextStream::instance().setText("Amount of deaths:" + std::to_string(data->getAmountOfDeaths()), 0, 6);
    if(data->getAmountOfDeaths() == 0){
        TextStream::instance().setText("Good luck!!!", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 1){
        TextStream::instance().setText("Mhh, Better next time.", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 2){
        TextStream::instance().setText("Maybe like don't die.", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 3){
        TextStream::instance().setText("Avoid being hit", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 4){
        TextStream::instance().setText("You can read, right?", 1, 6);
    }


    if(keys == KEY_START)
    {
        engine->setScene(new UnfairScene(engine, GenericScene::data));
    }
}

void StartScene::load()
{
    basicLoad();
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(startScreenPal, sizeof(startScreenPal)));
    background = std::unique_ptr<Background>(new Background(1, startScreenTiles, sizeof(startScreenTiles), startScreenMap, sizeof(startScreenMap)));
    background->useMapScreenBlock(16);
    healthbarGerard->getSprite()->moveTo(-50, -50);
    gerard->getSprite()->moveTo(-50,-50);
    engine->getTimer()->start();
}