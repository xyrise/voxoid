#pragma once

#include "game.h"
#include "tile.h"
#include "raylib.h"

typedef struct TileCube {
	Tile front;
	Tile back;
	Tile left;
	Tile right;
	Tile top;
	Tile bottom;
} TileCube;

void TileCube_update(TileCube* self, Game* game, float delta);
void TileCube_draw(TileCube* self, Game* game);
