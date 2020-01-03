//
// Created by Sebastiaan on 3/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_IMAGINARYBLOCK_H
#define GBA_SPRITE_ENGINE_PROJECT_IMAGINARYBLOCK_H


#include "Renderable.h"

class ImaginaryBlock: public Renderable
{
public:
    ImaginaryBlock(int x, int y);
protected:
private:
    int x,y;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_IMAGINARYBLOCK_H
