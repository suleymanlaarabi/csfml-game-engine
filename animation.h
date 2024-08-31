/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** animation
*/

#ifndef INCLUDED_ANIMATION_H
    #define INCLUDED_ANIMATION_H
    #include "sprite_utils.h"

typedef struct animated_sprite {
    tiles_sprite *tiles;
    short animation_start;
    short animation_end;
    float speed;
    short current_frame;
    sfClock *clock;
} animated_sprite;

animated_sprite *create_animated_sprite(
    short start,
    short end,
    float speed,
    tiles_sprite *sprites
);

void set_animated_sprite_frame(
    animated_sprite *element,
    short frame
);
void update_animation(animated_sprite *element, float delta);

#endif
