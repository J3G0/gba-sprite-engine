//
// Created by Sebastiaan on 22/12/2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include "EndScene.h"
#include "UnfairScene.h"

void EndScene::tick(u16 keys)
{
    TextStream::instance().clear();
    TextStream::instance().setText("You won! Press Start replay", 0 , 2);

    if(keys == KEY_START)
    {
        engine->setScene(new UnfairScene(engine, data));
    }
}
