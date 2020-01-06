//
// Created by Sebastiaan on 22/12/2019.
//

#include <libgba-sprite-engine/background/text_stream.h>

#include <memory>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "EndScene.h"
#include "UnfairScene.h"
#include "../src/Data.h"
#include "../src/sound/win.h"

void EndScene::tick(u16 keys)
{
    TextStream::instance().setText("You won! Press Start replay", 0 , 2);
    //TextStream::instance().setText("(Unless you don't want to)", 1 , 2);

    if(data->getAmountOfDeaths() == 0)
    {
        TextStream::instance().setText("You didn't die, did you cheat?", 1, 1);
    }
    else if(data->getAmountOfDeaths() == 1)
    {
        TextStream::instance().setText("You died only once!" , 1, 5);
    }
    else if(data->getAmountOfDeaths() > 1)
    {
       TextStream::instance().setText("You died " + std::to_string(data->getAmountOfDeaths()) + " times.", 1,3);
    }

    if(keys == KEY_START)
    {
        //Create new data
        engine->transitionIntoScene(new UnfairScene(engine, std::make_shared<Data>()), new FadeOutScene(2));
        //engine->setScene(new UnfairScene(engine, std::make_shared<Data>()));
    }
}

void EndScene::playSounds()
{
    engine->enqueueSound(win, win_bytes);
}
