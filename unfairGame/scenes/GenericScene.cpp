//
// Created by Sebastiaan on 17/12/2019.
//

#include "GenericScene.h"
#include "../background/Background/Background.h"
#include "../background/Clouds/Cloudbackground.h"
#include "../background/Shared/shared.h"

#include "UnfairScene.h"
#include "StartScene.h"
#include "../src/killable/FireBall.h"
#include "BossScene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <algorithm>
#include "../src/sound/boooo.h"
#include "../src/sound/HAHA.h"

#define JUMP_TIME 1000
#define COLLISION_OFFSET 2
#define BACKGROUND_TILE_SIZE 8
#define BACKGROUND_TILES_IN_MAPWIDTH 32


std::vector<Background *> GenericScene::backgrounds()
{
    return { background.get() };
}

void GenericScene::load()
{
    basicLoad();
    engine->getTimer()->start();
}

std::vector<Sprite*> GenericScene::sprites()
{
    spritesVector.clear();

    if( gerard->getSprite() != nullptr)
    {
        spritesVector.push_back(gerard->getSprite());
    }

    if(healthbarGerard->getSprite() != nullptr)
    {
        spritesVector.push_back(healthbarGerard->getSprite());
    }

    for(auto &h : healthBarScientist)
    {
        spritesVector.push_back(h->getSprite());
    }

    for(auto &w: walkables)
    {
        spritesVector.push_back(w->getSprite());
    }

    for(auto &w: nonWalkables)
    {
        spritesVector.push_back(w->getSprite());
    }

    for(auto &k: killables)
    {
        spritesVector.push_back(k->getSprite());
    }

    return spritesVector;
}

void GenericScene::tick(u16 keys)
{

    killablesSize = killables.size();
    walkablesSize = walkables.size();
    nonWalkablesSize = nonWalkables.size();
    Direction d = getCollidingDirection();
    bool onWalkableTile = isOnWalkableTile();
    TextStream::instance().setText(std::to_string(onWalkableTile),1,5);

    u32 currentTime = engine->getTimer()->getTotalMsecs();
    u32 timePassed = currentTime - getAtTime();
    VECTOR vel = updateVelocity(d, onWalkableTile, currentTime, timePassed, keys);
    gerard->setCharacterDirection(vel.x, vel.y);
    gerard->setVelocity(vel.x, vel.y);
    updateSprites();
    if(killables.size() > 0)
    {
        checkCollisionWithSprites();
    }
    registerInput(keys);
    updateHealthbar();
    //todo: update this moveSprites();

    if(killablesSize != killables.size())
    {
        engine->updateSpritesInScene();
    }


    if(gerard->isAlive())
    {
        updateGerardAnimation();
    }

    if(gerard->getHealth() <= 0 && gerard->isAlive())
    {
        //Need a way to display death before transitioning to scene, work with engine timer
        gerard->getSprite()->animateToFrame(10);
        gerard->setIsAlive(false);
        deathTime = currentTime;
        gerard->setVelocity(0, -1);
    }

    if(!gerard->isAlive())
    {
        if(currentTime - deathTime > 1500)
        {
            load();
            data->increaseAmountOfDeaths();
            canTransitionToBoss = false;
            engine->setScene(new StartScene(engine, data));
        }
    }

    else if(canTransitionToBoss && gerard->isAlive())
    {
        load();
        engine->setScene(new BossScene(engine, data));
    }



}

