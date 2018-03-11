#include <raylib.h>
#include <spritesheet_renderer.h>

static struct spritesheet_data character_spritesheet;

static struct spritesheet_animation character_walk_animation = {
    .ticks_per_frame = 0,
    .frame_elapsed_ticks = 0,
    .current_frame = 0,
    .frames = {
        [0] = {
            .x = 0,
            .y = 0,
            .width = 24,
            .height = 24,
        },
    },
    .num_frames = 1,
};

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

    Texture2D character_texture = LoadTexture("assets/test_character.png");

    SpritesheetRenderer_InitSpritesheet(&character_texture, &character_spritesheet);
    SpritesheetRenderer_SetAnimation(&character_spritesheet, 0, &character_walk_animation);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Begin2dMode(camera);

        SpritesheetRenderer_Draw(&character_spritesheet, &camera.target);

        End2dMode();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
