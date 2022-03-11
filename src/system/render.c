/* system/render.c */
#include "system/render.h"

/* Libraries */
#include "raylib.h"


void renderGame(RenderState const *const rs, GameState const *const gs) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(rs->camera);
    if (rs->collision.hit) {
        DrawCube(
            gs->cube_pos,
            gs->cube_size.x,
            gs->cube_size.y,
            gs->cube_size.z,
            RED
        );
        DrawCubeWires(
            gs->cube_pos,
            gs->cube_size.x,
            gs->cube_size.y,
            gs->cube_size.z,
            MAROON
        );
        DrawCubeWires(
            gs->cube_pos,
            gs->cube_size.x + 0.2f,
            gs->cube_size.y + 0.2f,
            gs->cube_size.z + 0.2f,
            GREEN
        );
    }
    else {
        DrawCube(
            gs->cube_pos,
            gs->cube_size.x,
            gs->cube_size.y,
            gs->cube_size.z,
            GRAY
        );
        DrawCubeWires(
            gs->cube_pos,
            gs->cube_size.x,
            gs->cube_size.y,
            gs->cube_size.z,
            DARKGRAY
        );
    }
    DrawRay(rs->ray, MAROON);
    DrawGrid(10, 1.0f);
    EndMode3D();
    EndDrawing();
}
