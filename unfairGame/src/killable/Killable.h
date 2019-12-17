//
// Created by Sebastiaan on 7/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_KILLABLE_H
#define GBA_SPRITE_ENGINE_PROJECT_KILLABLE_H

#include "../Renderable.h"

//Obstacle that will appear and (most likely) will kill you
class Killable : public Renderable
{
    private:
        //damaged means if the killable has hit something
        bool damaged = false;

protected:
    int velX;
    int velY;
    int dmg;

public:
    bool hasDamaged() const;
    void setDamaged(bool damaged);
    int getDmg() const;
    virtual void setDmg(int dmg) = 0;
    Killable(int x, int y, int velX, int velY, int dmg);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_KILLABLE_H
