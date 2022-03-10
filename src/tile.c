/* tile.c */
#include "tile.h"

void Tile_update(Tile* self, Game* game, float delta)
{
	if (!self || !game || !delta) return;
}

void Tile_draw(Tile* self, Game* game)
{
	if (!game) return;
	DrawPlane(self->center_pos, self->size, self->color);
}
