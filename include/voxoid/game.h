#pragma once

#include "tilecube.h"
#include "raylib.h"

typedef struct Game {
	Camera camera;
	Ray ray;
	Vector3 cube_pos;
	Vector3 cube_size;
	RayCollision collision;
} Game;

void update(Game* game, float delta); // Called for each frame, before rendering
void draw(Game* game); // Called after update on every frame
