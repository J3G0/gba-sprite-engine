//
// Created by Sebastiaan on 17/12/2019.
//

#include "GenericScene.h"
#include "../sprite/sprite_data/sprite_data.h"
#include "../sprite/sprite_data/background_data.h"
#include "UnfairScene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <algorithm>

#define JUMP_TIME 1000
#define COLLISION_OFFSET 2
#define BACKGROUND_TILE_SIZE 8
#define BACKGROUND_TILES_IN_MAPWIDTH 32

std::vector<Background *> GenericScene::backgrounds()
{
    return { mario_bg.get() };
}

void GenericScene::load()
{
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_palette, sizeof(bg_palette)));

    gerard = std::unique_ptr<Gerard>(new Gerard(0,100, NOT_MOVING));
    gerard->getSprite()->setStayWithinBounds(true);

    mario_bg = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    mario_bg->useMapScreenBlock(16);
    engine->getTimer()->start();

}

std::vector<Sprite*> GenericScene::sprites()
{
    std::vector<Sprite*> sprites;

    if( gerard->getSprite() != nullptr)
    {
        sprites.push_back(gerard->getSprite());
    }

    for(auto &b: killables)
    {
        sprites.push_back(b->getSprite());
    }

    return sprites;
}

void GenericScene::tick(u16 keys)
{

    Direction d = getCollidingDirection();
    bool onWalkableTile = isOnWalkableTile();
    u32 currentTime = engine->getTimer()->getTotalMsecs();
    u32 timePassed = currentTime - getAtTime();

    VECTOR vel = updateVelocity(d, onWalkableTile, currentTime, timePassed, keys);
    gerard->setCharacterDirection(vel.x, vel.y);
    gerard->setVelocity(vel.x, vel.y);

    updateGerardAnimation();
}

VECTOR GenericScene::updateVelocity(Direction d, bool onWalkableTile, int currentTime, int timePassed, u16 keys)
{
    TextStream::instance().setText(std::to_string(keys),5,1);
    TextStream::instance().setText(std::to_string(gerard->isJumping()),10,1);
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

    u32 gerardX = (gerard->getX() + scrollX + gerard->getSprite()->getWidth() - COLLISION_OFFSET);
    u32 gerardY = gerard->getY() + gerard->getSprite()->getHeight();

    // 8 because one tile is 8x8
    u32 gridX = (gerardX / BACKGROUND_TILE_SIZE);
    u32 gridY = gerardY / BACKGROUND_TILE_SIZE;

    int tileLoc = gridX + (gridY * BACKGROUND_TILES_IN_MAPWIDTH);

    return map[tileLoc];

}

void GenericScene::updateGerardAnimation()
{
    //enum Direction {NOT_MOVING, LEFT, LEFT_UP, UP, RIGHT_UP, RIGHT, RIGHT_DOWN, DOWN, LEFT_DOWN};
    Direction d = gerard->getDirection();

    switch(d)
    {
        case DOWN:
            //Zeker van dit?
            gerard->getSprite()->animateToFrame(10);
            gerard->getSprite()->stopAnimating();
            break;
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

int GenericScene::getAtTime() const
{
    return atTime;
}

void GenericScene::setAtTime(int atTime)
{
    GenericScene::atTime = atTime;
}
