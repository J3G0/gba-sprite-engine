//
// Created by Sebastiaan on 28/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "../src/killable/Killable.h"
#include "../src/Gerard.h"
#include "../src/Data.h"
#include "../src/Scientist.h"
#include "GenericScene.h"


//Vragen

// Transparancy?
// -- > in orde
// Wie moet bijhouden hoeveel keer doodgegaan, hoe beste overgaan van startscene naar spel scene (heletijd op en af)
// -- > aparte klasse met data
// Gerard een shared ptr? aangezien deze over meerdere scenes hetzelfde zou (moeten) blijven?
// --> niet nodig, wordt opgeruimd bij scene verandering

class UnfairScene : public GenericScene
{
public:
    UnfairScene(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Data> data) : GenericScene(std::move(engine), std::move(data)){}
    void load() override;
    void registerInput(u16 keys) override;
protected:

private:
};

#endif //GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H