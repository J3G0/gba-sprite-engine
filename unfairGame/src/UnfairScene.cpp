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
            .withLocation(50, 50)
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
    if(currentTime - atTime >= 1000)
    {
        atTime = currentTime;
        fireBalls.push_back(createFireball());
    }
    registerInput(keys);

    for(Sprite *s: spriteVector)
    {
        u32 startPosX = s->getStartX();
        u32 posY = s->getY();
        s->moveTo(startPosX - scrollX, posY);
    }
    if(fireBalls.size() > 0)
    {
        u32 posX = fireBalls.at(0).get()->getSprite()->getX();
        u32 posY = fireBalls.at(0).get()->getSprite()->getY();
        std::string text = "X: " + std::to_string(posX) + " Y:" + std::to_string(posY);
        TextStream::instance().setText(text,1,1);
    }
    removeFireBalls();
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
            scrollX--;
            break;
        case (KEY_RIGHT):
            scrollX++;
            break;
    }

}

bool UnfairScene::isCollidingOther()
{
    Sprite *mainCharacter = yellowSprite.get();

    for(Sprite *s: spriteVector)
    {
        if(mainCharacter->collidesWith(*s))
        {
            return true;
        }
    }
    return false;
}

std::unique_ptr<Fireball> UnfairScene::createFireball()
{
    return std::unique_ptr<Fireball>(
            new Fireball(builder
            .withNewStart(50,50)
            .withLocation(50,50)
            .withVelocity(0, 4)
            .buildWithDataOf(*fireBall.get())
            ));
}

void UnfairScene::removeFireBalls()
{
    fireBalls.erase(
            std::remove_if(fireBalls.begin(), fireBalls.end(), [](std::unique_ptr<Fireball> &s) { return s->getSprite()->getY() > 140; }),
            fireBalls.end());
}