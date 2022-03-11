/* voxoid.c */

/* Libraries */
#include "raylib.h"

/* Local States */
#include "state/controlstate.h"
#include "state/gamestate.h"
#include "state/renderstate.h"

/* Local Systems */
#include "system/controlupdate.h"
#include "system/render.h"
#include "system/selection.h"


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

    // State initializations
    ControlState control_state = { 0 };
    GameState game_state = {
        .cube_pos = (Vector3){ 0.0f, 1.0f, 0.0f },
        .cube_size = (Vector3){ 2.0f, 2.0f, 2.0f }
    };
    RenderState render_state = { 0 };
    render_state.camera = initializeCamera();
    SetCameraMode(render_state.camera, CAMERA_FREE);

    // Game Loop
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        // Pre-update
        // float delta = GetFrameTime();
        ControlState current_control_state = { 0 };
        updateControlState(&current_control_state);
        UpdateCamera(&render_state.camera);

        // Update systems
        updateSelection(&render_state, &game_state, &control_state);

        // Render systems
        renderGame(&render_state, &game_state);

        // Post-render
        control_state = current_control_state;
    }

    CloseWindow();
    return 0;
}
