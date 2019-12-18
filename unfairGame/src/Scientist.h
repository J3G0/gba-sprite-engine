//
// Created by Sebastiaan on 17/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCIENTIST_H
#define GBA_SPRITE_ENGINE_PROJECT_SCIENTIST_H


#include <vector>
#include "Renderable.h"
#include "killable/Testtube.h"
class Scientist : public Renderable
{
public:
    Scientist(int x, int y);
    std::vector<Testtube> doSomething();
protected:

private:
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SCIENTIST_H
