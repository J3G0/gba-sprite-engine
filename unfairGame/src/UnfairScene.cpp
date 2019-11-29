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
#include<sstream>

#define MAP_OFFSET_Y 8
#define JUMP_TIME 1000
std::vector<Background *> UnfairScene::backgrounds() {
    return { mario_bg.get() };
}

std::vector<Sprite*> UnfairScene::sprites()
{
    return { itsAMeMario.get(), testSprite.get() };
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
            .withLocation(50, 120)
            .buildPtr();

    testSprite = builder
            .withData(megamanTiles, sizeof(megamanTiles))
            .withSize(SIZE_32_32)
            .withLocation(250, 120)
            .buildPtr();


    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg.get()->useMapScreenBlock(16);

    engine->getTimer()->start();
}

void UnfairScene::tick(u16 keys)
{
    u32 posX = itsAMeMario.get()->getX();
    u32 posY = itsAMeMario.get()->getY();

    u32 startLoc = 100;
    u32 posTestY = testSprite.get()->getY();

    TextStream::instance().setText((itsAMeMario->getLocationAsString()), 7, 1);
    TextStream::instance().setText(std::to_string(scrollX), 9, 1);

    if (hasToDoJump)
    {
        performJump();
    }

    switch(keys)
    {
        case (KEY_LEFT):
            if(posX > 0)
                itsAMeMario->flipHorizontally(true);
            scrollX--;
            testSprite.get()->moveTo(startLoc - scrollX, posTestY);
        break;

        case(KEY_LEFT | KEY_UP):
            if(posX > 0)
                scrollX--;
                testSprite.get()->moveTo(startLoc - scrollX, posTestY);
                itsAMeMario->flipHorizontally(true);
            jumpAction();
            break;

        case(KEY_RIGHT | KEY_UP):
            scrollX++;
            testSprite.get()->moveTo(startLoc - scrollX, posTestY);
            itsAMeMario->flipHorizontally(false);
            jumpAction();
            break;

        case KEY_RIGHT:
            scrollX++;
            testSprite.get()->moveTo(startLoc - scrollX, posTestY);
            itsAMeMario->flipHorizontally(false);
            break;

        case KEY_DOWN:
            if(posY < GBA_SCREEN_HEIGHT - 32 - MAP_OFFSET_Y)
            itsAMeMario.get()->moveTo(posX, posY + 1);
            break;

        case KEY_UP:
            //Trigger jump here
            jumpAction();
            break;
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
    u32 posY = itsAMeMario.get()->getY();
    int currentTime = engine->getTimer()->getTotalMsecs();
    int timePassed = currentTime - atTime;
    TextStream::instance().setText(std::to_string(timePassed), 15, 1);

    //up movement
    if(timePassed <= JUMP_TIME / 2)
    {
        itsAMeMario->setVelocity(0, -2);
    }

        //down movement
    else
    {
        isFalling = true;
        itsAMeMario->setVelocity(0, 2);
    }

    //If hit a sprite or hit bottom
    if( (posY == 120 || itsAMeMario.get()->collidesWith(*testSprite)) && isFalling)
    {
        hasToDoJump = false;
        itsAMeMario->setVelocity(0, 0);
        isFalling = false;
    }
}
