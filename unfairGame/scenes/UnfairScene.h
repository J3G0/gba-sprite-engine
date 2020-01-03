//
// Created by Sebastiaan on 28/11/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "../src/killable/Killable.h"
#include "../src/renderable/Gerard.h"
#include "../src/Data.h"
#include "../src/renderable/Scientist.h"
#include "GenericScene.h"
#include "../src/renderable/Flag.h"


//Vragen

// Transparancy?
// -- > in orde
// Wie moet bijhouden hoeveel keer doodgegaan, hoe beste overgaan van startscene naar spel scene (heletijd op en af)
// -- > aparte klasse met data
// Gerard een shared ptr? aangezien deze over meerdere scenes hetzelfde zou (moeten) blijven?
// --> niet nodig, wordt opgeruimd bij scene verandering

enum ProgressionState {NONE = 0, STATE1, STATE2, STATE3, STATE4, FINAL_STATE};

class UnfairScene : public GenericScene
{
public:
    UnfairScene(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Data> data) : GenericScene(std::move(engine), std::move(data)){}
    void load() override;
    void registerInput(u16 keys) override;
    ProgressionState getProgressionState() const;
    void setProgressionState(ProgressionState progressionState);
    void handleProgression();
    void placeSprites();
    std::vector<Background *> backgrounds() override;
protected:

private:
    ProgressionState progressionState = NONE;
    std::unique_ptr<Renderable> flag;
    std::unique_ptr<Background> clouds;
    bool hasChanged = false;
};

#endif //GBA_SPRITE_ENGINE_PROJECT_UNFAIRSCENE_H