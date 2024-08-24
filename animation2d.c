/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** animation2d
*/

#include "animation2d.h"
#include <stdlib.h>

animated_sprite_2d *create_animated_sprite_2d(
    short start,
    short end,
    float speed,
    tiles_sprite *sprites
)
{
    animated_sprite_2d *animated_sprite = malloc(sizeof(animated_sprite_2d));

    animated_sprite->animation_start = start;
    animated_sprite->animation_end = end;
    animated_sprite->speed = speed;
    animated_sprite->tiles = sprites;
    return animated_sprite;
}
