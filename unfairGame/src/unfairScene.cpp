//
// Created by Sebastiaan on 28/11/2019.
//
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "unfairScene.h"
#include "Smiley.h"

unfairScene::unfairScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Background *> unfairScene::backgrounds() {
    return {};
}

std::vector<Sprite*> unfairScene::sprites()
{
    return { itsAMeMario.get() };
}

void unfairScene::load()
{

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(smiley_pal, sizeof(smiley_pal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    SpriteBuilder<Sprite> builder;

    itsAMeMario = builder
            .withData(smiley_data, sizeof(smiley_data))
            .withSize(SIZE_32_32)
            .withLocation(GBA_SCREEN_WIDTH / 2 - 32, GBA_SCREEN_HEIGHT / 2 - 32)
            .buildPtr();

    engine->getTimer()->start();
}

void unfairScene::tick(u16 keys)
{
    
}