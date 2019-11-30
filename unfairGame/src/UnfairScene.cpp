//
// Created by Sebastiaan on 28/11/2019.
//
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <algorithm>
#include "UnfairScene.h"
#include "sprite_data.h"
#include "Fireball.h"
#include <stdlib.h>

#define JUMP_TIME 1000

std::vector<Background *> UnfairScene::backgrounds() {
    return { mario_bg.get() };
}

std::vector<Sprite*> UnfairScene::sprites()
{
    std::vector<Sprite*> sprites;
    spriteVector.clear();
    spriteVector.push_back(redSprite.get());
    spriteVector.push_back(fireBall.get());

    sprites.push_back(yellowSprite.get());

    for(auto& b : fireBalls)
    {
        sprites.push_back(b->getSprite());
        spriteVector.push_back(b->getSprite());
    }

    for(Sprite *s: spriteVector)
    {
        sprites.push_back(s);
    }

    sprites.push_back(fireBall.get());
    return sprites;
}

void UnfairScene::load()
{
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_palette, sizeof(bg_palette)));


    yellowSprite = builder
            .withData(yellow_tempTiles, sizeof(yellow_tempTiles))
            .withSize(SIZE_32_32)
            .withLocation(50, GBA_SCREEN_HEIGHT - 48)
            .buildPtr();

    redSprite = builder
            .withData(red_tempTiles, sizeof(red_tempTiles))
            .withSize(SIZE_32_32)
            .withLocation(100, GBA_SCREEN_HEIGHT - 48)
            .buildPtr();

    fireBall = builder
            .withData(fireballTiles, sizeof(fireballTiles))
            .withLocation(250, 50)
            .withSize(SIZE_8_8)
            .buildPtr();

    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg.get()->useMapScreenBlock(16);
    engine->getTimer()->start();
    atTime = engine->getTimer()->getTotalMsecs();
}

void UnfairScene::tick(u16 keys)
{
    int currentTime = engine->getTimer()->getTotalMsecs();
    int howmanyballs = fireBalls.size();
    removeFireBalls();

    if(currentTime - atTime >= 1000)
    {
        atTime = currentTime;
        fireBalls.push_back(createFireball());
    }

    registerInput(keys);

    if(howmanyballs != fireBalls.size()) {
        engine.get()->updateSpritesInScene();
    }

    for(auto &b : fireBalls)
    {
        b->tick();
    }
    engine->updateSpritesInScene();
    mario_bg.get()->scroll(scrollX, scrollY);

}

void UnfairScene::registerInput(u16 keys)
{
    switch(keys)
    {
        case (KEY_LEFT):
            yellowSprite.get()->setVelocity(1, 0);
            break;
        case (KEY_RIGHT):
            yellowSprite.get()->setVelocity(-1, 0);
            break;

        default:
            yellowSprite.get()->setVelocity(0,0);
    }


}

std::unique_ptr<Fireball> UnfairScene::createFireball()
{
    return std::unique_ptr<Fireball>(
            new Fireball(builder
            .withNewStart(50 - scrollX,50)
            .withLocation(rand() % 50 - scrollX,50)
            .withVelocity(rand() % 7 - 3, rand() % 2 + 1)
            .buildWithDataOf(*fireBall.get())
            ));
}

void UnfairScene::removeFireBalls()
{
    fireBalls.erase(
            std::remove_if(fireBalls.begin(), fireBalls.end(), [](std::unique_ptr<Fireball> &s)
            {
                return (s->getSprite()->getY() > 160 || s->isOffScreen());
            }
            ),
            fireBalls.end());
}