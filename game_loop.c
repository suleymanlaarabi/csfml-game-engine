/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** game_loop
*/

#include "game_loop.h"

void default_event_handler(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void check_event(game_engine *engine, sfEvent *event, float delta_time)
{
    while (sfRenderWindow_pollEvent(engine->window, event)) {
        default_event_handler(engine->window, event);
        if (engine->on_event)
            engine->on_event(event);
    }
}

void process_entity(game_engine *engine, float delta_time)
{
    list_entity *temp = engine->scene->entities;
    entity_element el;

    while (temp != NULL) {
        el = temp->value->element;
        switch (temp->value->type) {
            case SPRITE:
                sfRenderWindow_drawSprite(engine->window, el.sprite, NULL);
            case TEXT:
                sfRenderWindow_drawText(engine->window, el.text, NULL);
        }
        if (temp->value->on_update)
            temp->value->on_update(delta_time, temp->value);
        temp = temp->next;
    }
}
