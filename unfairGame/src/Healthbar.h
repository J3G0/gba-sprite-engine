//
// Created by Sebastiaan on 21/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_HEALTHBAR_H
#define GBA_SPRITE_ENGINE_PROJECT_HEALTHBAR_H


#include "Renderable.h"

class Healthbar : public Renderable
{
public:
    Healthbar(int x, int y);
protected:
private:
    int x,y;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_HEALTHBAR_H
