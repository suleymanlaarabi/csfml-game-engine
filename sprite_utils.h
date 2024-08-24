/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** sprite_utils
*/

#ifndef INCLUDED_SPRITE_UTILS_H
    #define INCLUDED_SPRITE_UTILS_H
    #include <SFML/Graphics.h>

typedef struct tiles_sprite {
    float width;
    float height;
    sfSprite *sprite;
} tiles_sprite;


sfSprite *create_sprite_with_texture(char texture[]);

tiles_sprite *create_tiles_sprite(
    char *tiles_path,
    float sprite_height,
    float sprite_width
);

#endif
