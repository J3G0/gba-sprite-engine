//
// Created by Sebastiaan on 22/12/2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include "EndScene.h"
#include "UnfairScene.h"

void EndScene::tick(u16 keys)
{
    TextStream::instance().setText("You won! Press Start replay", 0 , 2);
    TextStream::instance().setText("(Unless you don't want to)", 1 , 2);
    if(keys == KEY_START)
    {
        //Create new data
        engine->setScene(new UnfairScene(engine, std::shared_ptr<Data>(new Data())));
    }
}
