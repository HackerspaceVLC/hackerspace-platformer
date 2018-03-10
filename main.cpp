#include <raylib.h>


int main()
{
    int screenWidth = 853;
    int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, (void *)"Hackerspace Platformer");

    Camera2D camera;

    camera.target = (Vector2){ 0, 0 };
    camera.offset = (Vector2){ 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            Begin2dMode(camera);
            End2dMode();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
