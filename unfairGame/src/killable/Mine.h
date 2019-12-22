//
// Created by Sebastiaan on 22/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MINE_H
#define GBA_SPRITE_ENGINE_PROJECT_MINE_H


#include "Killable.h"

class Mine : public Killable
{
public:
    Mine(int x, int y, int dmg);
    int getMineTickTime() { return mineTickTime; }
    void setMineTickTime(int mineTickTime) {this->mineTickTime = mineTickTime; }
    int getCurrentFrame() { return currentFrame; }
    void tickMine();
    void resetMine();
    bool getNeedsUpdate() { return needsUpdate; }
    void setNeedsUpdate(bool needsUpdate) {this->needsUpdate = needsUpdate; }
    int getExplosionRadius() { return explosionRadius; }

protected:

private:
    int mineTickTime;
    const int explosionRadius = 25;
    bool needsUpdate = false;
    const int amountOfFrames = 5;
    int currentFrame = getSprite()->getCurrentFrame();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MINE_H
