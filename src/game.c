/* game.c */
#include "game.h"

/* Libraries */
#include "raylib.h"

void update(Game* game, float delta)
{
    delta = delta; // Avoid unused parameter error

    UpdateCamera(&game->camera);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (!game->collision.hit) {
            game->ray = GetMouseRay(GetMousePosition(), game->camera);

            // Check collision between ray and box
            game->collision = GetRayCollisionBox(
                game->ray,
                (BoundingBox) {
                    (Vector3) {
                        game->cube_pos.x - game->cube_size.x / 2,
                        game->cube_pos.y - game->cube_size.y / 2,
                        game->cube_pos.z - game->cube_size.z / 2
                    },
                    (Vector3) {
                        game->cube_pos.x + game->cube_size.x / 2,
                        game->cube_pos.y + game->cube_size.y / 2,
                        game->cube_pos.z + game->cube_size.z / 2
                    }
                }
            );
        }
        else game->collision.hit = false;
    }
}

void draw(Game* game)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(game->camera);
    if (game->collision.hit) {
        DrawCube(game->cube_pos, game->cube_size.x, game->cube_size.y, game->cube_size.z, RED);
        DrawCubeWires(game->cube_pos, game->cube_size.x, game->cube_size.y, game->cube_size.z, MAROON);
        DrawCubeWires(
            game->cube_pos,
            game->cube_size.x + 0.2f,
            game->cube_size.y + 0.2f,
            game->cube_size.z + 0.2f,
            GREEN
        );
    }
    else {
        DrawCube(game->cube_pos, game->cube_size.x, game->cube_size.y, game->cube_size.z, GRAY);
        DrawCubeWires(
            game->cube_pos,
            game->cube_size.x,
            game->cube_size.y,
            game->cube_size.z,
            DARKGRAY
        );
    }
    DrawRay(game->ray, MAROON);
    DrawGrid(10, 1.0f);
    EndMode3D();
    EndDrawing();
}
