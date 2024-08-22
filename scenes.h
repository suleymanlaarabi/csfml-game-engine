/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** scenes
*/

#ifndef INCLUDED_SCENES_H
    #define INCLUDED_SCENES_H
    #include "lib/list/list.h"

struct scene_entity;

typedef void (*scene_update_func)(float, struct scene_entity*);
typedef void (*scene_init_func)(struct scene_entity*);

typedef struct scene_entity {
    list_entity *entities;
    scene_update_func on_update;
    scene_init_func on_init;
    sfRenderWindow *window;
} scene_entity;


#endif
