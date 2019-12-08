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
#include "../sprite/background_data.h"

#include <stdlib.h>

#define JUMP_TIME 1000
#define DEBUG 1
#define SCROLL_SPEED 1
#define COLLISION_OFFSET 2

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

    for(auto &b: walkables)
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
    gerard->getSprite()->setStayWithinBounds(true);

    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg.get()->useMapScreenBlock(16);
    engine->getTimer()->start();

    walkables.push_back(std::unique_ptr<Renderable>(new Renderable(100, 130, true)));


    scrollX = 8;
}

void UnfairScene::tick(u16 keys)
{
    int currentTime = engine->getTimer()->getTotalMsecs();
    if (currentTime - fireBallTimer >= 5000)
    {
        fireBallTimer = currentTime;
        //killables.push_back(std::unique_ptr<Killable>(new Killable(50,112, 0, 0, 50)));
        removeKillables();
        engine.get()->updateSpritesInScene();
    }

    registerInput(keys);
    if(DEBUG)
    {
        TextStream::instance().setText(std::to_string(getCollidingDirection()), 15 , 1);
    }

    mario_bg.get()->scroll( scrollX, scrollY);

    /**
    if(gerard->getX() > 100)
    {
        gerard->getSprite()->moveTo(gerard->getX() - 1, gerard->getY());
        scrollX++;
    }
     **/
}

void UnfairScene::registerInput(u16 keys)
{
    u32 currentTime = engine->getTimer()->getTotalMsecs();
    u32 timePassed = currentTime - getAtTime();
    int dx = 0;
    int dy = 0;

    if (gerard->isJumping())
    {
        if (timePassed < 500)
        {
            dy = -2;
        }
        else
        {

            if (gerard->getY() >= GBA_SCREEN_HEIGHT - 48 || getCollidingDirection() == UP)
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

    if (!gerard->isJumping() || getCollidingDirection() == UP)
    {
        dy = gerard->getY() < GBA_SCREEN_HEIGHT - 48 ? 2 : 0;
    }

    switch(keys)
    {
        case (KEY_LEFT):
            dx = -1;
            break;
        case (KEY_LEFT | KEY_UP):
            dx = -1;
            if(!gerard->isJumping())
            {
                gerard->setIsJumping(!gerard->isJumping());
                setAtTime(currentTime);
            }
            break;
        case (KEY_RIGHT):
            dx = 1;
            break;
        case (KEY_RIGHT | KEY_UP):
            dx = 1;
            if(!gerard->isJumping())
            {
                gerard->setIsJumping(!gerard->isJumping());
                setAtTime(currentTime);
            }
            break;
        case (KEY_UP):
            dy = -2;
            if(!gerard->isJumping())
            {
                gerard->setIsJumping(!gerard->isJumping());
                setAtTime(currentTime);
            }
            break;
        default:
            dx = 0;
    }
    if(getCollidingDirection() > 0)
    {
        switch(getCollidingDirection())
        {
            case RIGHT:
                dx = keys == KEY_RIGHT ? 1 : 0;
                break;
            case LEFT:
                dx = keys == KEY_LEFT ? -1 : 0;
                break;

            case UP:
                gerard->setIsJumping(false);
                dy = 0;
                break;

            case DOWN:
                gerard->setIsJumping(false);
                break;
        }
    }
    gerard->setCharacterDirection(dx, dy);
    gerard->setVelocity(dx, dy);
}

int UnfairScene::getAtTime() const
{
    return atTime;
}

void UnfairScene::setAtTime(int atTime)
{
    UnfairScene::atTime = atTime;
}

void UnfairScene::removeKillables()
{
    killables.erase(
            std::remove_if(killables.begin(), killables.end(), [](std::unique_ptr<Killable> &s) { return (s->isOffScreen()); }),
            killables.end());
}

Direction UnfairScene::getCollidingDirection()
{
    u32 gerardWidth =  gerard->getSprite()->getWidth();
    u32 gerardX = gerard->getX();
    u32 gerardHeight = gerard->getSprite()->getHeight();
    u32 gerardY = gerard->getY();

    for(auto &b : walkables)
    {
        if (gerard->getSprite()->collidesWith(*b->getSprite()))
        {
            //A tutorial on how to lose sanity

            u32 spriteHeight = b->getSprite()->getHeight();
            u32 spriteWidth = b->getSprite()->getWidth();
            u32 spriteX = b->getX();
            u32 spriteY = b->getY();

            if (gerardX + gerardWidth > spriteX && gerardX + gerardWidth < spriteX + COLLISION_OFFSET && gerardY + gerardHeight > spriteY)
            {
                return LEFT;
            }
            else if (gerardX <= spriteX + spriteWidth && gerardX  + COLLISION_OFFSET> spriteX + spriteWidth  && gerardY + gerardHeight > spriteY)
            {
                return  RIGHT;
            }
        }
    }
    return NOT_MOVING;
}