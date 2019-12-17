
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/allocator.h>
#include "../scenes/StartScene.h"
#include "../src/Data.h"



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
    std::shared_ptr<Data> data(new Data());
    StartScene* startScene = new StartScene(engine, data);
    engine->setScene(startScene);
    data->setAmountOfDeaths(0);

    //Doe ne keer zot
    for(;;)
    {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}