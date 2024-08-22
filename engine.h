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

struct game_engine;

typedef void (*window_update_event)(sfEvent*);
typedef void (*window_update_func)(float, struct sfRenderWindow*);

typedef struct {
    sfRenderWindow *window;
    window_update_func on_update;
    window_update_event on_event;
    list_entity *entities;
} game_engine;

game_engine *create_engine(
    char *title,
    window_update_func on_update,
    window_update_event on_event
);
void register_entity(game_engine *engine, game_entity *entity);
int run_game(game_engine *engine);

#endif
