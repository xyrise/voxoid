/* system/selection.c */
#include "system/selection.h"

/* Libraries */
#include "raylib.h"


void updateSelection(
    RenderState *const rs,
    GameState const *const gs,
    ControlState const *const cs
) {
    if (getMouseButtonLeft(cs->mouse_buttons)) {
        if (!rs->collision.hit) {
            rs->ray = GetMouseRay(GetMousePosition(), rs->camera);

            // Check collision between ray and box
            rs->collision = GetRayCollisionBox(
                rs->ray,
                (BoundingBox) {
                    (Vector3) {
                        gs->cube_pos.x - gs->cube_size.x / 2,
                        gs->cube_pos.y - gs->cube_size.y / 2,
                        gs->cube_pos.z - gs->cube_size.z / 2
                    },
                    (Vector3) {
                        gs->cube_pos.x + gs->cube_size.x / 2,
                        gs->cube_pos.y + gs->cube_size.y / 2,
                        gs->cube_pos.z + gs->cube_size.z / 2
                    }
                }
            );
        }
        else rs->collision.hit = false;
    }
}
