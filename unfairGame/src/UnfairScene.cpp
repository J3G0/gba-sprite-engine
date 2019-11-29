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
#include<sstream>

#define JUMP_TIME 1000
std::vector<Background *> UnfairScene::backgrounds() {
    return { mario_bg.get() };
}

std::vector<Sprite*> UnfairScene::sprites()
{
    return { redSprite.get(), yellowSprite.get() };
}

void UnfairScene::load()
{
    engine.get()->disableText();
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_palette, sizeof(bg_palette)));

    SpriteBuilder<Sprite> builder;

    yellowSprite = builder
            .withData(yellow_tempTiles, sizeof(yellow_tempTiles))
            .withSize(SIZE_32_32)
            .withLocation(50, GBA_SCREEN_HEIGHT - 48)
            .buildPtr();

    redSprite = builder
            .withData(red_tempTiles, sizeof(red_tempTiles))
            .withSize(SIZE_32_32)
            .withLocation(100, 50)
            .buildPtr();


    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg.get()->useMapScreenBlock(16);

    engine->getTimer()->start();
}

void UnfairScene::tick(u16 keys)
{
    handleMovement(keys);
    if (hasToDoJump)
    {
        performJump();
    }

    mario_bg.get()->scroll(scrollX, scrollY);
}

void UnfairScene::jumpAction()
{
    if(!hasToDoJump)
    {
        hasToDoJump = true;
        atTime = engine->getTimer()->getTotalMsecs();
    }
}

void UnfairScene::performJump()
{
    u32 posY = yellowSprite.get()->getY();
    int currentTime = engine->getTimer()->getTotalMsecs();
    int timePassed = currentTime - atTime;
    TextStream::instance().setText(std::to_string(timePassed), 15, 1);

    //up movement
    if(timePassed <= JUMP_TIME / 2)
    {
        yellowSprite->setVelocity(0, -2);
    }

    //down movement
    else
    {
        isFalling = true;
        yellowSprite->setVelocity(0, 2);
    }

    //If hit a sprite or hit bottom
    if((posY >= GBA_SCREEN_HEIGHT - 48 || yellowSprite.get()->collidesWith(*redSprite)) && isFalling)
    {
        hasToDoJump = false;
        yellowSprite->setVelocity(0, 0);
        isFalling = false;
    }
}

void UnfairScene::handleMovement(u16 keys)
{
    handleKeys(keys);


}

void UnfairScene::handleKeys(u16 keys)
{
    u32 posX = yellowSprite.get()->getX();
    u32 posY = yellowSprite.get()->getY();
    u32 startLoc = 100;
    u32 posTestY = redSprite.get()->getY();
    if(!hasToDoJump && posY <= GBA_SCREEN_HEIGHT - 48 && !yellowSprite.get()->collidesWith(*redSprite))
    {
        yellowSprite.get()->moveTo(posX, posY + 1);
    }
    switch(keys)
    {
        case (KEY_LEFT):
            if(posX > 0)
                yellowSprite->flipHorizontally(true);
            scrollX--;
            redSprite.get()->moveTo(startLoc - scrollX, posTestY);
            break;

        case(KEY_LEFT | KEY_UP):
            if(posX > 0)
                scrollX--;
            redSprite.get()->moveTo(startLoc - scrollX, posTestY);
            yellowSprite->flipHorizontally(true);
            jumpAction();
            break;

        case(KEY_RIGHT | KEY_UP):
            scrollX++;
            redSprite.get()->moveTo(startLoc - scrollX, posTestY);
            yellowSprite->flipHorizontally(false);
            jumpAction();
            break;

        case KEY_RIGHT:
            scrollX++;
            redSprite.get()->moveTo(startLoc - scrollX, posTestY);
            yellowSprite->flipHorizontally(false);
            break;

        case KEY_UP:
            //Trigger jump here
            jumpAction();
            break;
    }
}
