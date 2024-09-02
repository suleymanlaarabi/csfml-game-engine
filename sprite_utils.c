/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** sprite_utils
*/

#include "sprite_utils.h"
#include <stdlib.h>

sfSprite *create_sprite_with_texture(char texture[])
{
    sfSprite *my_sprite = sfSprite_create();
    sfTexture *my_texture = sfTexture_createFromFile(texture, NULL);

    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    return my_sprite;
}

tiles_sprite *create_tiles_sprite(
    char *tiles_path,
    float sprite_height,
    float sprite_width
)
{
    tiles_sprite *tiles_set = malloc(sizeof(tiles_sprite));

    tiles_set->height = sprite_height;
    tiles_set->width = sprite_width;
    tiles_set->sprite = create_sprite_with_texture(tiles_path);
    return tiles_set;
}

void flip_sprite(sfSprite *sprite)
{
    sfVector2f scale = sfSprite_getScale(sprite);

    sfSprite_setScale(sprite, (sfVector2f) {-scale.x, scale.y});
}

sfBool is_flipped(sfSprite *sprite)
{
    sfVector2f scale = sfSprite_getScale(sprite);

    if (scale.x < 0)
        return sfTrue;
    return sfFalse;
}
