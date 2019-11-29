//
// Created by Sebastiaan on 28/11/2019.
//
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "UnfairScene.h"
#include "Smiley.h"
#include "mario-bg.h"

std::vector<Background *> UnfairScene::backgrounds() {
    return { mario_bg.get() };
}

std::vector<Sprite*> UnfairScene::sprites()
{
    return { itsAMeMario.get() };
}

void UnfairScene::load()
{
    engine.get()->disableText();
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(megamanPal, sizeof(megamanPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_palette, sizeof(bg_palette)));

    SpriteBuilder<Sprite> builder;

    itsAMeMario = builder
            .withData(megamanTiles, sizeof(megamanTiles))
            .withSize(SIZE_32_32)
            .withLocation(GBA_SCREEN_WIDTH / 2 - 32, GBA_SCREEN_HEIGHT / 2 - 32)
            .buildPtr();


    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg.get()->useMapScreenBlock(16);

    engine->getTimer()->start();
}

void UnfairScene::tick(u16 keys)
{
    TextStream::instance().setText(itsAMeMario.get()->getLocationAsString(), 18, 1);
    u32 posX = itsAMeMario.get()->getX();
    u32 posY = itsAMeMario.get()->getY();

    switch(keys)
    {
        case KEY_LEFT:
            if(posX > 0)
            scrollX--;
        break;

        case KEY_RIGHT:
            scrollX++;
            break;

        case KEY_DOWN:
            if(posY < GBA_SCREEN_HEIGHT - 32)
            itsAMeMario.get()->moveTo(posX, posY + 1);
            break;

        case KEY_UP:
            if(posY > 0)
            itsAMeMario.get()->moveTo(posX, posY - 1);
            break;
    }
    mario_bg.get()->scroll(scrollX, scrollY);
}