//
// Created by Sebastiaan on 22/12/2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include "EndScene.h"

void EndScene::tick(u16 keys)
{
    TextStream::instance().clear();
    TextStream::instance().setText("     You won!", 0 , 6);
}
