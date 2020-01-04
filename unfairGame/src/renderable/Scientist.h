//
// Created by Sebastiaan on 17/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCIENTIST_H
#define GBA_SPRITE_ENGINE_PROJECT_SCIENTIST_H


#include <vector>
#include "Renderable.h"
#include "../killable/Testtube.h"
#define GBA_SCREEN_WIDTH 240
#define GBA_SCREEN_HEIGHT 160

class Scientist : public Renderable
{
public:
    Scientist(int x, int y);
    std::vector<std::unique_ptr<Testtube>> tubeBomb(int dx);
    int generateXDestination();
    int randomX();
    int getXDestination() { return xDestination; }
    void setXDestination(int xDestination) {this->xDestination = xDestination; }

    bool hasReachedXDestination(int margin) { return ( getX() > xDestination - (margin * 2))  && getX() < xDestination + (margin * 2); }

    int getScientistTime() { return scientistTime; }
    void setScientistTime(int scientistTime) {  this->scientistTime = scientistTime; }

    int getHealth() { return health; }
    void setHealth(int health) { this->health = health; }

    bool getCanBeDamaged() { return canBeDamaged; }
    void setCanBeDamaged(bool canBeDamaged) { this->canBeDamaged = canBeDamaged; }

    void setMoveSpeed(int moveSpeed) {this->moveSpeed = moveSpeed; }
    int getMoveSpeed() { return moveSpeed; }

protected:

private:
    bool reachedXDestination = false;
    int xDestination = 0;
    int scientistTime = 0;
    int health = 6;
    bool canBeDamaged = true;
    int moveSpeed = 1;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SCIENTIST_H
