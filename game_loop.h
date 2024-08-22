/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** game_loop
*/

#ifndef INCLUDED_GAME_LOOP_H
    #define INCLUDED_GAME_LOOP_H
    #include <SFML/Graphics.h>
    #include "engine.h"
    #include "scenes.h"

void default_event_handler(sfRenderWindow *window, sfEvent *event);
void check_event(game_engine *engine, sfEvent *event, float delta_time);
void process_entity(game_engine *engine, float delta_time);

#endif
