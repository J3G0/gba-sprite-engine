//
// Created by Sebastiaan on 3/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_PLANT_H
#define GBA_SPRITE_ENGINE_PROJECT_PLANT_H


#include "Killable.h"

class Plant : public Killable
{
public:
    Plant(int x, int y, int velX, int velY, int dmg);
protected:
private:
    int x;
    int y;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_PLANT_H
