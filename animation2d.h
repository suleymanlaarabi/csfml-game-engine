/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** animation2d
*/

#ifndef INCLUDED_ANIMATION2D_H
    #define INCLUDED_ANIMATION2D_H
    #include "sprite_utils.h"

typedef struct animated_sprite_2d {
    tiles_sprite *tiles;
    short animation_start;
    short animation_end;
    float speed;
} animated_sprite_2d;

#endif
