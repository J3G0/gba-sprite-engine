
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>

#include "unfairScene.h"



//Notities:
/***
 * pallette --> const unsigned short (0x0000)
 * data --> char
 *
 */
int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    unfairScene* startScene = new unfairScene(engine);
    engine->setScene(startScene);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;

    return 0;
}