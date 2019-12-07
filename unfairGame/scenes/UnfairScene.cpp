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

    if (currentTime - fireBallTimer >= 250)
    {
        fireBallTimer = currentTime;
        //killables.push_back(std::unique_ptr<Killable>(new Killable(rand() % 200,rand() % 200, 1 + rand() %  2, 1 + rand() % 2)));
        engine.get()->updateSpritesInScene();
    }

    registerInput(keys);

    scrollX = gerard.get()->getSprite()->getX() - gerard.get()->getSprite()->getStartX();

    mario_bg.get()->scroll( scrollX, scrollY);

    if(DEBUG)
    {

    }

}

void UnfairScene::registerInput(u16 keys)
{
    u32 currentTime = engine->getTimer()->getTotalMsecs();
    u32 timePassed = currentTime - getAtTime();
    VECTOR v = gerard->getSprite()->getVelocity();
    int dx = v.x;
    int dy = v.y;
    if (gerard->isJumping())
    {
        if (timePassed < 500)
        {
            dy = -2;
            gerard->setVelocity(dx, dy);
        }
        else
        {
            if (gerard->getSprite()->getY() >= GBA_SCREEN_HEIGHT - 48)
            {
                gerard->setIsJumping(false);
                dy = 0;
            }
            else
            {
                dy = 2;
            }
        }
    }

    if (!gerard->isJumping())
    //Gravity
    // && !isCollidingWithWalkable() zorgt mss voor een sticky effect als je tegen de zijkant opspringt.
    {
        dy = gerard.get()->getSprite()->getY() < GBA_SCREEN_HEIGHT - 48 ? 2 : 0;
    }
    switch(keys)
    {
        case (KEY_LEFT):
            dx = -1;
            gerard->setVelocity(dx, dy);
            scrollX -= SCROLL_SPEED;
            break;
        case (KEY_LEFT | KEY_UP):
            dx = -1;
            scrollX -= SCROLL_SPEED;
            if(!gerard->isJumping())
            {
                gerard->setIsJumping(!gerard->isJumping());
                setAtTime(currentTime);
            }
            gerard->setVelocity(dx, dy);
            break;
        case (KEY_RIGHT):
            dx = 1;
            scrollX += SCROLL_SPEED;
            gerard->setVelocity(dx, dy);
            break;
        case (KEY_RIGHT | KEY_UP):
            dx = 1;
            scrollX += SCROLL_SPEED;
            if(!gerard->isJumping())
            {
                gerard->setIsJumping(!gerard->isJumping());
                setAtTime(currentTime);
            }
            gerard->setVelocity(dx, dy);
            break;
        case (KEY_UP):
            if(!gerard->isJumping())
            {
                gerard->setIsJumping(!gerard->isJumping());
            }
            gerard->setVelocity(dx, dy);
            break;
        default:
            dx = 0;
            gerard->setVelocity(dx, dy);
    }
}

int UnfairScene::getAtTime() const
{
    return atTime;
}

void UnfairScene::setAtTime(int atTime)
{
    UnfairScene::atTime = atTime;
}
