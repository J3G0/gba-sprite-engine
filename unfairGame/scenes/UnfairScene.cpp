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
#include "../sprite/sprite_data.h"
#include <stdlib.h>

#define JUMP_TIME 1000
#define DEBUG 1
#define SCROLL_SPEED 1

std::vector<Background *> UnfairScene::backgrounds()
{
    return { mario_bg.get() };
}

std::vector<Sprite*> UnfairScene::sprites()
{
    std::vector<Sprite*> sprites;

    sprites.push_back(killable.get());
    sprites.push_back(redSprite.get());
    sprites.push_back(yellowSprite.get());

    for(auto &b: killables)
    {
        if(b->getSprite() != nullptr)
        {
            sprites.push_back(b->getSprite());
        }
    }

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

    killable = builder
            .withData(fireballTiles, sizeof(fireballTiles))
            .withSize(SIZE_8_8)
            .withLocation(50, 50)
            .buildPtr();

    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg.get()->useMapScreenBlock(16);
    engine->getTimer()->start();
}

void UnfairScene::tick(u16 keys)
{
    u32 mainX = yellowSprite.get()->getX() + yellowSprite.get()->getWidth();
    u32 mainY = yellowSprite.get()->getY();

    int currentTime = engine->getTimer()->getTotalMsecs();

    if (currentTime - fireBallTimer >= 500)
    {
        fireBallTimer = currentTime;
        killables.push_back(std::unique_ptr<Killable>(new Killable(rand() % 50,rand() % 50)));
        engine.get()->updateSpritesInScene();
    }

    registerInput(keys);

    scrollX = yellowSprite.get()->getX() - yellowSprite.get()->getStartX();

    mario_bg.get()->scroll( scrollX, scrollY);

    if(DEBUG)
    {
        if(killables.size() > 0)
        TextStream::instance().setText(std::to_string(killables.size()), 5, 1);
    }

}

void UnfairScene::registerInput(u16 keys)
{
    u32 dy = 0;
    u32 dx = 0;
    u32 currentTime = engine->getTimer()->getTotalMsecs();
    u32 timePassed = currentTime - atTime;
    if (isJumping)
    {
        if (timePassed < 500)
        {
            dy = -2;
        }
        else
        {
            if (yellowSprite.get()->getY() >= GBA_SCREEN_HEIGHT - 48)
            {
                isJumping = false;
                dy = 0;
            }
            else
            {
                dy = 2;
            }
        }
    }

    if (!isJumping)
    //Gravity
    // && !isCollidingWithWalkable() zorgt mss voor een sticky effect als je tegen de zijkant opspringt.
    {
        dy = yellowSprite.get()->getY() < GBA_SCREEN_HEIGHT - 48 ? 2 : 0;
    }

    switch(keys)
    {
        case (KEY_LEFT):
            dx = -1;
            scrollX -= SCROLL_SPEED;
            yellowSprite.get()->setVelocity(dx, dy);
            break;
        case (KEY_LEFT | KEY_UP):
            dx = -1;
            scrollX -= SCROLL_SPEED;
            if(!isJumping)
            performJump();
            yellowSprite.get()->setVelocity(dx, dy);
            break;
        case (KEY_RIGHT):
            dx = 1;
            scrollX += SCROLL_SPEED;
            yellowSprite.get()->setVelocity(dx, dy);
            break;
        case (KEY_RIGHT | KEY_UP):
            dx = 1;
            scrollX += SCROLL_SPEED;
            if(!isJumping)
            performJump();
            yellowSprite.get()->setVelocity(dx, dy);
            break;
        case (KEY_UP):
            if(!isJumping)
            performJump();
            yellowSprite.get()->setVelocity(dx, dy);
            break;
        default:
            dx = 0;
            yellowSprite.get()->setVelocity(dx,dy);
    }


}

void UnfairScene::performJump()
{
    isJumping = true;
    atTime = engine->getTimer()->getTotalMsecs();
}