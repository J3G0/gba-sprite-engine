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
#include "../sprite/background_data.h"
#include "StartScene.h"

#include <stdlib.h>
#include <sstream>

#define JUMP_TIME 1000
#define DEBUG 1
#define SCROLL_SPEED 1
#define COLLISION_OFFSET 2
#define BACKGROUND_TILE_SIZE 8
#define BACKGROUND_TILES_IN_MAPWIDTH 32

std::vector<Background *> UnfairScene::backgrounds()
{
    return { mario_bg.get() };
}

std::vector<Sprite*> UnfairScene::sprites()
{
    std::vector<Sprite*> sprites;
    sprites.push_back(gerard.get()->getSprite());

    for(auto &b: walkables)
    {
        if(b->getSprite() != nullptr)
        {
            sprites.push_back(b->getSprite());
        }
    }

    for(auto &b: nonWalkables)
    {
        if(b->getSprite() != nullptr)
        {
            sprites.push_back(b->getSprite());
        }
    }

    for(auto &b: killables)
    {
        if(b->getSprite() != nullptr)
        {
            sprites.push_back(b->getSprite());
        }
    }

    return sprites;
}

void UnfairScene::load()
{
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_palette, sizeof(bg_palette)));

    gerard = std::unique_ptr<Gerard>(new Gerard(0,100, NOT_MOVING));
    gerard->getSprite()->setStayWithinBounds(true);

    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg.get()->useMapScreenBlock(16);
    engine->getTimer()->start();

    walkables.push_back(std::unique_ptr<Renderable>(new Renderable(70, 130, true)));

    nonWalkables.push_back(std::unique_ptr<Renderable>(new Renderable(110, 100, true)));
}

void UnfairScene::tick(u16 keys)
{
    int currentTime = engine->getTimer()->getTotalMsecs();
    int gerardX = gerard->getX();
    UnfairSceneState state = getGameState();
    switch(state)
    {
        case FIREBALL1:
            if(gerardX > 50)
            {
                killables.push_back(std::unique_ptr<Killable>(new Killable(50,0, 0, 2, 100)));
                engine.get()->updateSpritesInScene();
                // Set state to next state so no more first state fireballs will spawn
                // https://stackoverflow.com/questions/40979513/changing-enum-to-next-value-c11
                setGameState(static_cast<UnfairSceneState>(state + 1));
            }
            break;
    }
    updateSprites();
    moveSprites();
    checkCollisionWithSprites();
    registerInput(keys);
    updateGerardAnimation();

    if(DEBUG)
    {
        TextStream::instance().setText(std::to_string(data.getAmountOfDeaths()), 5 , 1);
        TextStream::instance().setText(std::to_string(gerard->getHealth()), 5 , 1);
    }

    mario_bg.get()->scroll( scrollX, scrollY);


    if(gerard->getX() > 100)
    {
        gerard->getSprite()->moveTo(gerard->getX() - 1, gerard->getY());
        scrollX++;
    }
}

void UnfairScene::registerInput(u16 keys)
{
    Direction d = getCollidingDirection();
    bool onWalkableTile = isOnWalkableTile();
    u32 currentTime = engine->getTimer()->getTotalMsecs();
    u32 timePassed = currentTime - getAtTime();
    VECTOR vel = updateVelocity(d, onWalkableTile, currentTime, timePassed, keys);
    gerard->setCharacterDirection(vel.x, vel.y);
    gerard->setVelocity(vel.x, vel.y);

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
            data.increaseAmountOfDeaths();
            engine->setScene(new StartScene(engine, data));
        }
    }
}

int UnfairScene::getAtTime() const
{
    return atTime;
}

void UnfairScene::setAtTime(int atTime)
{
    UnfairScene::atTime = atTime;
}

void UnfairScene::updateSprites()
{
    killables.erase(
            std::remove_if(killables.begin(), killables.end(), [](std::unique_ptr<Killable> &s) { return (s->isOffScreen()); }),
            killables.end());
}

Direction UnfairScene::getCollidingDirection()
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

void UnfairScene::moveSprites()
{
    // V: Waarom crashed dit?
    // A: Oplossing voor crashen : nieuwe lijst aanmaken aan daarin dingen verwijderen, die dan kopieren naar originele lijst.
    for (auto &b : walkables)
    {
        u32 startX = b->getStartX();
        u32 startY = b->getStartY();

        b->getSprite()->moveTo(startX - scrollX, startY);
        // Source https://en.cppreference.com/w/cpp/algorithm/remove
        // Waarom crashed dit?
        //walkables.erase(std::remove_if(walkables.begin(),walkables.end(),[](std::unique_ptr<Renderable> &b){return b->isOffScreen();}),walkables.end());
    }

    for (auto &b : nonWalkables)
    {
        u32 startX = b->getStartX();
        u32 startY = b->getStartY();

        b->getSprite()->moveTo(startX - scrollX, startY);
        // Source https://en.cppreference.com/w/cpp/algorithm/remove
        //nonWalkables.erase(std::remove_if(nonWalkables.begin(),nonWalkables.end(),[this](std::unique_ptr<Renderable> &b){return b->getSprite()->collidesWith(*gerard->getSprite());}),nonWalkables.end());
    }
}

UnfairSceneState UnfairScene::getGameState() const
{
    return gameState;
}

void UnfairScene::setGameState(UnfairSceneState gameState)
{
    UnfairScene::gameState = gameState;
}

void UnfairScene::updateGerardAnimation()
{
    //enum Direction {NOT_MOVING, LEFT, LEFT_UP, UP, RIGHT_UP, RIGHT, RIGHT_DOWN, DOWN, LEFT_DOWN};
    Direction d = gerard->getDirection();

    if(!gerard->isAlive())
    {
        return;
    }

    switch(d)
    {
        case DOWN:
        case RIGHT_DOWN:
        case LEFT_DOWN:
        case NOT_MOVING:
            gerard->getSprite()->animateToFrame(8);
            gerard->getSprite()->stopAnimating();
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

//Original idea by Jelle and Michiel
//Instead of checking if on sprite for floor, check for background data!

int UnfairScene::getBackgroundTileBlock()
{

    u32 gerardX = (gerard->getX() + scrollX + gerard->getSprite()->getWidth() - COLLISION_OFFSET);
    u32 gerardY = gerard->getY() + gerard->getSprite()->getHeight();

    // 8 because one tile is 8x8
    u32 gridX = (gerardX / BACKGROUND_TILE_SIZE);
    u32 gridY = gerardY / BACKGROUND_TILE_SIZE;

    int tileLoc = gridX + (gridY * BACKGROUND_TILES_IN_MAPWIDTH);

    return map[tileLoc];

}

bool UnfairScene::isOnWalkableTile()
{
    int tile = getBackgroundTileBlock();

    // https://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
    return std::find(walkableBackgroundTiles.begin(), walkableBackgroundTiles.end(), tile) !=
           walkableBackgroundTiles.end();
}
void UnfairScene::checkCollisionWithSprites()
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

VECTOR UnfairScene::updateVelocity(Direction d, bool onWalkableTile, int currentTime, int timePassed, u16 keys)
{
    int dx = 0;
    int dy = 0;
    if (gerard->isJumping())
    {
        if( timePassed < 0.25 * JUMP_TIME)
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
            else
            {
                dy = 2;
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
