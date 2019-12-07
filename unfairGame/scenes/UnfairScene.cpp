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
#include "../src/Fireball.h"
#include <stdlib.h>

#define JUMP_TIME 1000
#define DEBUG 1
#define SCROLL_SPEED 1

std::vector<Background *> UnfairScene::backgrounds() {
    return { mario_bg.get() };
}

std::vector<Sprite*> UnfairScene::sprites()
{
    std::vector<Sprite*> sprites;
    spriteVector.clear();
    walkableSpriteVector.clear();
    nonWalkableSpriteVector.clear();

    sprites.push_back(redSprite.get());
    sprites.push_back(redSprite_nonWalkable.get());

    for (auto& b : walkableSpriteVector)
    {
        sprites.push_back(b);
    }

    spriteVector.push_back(fireBall.get());
    walkableSpriteVector.push_back(redSprite.get());
    walkableSpriteVector.push_back(redSprite_nonWalkable.get());
    sprites.push_back(yellowSprite.get());

    for (auto& b : fireBalls)
    {
        sprites.push_back(b->getSprite());
        spriteVector.push_back(b->getSprite());
    }

    for (Sprite *s: spriteVector)
    {
        sprites.push_back(s);
    }

    for (Sprite *s: walkableSpriteVector)
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

    redSprite_nonWalkable = builder
            .withData(red_tempTiles, sizeof(red_tempTiles))
            .withSize(SIZE_32_32)
            .withLocation(180, GBA_SCREEN_HEIGHT - 60)
            .buildPtr();

    fireBall = builder
            .withData(fireballTiles, sizeof(fireballTiles))
            .withLocation(250, 50)
            .withSize(SIZE_8_8)
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
    int howManyBalls = fireBalls.size();
    removeFireBalls();

    if (currentTime - fireBallTimer >= 500)
    {
        fireBallTimer = currentTime;
       // fireBalls.push_back(createFireball(200, GBA_SCREEN_HEIGHT - 24, -2, 0));
    }

    if(mainX == 100 || mainX == 150)
    {
       // fireBalls.push_back(createFireball(mainX, 0, 0, 2));
    }

    registerInput(keys);

    if (howManyBalls != fireBalls.size())
    {
        engine.get()->updateSpritesInScene();
    }

    for (auto &b : fireBalls)
    {
        if (yellowSprite.get()->collidesWith(*b.get()->getSprite()))
        {
            VECTOR v = b->getSprite()->getVelocity();
            b.get()->getSprite()->setVelocity(-v.x,-v.y);
        }
        b->tick();
    }
    scrollX = yellowSprite.get()->getX() - yellowSprite.get()->getStartX();


    for(auto &b: walkableSpriteVector)
    {
        u32 startX = b->getStartX();
        u32 startY = b->getStartY();
        b->moveTo(startX - scrollX, startY);
    }
    mario_bg.get()->scroll( scrollX, scrollY);

    if(DEBUG)
    {
        TextStream::instance().setText(yellowSprite->getLocationAsString(), 5, 1);
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
        if (isCollidingWithWalkable())
        {
            isJumping = false;
        }

        if (timePassed < 500)
        {
            dy = -2;
        }
        else
        {
            if (yellowSprite.get()->getY() >= GBA_SCREEN_HEIGHT - 48 || isCollidingWithWalkable())
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

    if (!isJumping && !isCollidingWithWalkable())
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

std::unique_ptr<Fireball> UnfairScene::createFireball(u32 x , u32 y, u32 velX, u32 velY)
{
    return std::unique_ptr<Fireball>(
            new Fireball(builder
             .withNewStart(x, y)
             .withLocation(x, y)
             .withVelocity(velX, velY)
             .buildWithDataOf(*fireBall.get())
            ));
}

void UnfairScene::removeFireBalls()
{
    fireBalls.erase(
            std::remove_if(fireBalls.begin(), fireBalls.end(), [this](std::unique_ptr<Fireball> &s)
            {
                return (s->getSprite()->getY() > 160 || s->isOffScreen());
            }
            ),
            fireBalls.end());
}

void UnfairScene::performJump()
{
    isJumping = true;
    atTime = engine->getTimer()->getTotalMsecs();
}

bool UnfairScene::isCollidingWithWalkable() {
    Sprite *mainChar = yellowSprite.get();

    for(Sprite *walkable : walkableSpriteVector)
    {
        if(mainChar->collidesWith(*walkable))
        {
            return true;
        }
    }
    return false;
}