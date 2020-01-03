//
// Created by Sebastiaan on 3/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_FLAG_H
#define GBA_SPRITE_ENGINE_PROJECT_FLAG_H


#include "Renderable.h"

class Flag : public Renderable
{
public:
    Flag(int x, int y);
protected:
private:
    int x,y;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_FLAG_H
