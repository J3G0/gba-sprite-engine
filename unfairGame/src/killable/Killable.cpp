//
// Created by Sebastiaan on 7/12/2019.
//

#include "Killable.h"


Killable::Killable(int x, int y, int velX, int velY, int dmg) : Renderable(x, y, false)
{
    Renderable::getSprite()->setVelocity(velX, velY);
    this->dmg =  dmg;
    this->damaged = false;
    this->velX = velX;
    this->velY = velY;

}

int Killable::getDmg() const
{
    return dmg;
}

void Killable::setDmg(int dmg)
{
    Killable::dmg = dmg;
}

bool Killable::hasDamaged() const
{
    return damaged;
}

void Killable::setDamaged(bool damaged)
{
    Killable::damaged = damaged;
}
