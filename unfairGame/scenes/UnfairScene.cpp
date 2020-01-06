//
// Created by Sebastiaan on 28/11/2019.
//
#include <libgba-sprite-engine/background/text_stream.h>
#include <algorithm>
#include "UnfairScene.h"
#include "../src/killable/FireBall.h"
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

}

void UnfairScene::registerInput(u16 keys)
{
    handleProgression();
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
            if(gerard->isAlive() && gerardX > 65)
            {
                killables.push_back(std::unique_ptr<FireBall>(new FireBall(gerardX ,7, 0, 4, 1)));
                setProgressionState(static_cast<ProgressionState>(state + 1));
            }

            break;

        case STATE2:

            if(gerard->isAlive() && gerardX > 120)
            {
                killables.push_back(std::unique_ptr<FireBall>(new FireBall(0,60, 10, 0, 2)));
                setProgressionState(static_cast<ProgressionState>(state + 1));
            }
            break;

        case STATE3:

            if(gerard->isAlive() && gerardX > 160 && gerard->getY() < 50)
            {
                canTransitionToBoss = true;
            }

/*
 * //WERKT NIET IN DEZE STATE ^^ FF HARDCODED
            if(gerard->isAlive() && (gerardX > flag->getX()) && (gerard->getY() > (flag->getY() + flag.get()->getSprite()->getWidth())))
            {
                canTransitionToBoss = true;
            }
*/
            break;
    }

}

void UnfairScene::placeSprites()
{
    flag = std::unique_ptr<Flag>(new Flag(170,50));
    // Looks more real, but adds to much lag
    //nonWalkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(110, 128)));
    plant = std::unique_ptr<Plant>(new Plant(110, 112, 0,0,3));

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