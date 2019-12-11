//
// Created by Sebastiaan on 11/12/2019.
//

#include "StartScene.h"
#include "../sprite/sprite_data.h"
#include "../sprite/background_data.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

std::vector<Background *> StartScene::backgrounds()
{
    return { mario_bg.get() };
}

void StartScene::load()
{
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_palette, sizeof(bg_palette)));

    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg.get()->useMapScreenBlock(16);

}

std::vector<Sprite*> StartScene::sprites()
{
    std::vector<Sprite*> sprites;
    sprites.push_back(g->getSprite());
    return sprites;
}

void StartScene::tick(u16 keys)
{

}