VECTOR GenericScene::updateVelocity(Direction d, bool onWalkableTile, int currentTime, int timePassed, u16 keys)
{
        int dx = 0;
        int dy = 0;
        if (gerard->isJumping())
        {
            if( timePassed < 0.10 * JUMP_TIME)
            {
                dy = -3;
            }
            else if ( timePassed < 0.25 * JUMP_TIME)
            {
                dy = -2;
            }

            else if (timePassed < 0.5 * JUMP_TIME)
            {
                dy = -1;
            }
            else
            {
                if (onWalkableTile || d == UP)
                {
                    gerard->setIsJumping(false);
                    dy = 0;
                }
                else if (timePassed < 0.15 * JUMP_TIME)
                {
                    dy = 1;
                }
                else if (timePassed < 0.25 * JUMP_TIME)
                {
                    dy = 2;
                }
                else if (timePassed < 0.35 * JUMP_TIME)
                {
                    dy = 3;
                }
                else
                {
                    dy = 4;
                }
            }
        }

        if (!gerard->isJumping() || d == UP)
        {
            dy =  onWalkableTile ? 0 : 2;
        }

        switch(keys)
        {
            case (KEY_LEFT | KEY_DOWN):
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
            case (KEY_RIGHT | KEY_DOWN):
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
                if(!gerard->isJumping())
                {
                    dy = -2;
                    gerard->setIsJumping(!gerard->isJumping());
                    setAtTime(currentTime);
                }
                break;
            case (KEY_A):
                if(!gerard->isJumping())
                {
                    dy = -2;
                    gerard->setIsJumping(!gerard->isJumping());
                    setAtTime(currentTime);
                }
                break;
            case (KEY_RIGHT | KEY_A):
                dx = 1;
                if(!gerard->isJumping())
                {
                    gerard->setIsJumping(!gerard->isJumping());
                    setAtTime(currentTime);
                }
                break;
            case (KEY_LEFT | KEY_A):
                dx = -1;
                if(!gerard->isJumping())
                {
                    gerard->setIsJumping(!gerard->isJumping());
                    setAtTime(currentTime);
                }
                break;


            default:
                dx = 0;
        }

        if(d > 0)
        {
            switch(d)
            {
                case RIGHT:
                    dx = keys == KEY_RIGHT ? 1 : 0;
                    break;

                case LEFT:
                    dx = keys == KEY_LEFT ? -1 : 0;
                    break;

                case UP:
                    dy = 0;
                    gerard->setIsJumping(false);
                    if(!gerard->isJumping() && ( (keys == KEY_UP) || (keys == (KEY_RIGHT | KEY_UP)) || (keys == (KEY_LEFT | KEY_UP))))
                    {
                        dy = -2;
                        gerard->setIsJumping(!gerard->isJumping());
                        setAtTime(currentTime);
                    }
                    break;

                case DOWN:
                    dy = 2;
                    gerard->setIsJumping(false);
                    break;
            }
        }

        VECTOR vel;
        vel.x = dx;
        vel.y = dy;

        return vel;
}

Direction GenericScene::getCollidingDirection()
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

            if (gerardX + gerardWidth > spriteX && gerardX + gerardWidth < spriteX + COLLISION_OFFSET && gerardY + gerardHeight >= spriteY)
            {
                return LEFT;
            }
            else if (gerardX <= spriteX + spriteWidth && gerardX  + COLLISION_OFFSET> spriteX + spriteWidth  && gerardY + gerardHeight >= spriteY)
            {
                return  RIGHT;
            }

            else if ( gerardX  + 4 * COLLISION_OFFSET >= spriteX  && gerardY + gerardHeight >= spriteY && gerardY < spriteY)
            {
                return UP;
            }

            else if ( gerardX  + 4 * COLLISION_OFFSET >= spriteX  && gerardY <= spriteY + spriteHeight)
            {
                return DOWN;
            }
        }
    }
    return NOT_MOVING;
}

bool GenericScene::isOnWalkableTile()
{
    int tile = getBackgroundTileBlock();

    // https://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
    return std::find(walkableBackgroundTiles.begin(), walkableBackgroundTiles.end(), tile) !=
           walkableBackgroundTiles.end();
}

int GenericScene::getBackgroundTileBlock()
{

    u32 gerardX = (gerard->getX() + gerard->getSprite()->getWidth() - COLLISION_OFFSET);
    u32 gerardY = gerard->getY() + gerard->getSprite()->getHeight();

    // 8 because one tile is 8x8
    u32 gridX = (gerardX / BACKGROUND_TILE_SIZE);
    u32 gridY = gerardY / BACKGROUND_TILE_SIZE;

    int tileLoc = gridX + (gridY * BACKGROUND_TILES_IN_MAPWIDTH);

    return background_map[tileLoc];

}

