//
// Created by Sebastiaan on 17/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_TESTTUBE_H
#define GBA_SPRITE_ENGINE_PROJECT_TESTTUBE_H

#include "Killable.h"

class Testtube : public Killable
{
public:
    Testtube(int x, int y, int velX, int velY, int dmg);
protected:
private:
    int x;
    int y;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_TESTTUBE_H
