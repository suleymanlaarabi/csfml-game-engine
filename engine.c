/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** engine
*/

#include "engine.h"
#include "game_loop.h"
#include "scenes.h"
#include "lib/list/list.h"
#include <stdlib.h>

game_engine *create_engine(
    char *title,
    window_update_func on_update,
    window_update_event on_event
)
{
    game_engine *engine = malloc(sizeof(game_engine));
    sfVideoMode video_mode = {1920, 1080, 32};

    engine->window = sfRenderWindow_create(
        video_mode,
        title,
        sfResize | sfClose,
        NULL
    );
    engine->on_update = on_update;
    engine->on_event = on_event;
    engine->scene = NULL;
    return engine;
}

void clean_game(game_engine *engine, sfClock *clock)
{
    list_entity *temp = engine->scene->entities;

    while (temp != NULL) {
        switch (temp->value->type) {
            case SPRITE:
                sfSprite_destroy(temp->value->element.sprite);
            case TEXT:
                sfText_destroy(temp->value->element.text);
        }
        free(temp);
    }
    sfClock_destroy(clock);
}

int run_game(game_engine *engine)
{
    float delta_time;
    sfClock *clock = sfClock_create();
    sfEvent event;

    while (sfRenderWindow_isOpen(engine->window)) {
        delta_time = sfTime_asSeconds(sfClock_restart(clock));
        check_event(engine, &event, delta_time);
        sfRenderWindow_clear(engine->window, sfColor_fromRGB(0, 0, 0));
        process_entity(engine, delta_time);
        if (engine->on_update)
            engine->on_update(delta_time, engine->window);
        sfRenderWindow_display(engine->window);
    }
    clean_game(engine, clock);
}
