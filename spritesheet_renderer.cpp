#include <spritesheet_renderer.h>
#include <string.h>

void SpritesheetRenderer_InitSpritesheet(Texture2D *texture, struct spritesheet_data *spritesheet)
{
    memset(spritesheet, 0, sizeof(struct spritesheet_data));

    spritesheet->spritesheet = texture;
}


void SpritesheetRenderer_SetAnimation(struct spritesheet_data *spritesheet, uint8_t id, struct spritesheet_animation *animation)
{
    memcpy(&spritesheet->animations[id], animation, sizeof(struct spritesheet_animation));

    spritesheet->animations[id].current_frame = 0;
    spritesheet->animations[id].frame_elapsed_ticks = 0;
}


void SpritesheetRenderer_Draw(struct spritesheet_data *spritesheet, Vector2 *position)
{
    struct spritesheet_animation *current_animation = &spritesheet->animations[spritesheet->current_animation];
    Rectangle *current_rect = &current_animation->frames[current_animation->current_frame];

    DrawTextureRec(*spritesheet->spritesheet, *current_rect, *position, WHITE);
}