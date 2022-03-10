/* voxoid.c */
#include "game.h"

/* Libraries */
#include "raylib.h"

Camera initializeCamera()
{
    Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    return camera;
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(
        screenWidth,
        screenHeight,
        "raylib [core] example - 3d picking"
    );

    Game game = { 0 };
    game.camera = initializeCamera();
    game.cube_pos = (Vector3){ 0.0f, 1.0f, 0.0f };
    game.cube_size = (Vector3){ 2.0f, 2.0f, 2.0f };

    SetCameraMode(game.camera, CAMERA_FREE);

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        update(&game, GetFrameTime());

        draw(&game);
    }

    CloseWindow();

    return 0;
}
