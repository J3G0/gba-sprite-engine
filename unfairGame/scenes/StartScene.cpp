//
// Created by Sebastiaan on 11/12/2019.
//

#include "StartScene.h"
#include "UnfairScene.h"
#include "BossScene.h"
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>

void StartScene::tick(u16 keys)
{
    if(keys == KEY_START)
    {
        engine->setScene(new BossScene(engine, GenericScene::data));
    }
}