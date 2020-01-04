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
#include "../sprite/sprite_data/combined_data.h"
#include "../sprite/sprite_data/background_data.h"
#include "StartScene.h"
#include "../src/killable/FireBall.h"
#include "../src/killable/Testtube.h"
#include "BossScene.h"
#include "../src/renderable/Flag.h"
#include "../src/renderable/ImaginaryBlock.h"
#include "../src/killable/Plant.h"
#include "../background/Background/Background.h"
#include "../background/Clouds/Cloudbackground.h"
#include "../background/Shared/shared.h"

#include <utility>

#define JUMP_TIME 1000
#define COLLISION_OFFSET 2
#define BACKGROUND_TILE_SIZE 8
#define BACKGROUND_TILES_IN_MAPWIDTH 32

void UnfairScene::load()
{
    basicLoad();
    placeSprites();
    engine->getTimer()->start();
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(shared_background_palette, sizeof(shared_background_palette)));

    clouds = std::unique_ptr<Background>(new Background(0, clouds_tiles, sizeof(clouds_tiles), clouds_map, sizeof(clouds_map)));
    clouds->useMapScreenBlock(3);
    background = std::unique_ptr<Background>(new Background(1, background_tiles, sizeof(background_tiles), background_map, sizeof(background_map)));
    background->useMapScreenBlock(21);

}

void UnfairScene::registerInput(u16 keys)
{
    //TextStream::instance().setText(std::to_string(gerard.get()->getX()), 5 , 1);
    handleProgression();

    //background->scroll(scrollX, 0);

    if(keys == KEY_START)
    {
        gerard->setHealth(0);
        TextStream::instance().clear();
    }

}

ProgressionState UnfairScene::getProgressionState() const
{
    return progressionState;
}

void UnfairScene::setProgressionState(ProgressionState progressionState)
{
    UnfairScene::progressionState = progressionState;
}

void UnfairScene::handleProgression()
{
    int gerardX = gerard->getX();
    ProgressionState state = getProgressionState();
    TextStream::instance().setText(std::to_string(state), 5 , 1);
    switch(state)
    {
        case NONE:
            if(gerard->isAlive() && gerardX > 50)
            {
                killables.push_back(std::unique_ptr<FireBall>(new FireBall(gerardX,0, 0, 4, 1)));

                // Set state to next state so no more first state fireballs will spawn
                // https://stackoverflow.com/questions/40979513/changing-enum-to-next-value-c11
                setProgressionState(static_cast<ProgressionState>(state + 1));
            }
            break;

        case STATE1:
            if(gerard->isAlive() && gerardX > 75)
            {
                killables.push_back(std::unique_ptr<FireBall>(new FireBall(gerardX ,7, 0, 4, 1)));
                setProgressionState(static_cast<ProgressionState>(state + 1));
            }
            break;

        case STATE2:

            if(gerard->isAlive() && gerardX > 120)
            {
                killables.push_back(std::unique_ptr<FireBall>(new FireBall(0,100, 6, 0, 2)));
                setProgressionState(static_cast<ProgressionState>(state + 1));
            }
            break;

        case STATE3:
            if(gerard->isAlive() && gerardX > flag->getX() && gerard->getY() > flag->getY())
            {
                canTransitionToBoss = true;
            }
            break;
    }

}

void UnfairScene::placeSprites()
{
    flag = std::unique_ptr<Flag>(new Flag(170,50));
    plant = std::unique_ptr<Plant>(new Plant(110, 112, 0,0,1));

    //move to stop compiler from crying
    nonWalkables.push_back(std::move(flag));
    walkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(30, 120)));
    walkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(50, 100)));
    walkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(70, 80)));

    nonWalkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(110, 70)));
    walkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(130, 70)));
    walkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(150, 70)));
    killables.push_back(std::move(plant));

}

std::vector<Background *>  UnfairScene::backgrounds()
{
    return { background.get(), clouds.get() };
}
