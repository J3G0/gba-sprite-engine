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
}

void UnfairScene::registerInput(u16 keys)
{
    //TextStream::instance().setText(std::to_string(gerard.get()->getX()), 5 , 1);
    handleProgression();
    if(gerard->getX() > 50)
    {
        //gerard->getSprite()->moveTo(gerard->getX() - 1, gerard->getY());
        scrollX++;
    }

    //background->scroll(scrollX, 0);
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
    int gerardX = gerard->getX() + scrollX;
    ProgressionState state = getProgressionState();
    switch(state)
    {
        case NONE:
            if(gerard->isAlive() && gerardX > 50)
            {
                killables.push_back(std::unique_ptr<FireBall>(new FireBall(50,0, 0, 4, 1)));

                // Set state to next state so no more first state fireballs will spawn
                // https://stackoverflow.com/questions/40979513/changing-enum-to-next-value-c11
                setProgressionState(static_cast<ProgressionState>(state + 1));
            }
            break;

        case STATE1:
            if(gerard->isAlive() && gerardX > 75)
            {
                killables.push_back(std::unique_ptr<FireBall>(new FireBall(65 ,7, 0, 4, 1)));
                setProgressionState(static_cast<ProgressionState>(state + 1));
            }
            break;

        case STATE2:
                if(gerard->isAlive() && gerardX > 150)
                {
                    killables.push_back(std::unique_ptr<FireBall>(new FireBall(0,100, 4, 0, 1)));
                }
            setProgressionState(static_cast<ProgressionState>(state + 1));
            break;

        case STATE3:

            if(gerardX > 460 & gerard->isAlive())
            {
                //load();
                //canTransitionToBoss = true;
            }
            break;
    }

}

void UnfairScene::placeSprites()
{
    flag = std::unique_ptr<Flag>(new Flag(200,20));

    //move to stop compiler from crying

    walkables.push_back(std::move(flag));
    walkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(30, 120)));
    walkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(70, 80)));

    nonWalkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(110, 70)));
    killables.insert(killables.begin(),  std::unique_ptr<Plant>(new Plant(110, 112, 0,0,1)));

    /**
    walkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(150, 70)));
    walkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(190, 60)));
    walkables.push_back(std::unique_ptr<ImaginaryBlock>(new ImaginaryBlock(200, 50)));
     **/
}
