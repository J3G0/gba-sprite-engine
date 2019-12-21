//
// Created by Sebastiaan on 17/12/2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include "BossScene.h"
#include "../src/killable/FireBall.h"

#define SCIENTIST_MOVE_TICK_TIME 3000

void BossScene::load()
{
    basicLoad();
    scientist = (std::unique_ptr<Scientist>(new Scientist(100, 112)));
    engine->getTimer()->start();
}

void BossScene::registerInput(u16 keys) {
    u32 currentTime = engine->getTimer()->getTotalMsecs();

    short flip = scientist->getIsLeftOfRightOf(*gerard->getSprite());
    flip < 0 ? scientist->getSprite()->flipHorizontally(true) : scientist->getSprite()->flipHorizontally(false);
    if(scientist->hasReachedXDestination())
    {
        if(currentTime - scientistTime > SCIENTIST_MOVE_TICK_TIME)
        {
            scientistTime = currentTime;
            u32 dest = scientist->generateXDestination();
            scientist->setXDestination(dest);
            //This is where we can decide what happens
            short randomEvent = rand() % 3;
            switch(randomEvent)
            {
                case 0:
                    spawnTubeBomb();
                    break;
                case 1:
                    spawnFireBall();
                    break;
                case 2:
                    spawnFireBalls();
                    break;
                default:
                    spawnTubeBomb();
                    break;
            }
        }
    }

    if(!scientist->hasReachedXDestination())
    {
        u32 scientistX = scientist->getX();
        u32 scientistY = scientist->getY();

        //Check where scientist has to move to
        if (scientist->getX() > scientist->getXDestination())
        {
            scientist->getSprite()->moveTo(scientistX - 1, scientistY);
        }
        else
        {
            scientist->getSprite()->moveTo(scientistX + 1, scientistY);
        }
    }


}

void BossScene::spawnTubeBomb()
{
    int dx = gerard->getIsLeftOfRightOf(*scientist->getSprite());
    std::vector<std::unique_ptr <Testtube>> tubes = scientist->tubeBomb(dx);

    for(auto &b : tubes)
    {
        // https://stackoverflow.com/questions/30905487/how-can-i-pass-stdunique-ptr-into-a-function
        killables.push_back(std::move(b));
    }
}

void BossScene::spawnFireBall()
{
    u32 gerardX = gerard->getX();

    //Gerard is on left side of map
    if(gerardX < GBA_SCREEN_WIDTH / 2 )
    {
        //Generate fireball coming from right side of map with a negative dx (going left)
        VECTOR fireballCoords;
        fireballCoords.x = 20;
        fireballCoords.y = 0;

        VECTOR v = gerard->getVectorToHitOtherSprite(fireballCoords);
        killables.push_back(std::unique_ptr<FireBall>(new FireBall(fireballCoords.x, fireballCoords.y, v.x, v.y, 50)));
    }
    //Right side
    else
    {
        //Generate fireball coming from right side of map with a negative dx (going left)
        VECTOR fireballCoords;
        fireballCoords.x = 100;
        fireballCoords.y = 0;

        VECTOR v = gerard->getVectorToHitOtherSprite(fireballCoords);
        killables.push_back(std::unique_ptr<FireBall>(new FireBall(fireballCoords.x, fireballCoords.y, v.x, v.y, 50)));
    }
}

void BossScene::spawnFireBalls()
{
    u32 gerardX = gerard->getX() - 10;
    for(int i = 0; i < 5 ; i++)
    {
        killables.push_back(std::unique_ptr<FireBall>(new FireBall(gerardX + (5 * i) ,5 * i, 0, 4, 20)));
    }
}


std::vector<Sprite*> BossScene::sprites()
{
    spritesVector.clear();

    spritesVector.push_back(scientist->getSprite());

    if( gerard->getSprite() != nullptr)
    {
        spritesVector.push_back(gerard->getSprite());
    }

    for(auto &b: walkables)
    {
        spritesVector.push_back(b->getSprite());
    }

    for(auto &b: killables)
    {
        spritesVector.push_back(b->getSprite());
    }
    return spritesVector;
}