#pragma once

#include <raylib.h>
#include <stdint.h>

#define kMAX_FRAMES_PER_ANIMATION             64
#define kMAX_ANIMATIONS_PER_SPRITESHEET       64


struct spritesheet_animation {
    uint8_t ticks_per_frame;
    uint8_t frame_elapsed_ticks;
    uint8_t current_frame;

    Rectangle frames[kMAX_FRAMES_PER_ANIMATION];
    uint8_t num_frames;
};


struct spritesheet_data {
    Texture2D *spritesheet;
    uint8_t current_animation;

    struct spritesheet_animation animations[kMAX_ANIMATIONS_PER_SPRITESHEET];
    uint8_t num_animations;
};

void SpritesheetRenderer_InitSpritesheet(Texture2D *texture, struct spritesheet_data *spritesheet);

void SpritesheetRenderer_SetAnimation(struct spritesheet_data *spritesheet, uint8_t id, struct spritesheet_animation *animation);

void SpritesheetRenderer_Draw(struct spritesheet_data *spritesheet, Vector2 *position);