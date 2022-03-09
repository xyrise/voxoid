/* voxoid.c */

/* Libraries */
#include "raylib.h"

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(
      screenWidth,
      screenHeight,
      "raylib [core] example - 3d picking"
  );

  // Define the camera for 3D view
  Camera camera = { 0 };
  camera.position = (Vector3) { 10.0f, 10.0f, 10.0f };
  camera.target = (Vector3) { 0.0f, 0.0f, 0.0f };
  camera.up = (Vector3) { 0.0f, 1.0f, 0.0f };
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Vector3 cubePosition = { 0.0f, 1.0f, 0.0f };
  Vector3 cubeSize = { 2.0f, 2.0f, 2.0f };


  Ray ray = { 0 };
  RayCollision collision = { 0 };

  SetCameraMode(camera, CAMERA_FREE);

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    // Update
    UpdateCamera(&camera);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      if (!collision.hit) {
        ray = GetMouseRay(GetMousePosition(), camera);

        // Check collision between ray and box
        collision = GetRayCollisionBox(
            ray,
            (BoundingBox) {
              (Vector3) {
                cubePosition.x - cubeSize.x / 2,
                cubePosition.y - cubeSize.y / 2,
                cubePosition.z - cubeSize.z / 2
              },
              (Vector3) {
                cubePosition.x + cubeSize.x / 2,
                cubePosition.y + cubeSize.y / 2,
                cubePosition.z + cubeSize.z / 2
              }
            }
        );
      }
      else collision.hit = false;
    }

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(camera);
    if (collision.hit) {
      DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, RED);
      DrawCubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, MAROON);
      DrawCubeWires(
          cubePosition,
          cubeSize.x + 0.2f,
          cubeSize.y + 0.2f,
          cubeSize.z + 0.2f,
          GREEN
      );
    }
    else {
      DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, GRAY);
      DrawCubeWires(
          cubePosition,
          cubeSize.x,
          cubeSize.y,
          cubeSize.z,
          DARKGRAY
      );
    }
    DrawRay(ray, MAROON);
    DrawGrid(10, 1.0f);
    EndMode3D();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
