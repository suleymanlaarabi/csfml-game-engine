/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** sprite_utils
*/

#include "sprite_utils.h"

sfSprite *create_sprite_with_texture(char texture[])
{
    sfSprite *my_sprite = sfSprite_create();
    sfTexture *my_texture = sfTexture_createFromFile(texture, NULL);

    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    return my_sprite;
}
