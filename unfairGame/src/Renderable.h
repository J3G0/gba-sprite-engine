//
// Created by Sebastiaan on 7/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_RENDERABLE_H
#define GBA_SPRITE_ENGINE_PROJECT_RENDERABLE_H

#include <libgba-sprite-engine/sprites/sprite.h>
#include "libgba-sprite-engine/sprites/sprite_builder.h"
//Renderable needs to know all sprite data
#include "../sprite/sprite_data.h"
#include "../sprite/walkable.c"


// Base class of something in scene
// loosely based on https://github.com/J3G0/gba-sprite-engine/blob/master/demos/demo3-foodthrowing/src/bullet.h
class Renderable
{
private:
    std::unique_ptr<Sprite> sprite;
    bool walkable;
    bool offScreen;

    //Protected because inheritance
protected:
        SpriteBuilder<Sprite> spriteBuilder;
        int x;
        int y;
public:
     Renderable(int x, int y, bool walkable);
     Sprite* getSprite() { return sprite.get(); }
     void setSprite(std::unique_ptr<Sprite> sprite);
     bool isOffScreen() { return getSprite()->isOffScreen(); }

     int getX() { return sprite->getX(); }
     int getY() { return sprite->getY(); }
     int getStartX() { return sprite->getStartX(); }
     int getStartY() { return sprite->getStartY(); }

    bool collidesWith(Sprite *other) {return sprite->collidesWith(*other); }
    bool isWalkable() const;

    void setWalkable(bool walkable);








};


#endif //GBA_SPRITE_ENGINE_PROJECT_RENDERABLE_H