void GenericScene::updateGerardAnimation()
{
    //enum Direction {NOT_MOVING, LEFT, LEFT_UP, UP, RIGHT_UP, RIGHT, RIGHT_DOWN, DOWN, LEFT_DOWN};
    Direction d = gerard->getDirection();

    switch(d)
    {
        case DOWN:
            // Zeker van dit?
            // Zorgt ervoor dat Gerard 'dood' is als hij aan het vallen is?

            // gerard->getSprite()->animateToFrame(10);
            // gerard->getSprite()->stopAnimating();
            // break;
        case RIGHT_DOWN:
        case LEFT_DOWN:
        case NOT_MOVING:
            gerard->getSprite()->animateToFrame(8);
            gerard->getSprite()->stopAnimating();
            gerard->getSprite()->flipHorizontally(false);
            break;
        case UP:
        case LEFT_UP:
        case RIGHT_UP:
            gerard->getSprite()->animateToFrame(9);
            gerard->getSprite()->stopAnimating();
            break;
        case LEFT:
            gerard->getSprite()->makeAnimated(8, 10);
            gerard->getSprite()->flipHorizontally(true);
            break;
        case RIGHT:
            gerard->getSprite()->makeAnimated(8, 10);
            gerard->getSprite()->flipHorizontally(false);
            break;
    }
}

void GenericScene::registerInput(u16 keys)
{
    // override  in subclass
}

void GenericScene::updateSprites()
{
    killables.erase(
            std::remove_if(killables.begin(), killables.end(), [](std::unique_ptr<Killable> &s) { return (s->isOffScreen() || s->hasDamaged() ); }),
            killables.end());
}

void GenericScene::moveSprites()
{
    // V: Waarom crashed dit?
    // A: Oplossing voor crashen : nieuwe lijst aanmaken aan daarin dingen verwijderen, die dan kopieren naar originele lijst.
    for (auto &b : walkables)
    {
        u32 x = b->getX();
        u32 y = b->getY();

        b->getSprite()->moveTo(x - scrollX, y);
        // Source https://en.cppreference.com/w/cpp/algorithm/remove
        // Waarom crashed dit?
        walkables.erase(std::remove_if(walkables.begin(),walkables.end(),[](std::unique_ptr<Renderable> &b){return b->isOffScreen();}),walkables.end());
        continue;
    }

    for (auto &b : killables)
    {
        u32 x = b->getX();
        u32 y = b->getY();

        b->getSprite()->moveTo(x - scrollX, y);
        // Source https://en.cppreference.com/w/cpp/algorithm/remove
        killables.erase(std::remove_if(killables.begin(),killables.end(),[this](std::unique_ptr<Killable> &b){return b->getSprite()->collidesWith(*gerard->getSprite());}),killables.end());
        continue;
    }
}

void GenericScene::checkCollisionWithSprites()
{

    for (auto &b : killables)
    {
        if(b->getSprite()->collidesWith(*gerard->getSprite()) && !b->hasDamaged())
        {
            u32 killableDamage = b->getDmg();
            u32 currentHealth = gerard->getHealth();
            gerard->setHealth(currentHealth - killableDamage);
            b->setDamaged(true);
        }
    }
}

void GenericScene::basicLoad()
{
    engine->disableText();
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(shared_background_palette, sizeof(shared_background_palette)));

    gerard = std::unique_ptr<Gerard>(new Gerard(0,100, NOT_MOVING));
    gerard->getSprite()->setStayWithinBounds(true);

    healthbarGerard = std::unique_ptr<Healthbar>(new Healthbar(0,0));
    healthbarGerard->getSprite()->animateToFrame(0);

    for (int i = 0; i < 2; i++)
    {
        healthBarScientist.push_back(std::unique_ptr<Healthbar>(new Healthbar(-50, -50)));
    }

    background = std::unique_ptr<Background>(new Background(1, background_tiles, sizeof(background_tiles), background_map, sizeof(background_map)));
    background->useMapScreenBlock(2);
    background->scroll(0,0);
}

void GenericScene::updateHealthbar()
{
    // 4 Frames
    // Frame 0: Full health

    // Frame 3: Zero health
    int healthGerard = gerard->getHealth();
    int healthTickGerard =  min(4 - healthGerard, 3);
    //TextStream::instance().setText(std::to_string(healthTick), 5 , 1);
    healthbarGerard->getSprite()->animateToFrame(healthTickGerard);

}