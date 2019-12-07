
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>
#include "../scenes/UnfairScene.h"



//Notities:
/***
 * pallette --> const unsigned short (0x0000)
 * data --> char
 * voor sprites
 * grit pic1.png pic2.png kul.png -ftc -pS -gB8 -O shared.c
 *
 * voor backgrounds
 * grit splashimage.png -gt -gB8 -mRtpf -mLs -ftc
 */
int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    UnfairScene* startScene = new UnfairScene(engine);
    engine->setScene(startScene);

    while (true)
    {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}