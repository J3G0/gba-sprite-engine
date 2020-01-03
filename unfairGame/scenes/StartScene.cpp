//
// Created by Sebastiaan on 11/12/2019.
//

#include "StartScene.h"
#include "UnfairScene.h"
#include "BossScene.h"
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "../sprite/StartScreen/startScreen.c"

#include "../background/StartScreen/startScreen.h"
void StartScene::tick(u16 keys)
{
    //interaction with player on startscreen
    TextStream::instance().setText("Amount of deaths:" + std::to_string(data->getAmountOfDeaths()), 0, 6);

    /*
     * keeps playing
    //is even
    if(data->getAmountOfDeaths() % 2 == 0 && ) {
        engine->enqueueSound(boooo, boooo_bytes);
    }
    //is odd
    else
        engine->enqueueSound(HAHA, HAHA_bytes);
    */

    if(data->getAmountOfDeaths() == 0){
        TextStream::instance().setText("Good luck!!!", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 1 || data->getAmountOfDeaths() == 14){
        TextStream::instance().setText("Mhh, Better next time.", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 2 || data->getAmountOfDeaths() == 27){
        TextStream::instance().setText("Maybe like don't die.", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 3 || data->getAmountOfDeaths() == 16){
        TextStream::instance().setText("Avoid being hit", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 4|| data->getAmountOfDeaths() == 28){
        TextStream::instance().setText("You can read, right?", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 5 || data->getAmountOfDeaths() == 18){
        TextStream::instance().setText("Stopping is an option", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 6){
        TextStream::instance().setText("Perfect, 1*2*3=6", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 7 || data->getAmountOfDeaths() == 29){
        TextStream::instance().setText("You're stubborn.", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 8 || data->getAmountOfDeaths() == 20){
        TextStream::instance().setText("I like trains", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 9 || data->getAmountOfDeaths() == 21){
        TextStream::instance().setText("Stop pressing my buttons", 1, 4);
    }
    else if(data->getAmountOfDeaths() == 10 || data->getAmountOfDeaths() == 22){
        TextStream::instance().setText("Green is not a creative color", 1, 2);
    }
    else if(data->getAmountOfDeaths() == 11){
        TextStream::instance().setText("Almost 12 deaths", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 12){
        TextStream::instance().setText("Nice this is certainty", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 13){
        TextStream::instance().setText("Hate the creators yet?", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 15){
        TextStream::instance().setText("You like dying?", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 17){
        TextStream::instance().setText("I enjoyed your failure!", 1, 2);
    }
    else if(data->getAmountOfDeaths() == 19){
        TextStream::instance().setText("This is so much fun!", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 23){
        TextStream::instance().setText("Still trying?", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 24){
        TextStream::instance().setText("Just give up?", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 25){
        TextStream::instance().setText("Read the name of the game", 1, 4);
    }
    else if(data->getAmountOfDeaths() == 26){
        TextStream::instance().setText("Unfair isn't it?", 1, 6);
    }
    else if(data->getAmountOfDeaths() == 30){
        TextStream::instance().setText("Did we even test this far?", 1, 4);
    }
    else
        TextStream::instance().setText("I have nothing more to say", 1, 4);

    if(keys == KEY_START)
    {
        //engine->setScene(new UnfairScene(engine, GenericScene::data));
        engine->transitionIntoScene(new UnfairScene(engine, GenericScene::data), new FadeOutScene(2));
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