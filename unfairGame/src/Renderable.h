//
// Created by Sebastiaan on 7/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_RENDERABLE_H
#define GBA_SPRITE_ENGINE_PROJECT_RENDERABLE_H

#include <libgba-sprite-engine/sprites/sprite.h>

// Base class of something in scene
// loosely based on https://github.com/J3G0/gba-sprite-engine/blob/master/demos/demo3-foodthrowing/src/bullet.h
class Renderable
{
    private:
        std::unique_ptr<Sprite> sprite;
        int x,y;
    public:
         Renderable(int x, int y) : x(x), y(y) {}
         Sprite* getSprite() { return sprite.get(); }
         virtual void setSprite(std::unique_ptr<Sprite> sprite);




};


#endif //GBA_SPRITE_ENGINE_PROJECT_RENDERABLE_H
