//
// Created by Sebastiaan on 7/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_KILLABLE_H
#define GBA_SPRITE_ENGINE_PROJECT_KILLABLE_H

#include "../src/Renderable.h"

//Obstacle that will appear and (most likely) will kill you
class Killable : public Renderable
{
    private:
        int x;
        int y;
    public:
        Killable(int x, int y, int velX, int velY);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_KILLABLE_H
