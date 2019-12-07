//
// Created by Sebastiaan on 7/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GERARD_H
#define GBA_SPRITE_ENGINE_PROJECT_GERARD_H

#include "../src/Renderable.h"
enum Direction {NOT_MOVING, LEFT, RIGHT, UP, DOWN};


class Gerard : public Renderable
{
private:
    Direction direction;
    int xLocation;
    int yLocation;
    bool isAlive = true;
    bool isJumping = false;

public:
    Gerard(int xLocation, int yLocation, Direction direction);
    Direction getDirection() { return direction; }
    void setDirection(Direction newDirection);
    Sprite* getSprite() { return Renderable::getSprite(); }
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GERARD_H
