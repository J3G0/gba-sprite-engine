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
    sprites.push_back(gerard.get()->getSprite());

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


    gerard = std::unique_ptr<Gerard>(new Gerard(0,100, NOT_MOVING));

    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg.get()->useMapScreenBlock(16);
    engine->getTimer()->start();
}

void UnfairScene::tick(u16 keys)
{
    u32 mainX = gerard.get()->getSprite()->getX() + gerard.get()->getSprite()->getWidth();
    u32 mainY = gerard.get()->getSprite()->getY();

    int currentTime = engine->getTimer()->getTotalMsecs();

    if (currentTime - fireBallTimer >= 10000)
    {
        fireBallTimer = currentTime;
        killables.push_back(std::unique_ptr<Killable>(new Killable(rand() % 200,rand() % 200)));
        engine.get()->updateSpritesInScene();
    }

    registerInput(keys);

    scrollX = gerard.get()->getSprite()->getX() - gerard.get()->getSprite()->getStartX();

    mario_bg.get()->scroll( scrollX, scrollY);

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
            if (gerard.get()->getSprite()->getY() >= GBA_SCREEN_HEIGHT - 48)
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
        dy = gerard.get()->getSprite()->getY() < GBA_SCREEN_HEIGHT - 48 ? 2 : 0;
    }

    switch(keys)
    {
        case (KEY_LEFT):
            dx = -1;
            scrollX -= SCROLL_SPEED;
            gerard.get()->getSprite()->setVelocity(dx, dy);
            break;
        case (KEY_LEFT | KEY_UP):
            dx = -1;
            scrollX -= SCROLL_SPEED;
            if(!isJumping)
            performJump();
            gerard.get()->getSprite()->setVelocity(dx, dy);
            break;
        case (KEY_RIGHT):
            dx = 1;
            scrollX += SCROLL_SPEED;
            gerard.get()->getSprite()->setVelocity(dx, dy);
            break;
        case (KEY_RIGHT | KEY_UP):
            dx = 1;
            scrollX += SCROLL_SPEED;
            if(!isJumping)
            performJump();
            gerard.get()->getSprite()->setVelocity(dx, dy);
            break;
        case (KEY_UP):
            if(!isJumping)
            performJump();
            gerard.get()->getSprite()->setVelocity(dx, dy);
            break;
        default:
            dx = 0;
            gerard.get()->getSprite()->setVelocity(dx, dy);
    }
}

void UnfairScene::performJump()
{
    isJumping = true;
    atTime = engine->getTimer()->getTotalMsecs();
}