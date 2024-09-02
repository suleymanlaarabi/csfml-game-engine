/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** animation
*/

#include "animation.h"
#include <stdlib.h>
#include <stdio.h>

animated_sprite *create_animated_sprite(
    short start,
    short end,
    float speed,
    tiles_sprite *sprites
)
{
    animated_sprite *el = malloc(sizeof(animated_sprite));

    el->animation_start = start;
    el->animation_end = end;
    el->speed = speed;
    el->tiles = sprites;
    el->clock = sfClock_create();
    return el;
}

void set_animated_sprite_frame(
    animated_sprite *element,
    short frame
)
{
    const sfTexture *texture = sfSprite_getTexture(element->tiles->sprite);
    unsigned int img_width = sfTexture_getSize(texture).x;
    short img_per_line = img_width / element->tiles->width;
    short row = (short)frame / img_per_line + 1;
    int column = frame - ((row - 1) * img_per_line);
    sfIntRect rect = {0, 0, 0, 0};

    rect.height = element->tiles->height;
    rect.width = element->tiles->width;
    rect.left = column * element->tiles->height;
    rect.top = (row - 1) * element->tiles->width;
    sfSprite_setTextureRect(element->tiles->sprite, rect);
}

void update_animation(animated_sprite *element, float delta)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(element->clock)) <
        element->speed)
        return;
    if (element->current_frame >= element->animation_end) {
        element->current_frame = element->animation_start;
    } else {
        element->current_frame++;
    }
    set_animated_sprite_frame(element, element->current_frame);
    sfClock_restart(element->clock);
}

void set_animation(
    animated_sprite *element,
    short animation_start,
    short animation_end,
    float speed
)
{
    element->animation_start = animation_start;
    element->animation_end = animation_end;
    element->speed = speed;
}
