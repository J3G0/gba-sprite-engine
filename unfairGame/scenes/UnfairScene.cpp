//
// Created by Sebastiaan on 28/11/2019.
//
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <algorithm>
#include "UnfairScene.h"
#include "../sprite/sprite_data/sprite_data.h"
#include "../sprite/sprite_data/background_data.h"
#include "StartScene.h"
#include "../src/killable/FireBall.h"
#include "../src/killable/Testtube.h"

#include <utility>

#define JUMP_TIME 1000
#define COLLISION_OFFSET 2
#define BACKGROUND_TILE_SIZE 8
#define BACKGROUND_TILES_IN_MAPWIDTH 32

UnfairScene::UnfairScene(std::shared_ptr<GBAEngine> engine, std::shared_ptr<Data> data): GenericScene(std::move(engine), std::move(data))
{

}