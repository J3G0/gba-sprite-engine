
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    while (true)
    {
        engine->update();
    }

    return 0;
}