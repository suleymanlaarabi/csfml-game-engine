/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** scenes
*/

#ifndef INCLUDED_SCENES_H
    #define INCLUDED_SCENES_H
    #include "engine.h"
    #include "lib/list/list.h"

struct scene_entity;

typedef void (*scene_update_func)(float, struct scene_entity*);
typedef void (*scene_init_func)(struct scene_entity*, game_engine*);

typedef struct scene_entity {
    list_entity *entities;
    scene_update_func on_update;
    scene_init_func on_init;
    sfMusic *music;
} scene_entity;

scene_entity *create_scene(
    list_entity *entities,
    scene_init_func init_func,
    scene_update_func update_func,
    char *music_path
);

void register_entity(scene_entity *scene, game_entity *entity);
void load_scene(game_engine *engine, scene_entity *scene);

#endif
