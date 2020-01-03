//
// Created by Sebastiaan on 17/12/2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <algorithm>
#include "BossScene.h"
#include "../src/killable/FireBall.h"
#include "EndScene.h"
#include "../src/sound/Explosion1.h"

#define SCIENTIST_MOVE_TICK_TIME 3000
#define MINE_TICK_RATE 350

void BossScene::load()
{
    basicLoad();
    scientist = (std::unique_ptr<Scientist>(new Scientist(100, 112)));
    healthbarGerard->getSprite()->moveTo(0,0);
    u32 it = 0;
    for(auto &h : healthBarScientist)
    {
        healthBarScientist.push_back(std::unique_ptr<Healthbar>(new Healthbar(-50, -50)));
        u32 healthBarWidth = healthBarScientist.at(it)->getSprite()->getWidth();
        u32 healthBarHeight = healthBarScientist.at(it)->getSprite()->getHeight();
        healthBarScientist.at(it)->getSprite()->moveTo(GBA_SCREEN_WIDTH - healthBarWidth, it * healthBarHeight);
        healthBarScientist.at(it)->getSprite()->animateToFrame(it);
        it++;
    }
    mine = std::unique_ptr<Mine>(new Mine(50,50,2));
    engine->getTimer()->start();
}

void BossScene::registerInput(u16 keys)
{
    TextStream::instance().setText(std::to_string(healthBarScientist.size()), 5 , 1);
    u32 currentTime = engine->getTimer()->getTotalMsecs();
    handleScientistActions(currentTime);
    handleMine(currentTime);
    updateScientistHealthbar();
    u32 gerardX = gerard->getX();
    u32 gerardY = gerard->getY();



    if(keys == KEY_B && !mine->getNeedsUpdate())
    {
        mine->getSprite()->moveTo(min(gerardX - 10,GBA_SCREEN_WIDTH), gerardY + 16);
        mine->setNeedsUpdate(true);

        //explosion sound!
        engine->enqueueSound(Explosion1, Explosion1_bytes);
    }

    if(scientist->getHealth() <= 0 && gerard->isAlive())
    {
        scientist->setCanBeDamaged(false);
        engine->updateSpritesInScene();
        engine->setScene(new EndScene(std::move(engine), std::move(data)));
    }
}

std::vector<Sprite*> BossScene::sprites()
{
    spritesVector.clear();

    spritesVector.push_back(scientist->getSprite());
    spritesVector.push_back(healthbarGerard->getSprite());
    spritesVector.push_back(mine->getSprite());
    spritesVector.push_back(gerard->getSprite());

    for(auto &h: healthBarScientist)
    {
        spritesVector.push_back(h->getSprite());
    }

    for(auto &w: walkables)
    {
        spritesVector.push_back(w->getSprite());
    }

    for(auto &k: killables)
    {
        spritesVector.push_back(k->getSprite());
    }

    return spritesVector;
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
        killables.push_back(std::unique_ptr<FireBall>(new FireBall(fireballCoords.x, fireballCoords.y, v.x, v.y, 1)));
    }
    //Right side
    else
    {
        //Generate fireball coming from right side of map with a negative dx (going left)
        VECTOR fireballCoords;
        fireballCoords.x = 100;
        fireballCoords.y = 0;

        VECTOR v = gerard->getVectorToHitOtherSprite(fireballCoords);
        killables.push_back(std::unique_ptr<FireBall>(new FireBall(fireballCoords.x, fireballCoords.y, v.x, v.y, 1)));
    }
}

void BossScene::spawnFireBalls()
{
    u32 gerardX = gerard->getX() - 10;
    for(int i = 0; i < 5 ; i++)
    {
        killables.push_back(std::unique_ptr<FireBall>(new FireBall(gerardX + (5 * i) ,9 * i, 0, 4, 1)));
    }
}

void BossScene::handleScientistActions(u32 currentTime)
{
    short flip = scientist->getIsLeftOfRightOf(*gerard->getSprite());
    flip < 0 ? scientist->getSprite()->flipHorizontally(true) : scientist->getSprite()->flipHorizontally(false);



    if(scientist->hasReachedXDestination())
    {
        if(currentTime - scientist->getScientistTime() > SCIENTIST_MOVE_TICK_TIME)
        {
            scientist->setScientistTime(currentTime);
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

void BossScene::handleMine(u32 currentTime)
{
    if (currentTime - mine->getMineTickTime() > MINE_TICK_RATE )
    {
        if(mine->getNeedsUpdate())
        {
            mine->setMineTickTime(currentTime);
            mine->tickMine();
            updateMine();
        }
    }

    if(mine->getCurrentFrame() > 3)
    {
        bool hit = isMineHittingScientist();
        if (hit && !mine->hasDamaged())
        {
            u32 currentScientistHealth = scientist->getHealth();
            u32 mineDamage = mine->getDmg();
            if(scientist->getCanBeDamaged())
            {
                scientist->setHealth(currentScientistHealth - mineDamage);
                mine->setDamaged(true);
            }
        }
    }
}

void BossScene::updateMine()
{
    if(mine->hasDamaged())
    {
        mine->resetMine();
    }
}

bool BossScene::isMineHittingScientist()
{

    u32 mineX = mine->getSprite()->getX();
    u32 mineExplosionRadius = mine->getExplosionRadius();
    u32 scientistX = scientist->getSprite()->getX();
    bool inRange = scientistX > mineX - mineExplosionRadius && scientistX < mineX + mineExplosionRadius;

    return inRange;
}

void BossScene::updateScientistHealthbar()
{
    u32 scientistHealth = scientist->getHealth();

    //Modulo for scientist health
    // Returns 1 when health is 4 - 6
    // Returns 0 when health is 0 - 3;
    u32 scientistHealthMod = scientistHealth % 3;

    if(scientistHealth < 4)
    {
        healthBarScientist.at(1)->getSprite()->animateToFrame(3);
    }

    switch(scientistHealth)
    {
        case 0:
                 healthBarScientist.at(0)->getSprite()->animateToFrame(3);
            break;
        case 1:
                 healthBarScientist.at(0)->getSprite()->animateToFrame(2);
            break;

        case 2:
                 healthBarScientist.at(0)->getSprite()->animateToFrame(1);
            break;
        case 3:
                 healthBarScientist.at(0)->getSprite()->animateToFrame(0);
            break;

        case 4:
                healthBarScientist.at(1)->getSprite()->animateToFrame(2);
            break;

        case 5:
                healthBarScientist.at(1)->getSprite()->animateToFrame(1);
            break;

        case 6:
                healthBarScientist.at(1)->getSprite()->animateToFrame(0);
            break;
    }
}