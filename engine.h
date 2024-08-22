/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** engine
*/

#ifndef INCLUDED_ENGINE_H
    #define INCLUDED_ENGINE_H
    #include <SFML/Graphics.h>
    #include "entity.h"
    #include "lib/list/list.h"

struct scene_entity;
struct game_engine;

typedef void (*window_update_event)(sfEvent*);
typedef void (*window_update_func)(float, struct sfRenderWindow*);

typedef struct game_engine {
    sfRenderWindow *window;
    window_update_func on_update;
    window_update_event on_event;
    struct scene_entity *scene;
} game_engine;

game_engine *create_engine(
    char *title,
    window_update_func on_update,
    window_update_event on_event
);
int run_game(game_engine *engine);

#endif
