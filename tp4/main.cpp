#include <raylib-cpp.hpp>

#include "Frustum.h"
#include "AABB.h"

//void DrawCubeWithStatus(AABB& aabb, Frustum& frustum)
//{
//    // Dibujar el cubo
//    if (frustum.isAABBVisible(aabb)) {
//        DrawCube(aabb.center, aabb.extents.x * 2, aabb.extents.y * 2, aabb.extents.z * 2, GREEN);  // Si está dentro, dibujar verde
//        DrawText("Cube is inside frustum", aabb.center.x - 50, aabb.center.y + 20, 20, GREEN);  // Mensaje indicando que está dentro
//    }
//    else {
//        DrawCube(aabb.center, aabb.extents.x * 2, aabb.extents.y * 2, aabb.extents.z * 2, RED);    // Si está fuera, dibujar rojo
//        DrawText("Cube is outside frustum", aabb.center.x - 50, aabb.center.y + 20, 20, RED);  // Mensaje indicando que está fuera
//    }
//}

int main(void) {
  raylib::Window Window;
  raylib::Camera Camera;
  raylib::Camera Camera2;
  Window.Init();

  // Define the camera to look into our 3d world
  Camera.position = {10.0f, 10.0f, 10.0f};
  Camera.target = {0.0f, 0.0f, 0.0f};
  Camera.up = {0.0f, 1.0f, 0.0f};
  Camera.fovy = 45.0f;
  Camera.projection = CAMERA_PERSPECTIVE;

  Camera2.position = {10.0f, 10.0f, 10.0f};
  Camera2.target = {0.0f, 0.0f, 0.0f};
  Camera2.up = {0.0f, 1.0f, 0.0f};
  Camera2.fovy = 45.0f;
  Camera2.projection = CAMERA_PERSPECTIVE;

  Frustum Frustum(20, Camera2);

  // Agregar objetos
  // Dibuja un cubo utilizando la función DrawCube de Raylib
  
  DisableCursor();

  Window.SetTargetFPS(60);

  // Main game loop
  while (!WindowShouldClose()) {
    Camera.Update(CAMERA_FREE);

    Frustum.Update(Camera2);

    Frustum.UpdatePlanes();

    Window.BeginDrawing();

    Window.ClearBackground(BLACK);

    Camera.BeginMode();

    Frustum.DrawWireframe();

    Frustum.DrawVisibleObjects();

    DrawGrid(20,1);

    /*DrawCubeWithStatus(cube1, Frustum);
    DrawCubeWithStatus(cube2, Frustum);*/

    Camera.EndMode();

    Window.EndDrawing();
  }

  Window.Close(); // Close window and OpenGL context


  return 0;
}
