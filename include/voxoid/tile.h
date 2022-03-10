#pragma once

#include "raylib.h"
#include "game.h"

typedef struct Tile {
	Vector3 center_pos;
	Vector2 size;
	Color color;
} Tile;

void Tile_update(Tile* self, float delta);
void Tile_draw(Tile* self, float game);
