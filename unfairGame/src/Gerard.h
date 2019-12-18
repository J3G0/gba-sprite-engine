//
// Created by Sebastiaan on 7/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GERARD_H
#define GBA_SPRITE_ENGINE_PROJECT_GERARD_H

#include "../src/Renderable.h"
#include "libgba-sprite-engine/timer.h"
enum Direction {NOT_MOVING, LEFT, LEFT_UP, UP, RIGHT_UP, RIGHT, RIGHT_DOWN, DOWN, LEFT_DOWN};

class Gerard : public Renderable
{
private:
    Direction direction;
    int dx = 0;
    int dy = 0;
    int health = 100;
    bool alive = true;
    bool jumping = false;

public:
    Gerard(int x, int y, Direction direction);
    ~Gerard();
    Direction getDirection() { return direction; }
    void setDirection(Direction newDirection);
    Sprite* getSprite() { return Renderable::getSprite(); }

    int getHealth() const;
    void setHealth(int health);

    bool isJumping() const;
    void setIsJumping(bool isJumping);

    void setVelocity(int velX, int velY);
    void setCharacterDirection(int dx, int dy);

    bool isAlive() const;
    void setIsAlive(bool isAlive);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GERARD_H
