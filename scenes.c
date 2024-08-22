/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** scenes
*/

#include "scenes.h"
#include <stdlib.h>
#include <SFML/Audio.h>

scene_entity *create_scene(
    list_entity *entities,
    scene_init_func init_func,
    scene_update_func update_func,
    char *music_path
)
{
    scene_entity *scene = malloc(sizeof(scene_entity));

    scene->entities = entities;
    scene->on_init = init_func;
    scene->on_update = update_func;
    if (music_path) {
        scene->music = sfMusic_createFromFile(music_path);
        sfMusic_play(scene->music);
    } else {
        scene->music = NULL;
    }
    return scene;
}

void register_entity(scene_entity *scene, game_entity *entity)
{
    scene->entities = push_back_entity(scene->entities, entity);
}

void load_scene(game_engine *engine, scene_entity *scene)
{
    scene->on_init(scene);
    engine->scene = scene;
}