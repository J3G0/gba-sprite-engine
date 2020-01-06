//
// Created by Sebastiaan on 11/12/2019.
//

#include "StartScene.h"
#include "UnfairScene.h"
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "../background/StartScreen/startScreen.h"
#include "../src/sound/boooo.h"
#include "../src/sound/HAHA.h"

void StartScene::tick(u16 keys)
{
    scrollTextX = 0;
    if(keys == KEY_START)
    {
        engine->setScene(new UnfairScene(engine, data));
    }
}

void StartScene::load()
{
    engine->enableText();
    TextStream::instance().scroll(scrollTextX, 0);
    updateText();
    playSounds();
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(startScreenPal, sizeof(startScreenPal)));
    background = std::unique_ptr<Background>(new Background(1, startScreenTiles, sizeof(startScreenTiles), startScreenMap, sizeof(startScreenMap)));
    background->useMapScreenBlock(6);
    engine->getTimer()->start();
}

std::vector<Sprite *> StartScene::sprites()
{
    return
    {

    };
}

std::vector<Background *> StartScene::backgrounds()
{
    return
    {
        background.get()
    };
}

void StartScene::updateText()
{
    TextStream::instance().setText(data->getAmountOfDeathsString(), 0, 6);

    std::string displayText = "";
    switch(data->getAmountOfDeaths())
    {
        case 0:
            displayText = "Good luck!!!";
            break;
        case 1:
            displayText = "Mhh, Better next time.";
            break;
        case 2:
            displayText = "Maybe like don't die.";
            break;
        case 3:
            displayText = "Avoid being hit";
            break;
        case 4:
            displayText = "You can read, right?";
            break;
        case 5:
            displayText = "Stopping is an option";
            break;
        case 6:
            displayText = "Perfect, 1*2*3=6";
            break;
        case 7:
            displayText = "You're stubborn.";
            break;
        case 8:
            displayText = "I like trains";
            break;
        case 9:
            displayText = "Stop pressing my buttons";
            break;
        case 10:
            displayText = "Hate the creators yet?";
            break;
        case 11:
            displayText = "You like dying?";
            break;
        case 12:
            displayText = "This is so much fun!";
            break;
        case 13:
            displayText = "Fun for me, pain for you.";
            break;
        case 14:
            displayText = "Still trying?";
            break;
        case 15:
            displayText = "Just give up?";
            break;
        case 16:
            displayText = "Read the name of the game";
            break;
        case 17:
            displayText = "Still trying?";
            break;
        case 18:
            displayText = "Unfair isn't it??";
            break;
        case 19:
            displayText = "Like these texts?";
            break;
        case 20:
            displayText = "Try again?";
            break;
        case 21:
            displayText = "You die so quickly";
            break;
        default:
            displayText = "How did you get here?";
            break;
    }

    TextStream::instance().setText(displayText, 1,6);
}

void StartScene::playSounds()
{
    if(!data->getAtEnd())
    {
        if(data->getAmountOfDeaths() % 2 == 0 && data->getAmountOfDeaths() > 0)
        {
            engine->enqueueSound(boooo, boooo_bytes);
        }
        else if(data->getAmountOfDeaths() > 0)
        {
            engine->enqueueSound(HAHA, HAHA_bytes);
        }
    }
}