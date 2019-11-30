//
// Created by Sebastiaan on 28/11/2019.
//
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "UnfairScene.h"
#include "sprite_data.h"

#define JUMP_TIME 1000

std::vector<Background *> UnfairScene::backgrounds() {
    return { mario_bg.get() };
}

std::vector<Sprite*> UnfairScene::sprites()
{
    spriteVector.push_back(redSprite.get());

    return { redSprite.get(), yellowSprite.get() };
}

void UnfairScene::load()
{
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_palette, sizeof(bg_palette)));

    SpriteBuilder<Sprite> builder;

    yellowSprite = builder
            .withData(yellow_tempTiles, sizeof(yellow_tempTiles))
            .withSize(SIZE_32_32)
            .withLocation(50, GBA_SCREEN_HEIGHT - 48)
            .buildPtr();

    yellowSprite->setStayWithinBounds(true);

    redSprite = builder
            .withData(red_tempTiles, sizeof(red_tempTiles))
            .withSize(SIZE_32_32)
            .withLocation(150, GBA_SCREEN_HEIGHT - 48)
            .buildPtr();

    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg.get()->useMapScreenBlock(16);

    engine->getTimer()->start();
}

void UnfairScene::tick(u16 keys)
{
    registerInput(keys);

    for(Sprite *s: spriteVector)
    {
        u32 startPosX = s->getStartX();
        u32 posY = s->getY();

        s->moveTo(startPosX - scrollX, posY);
    }

    mario_bg.get()->scroll(scrollX, scrollY);
}

void UnfairScene::registerInput(u16 keys)
{
    switch(keys)
    {
        case (KEY_LEFT):
            scrollX--;
            break;
        case (KEY_RIGHT):
            scrollX++;
            break;
    }
}