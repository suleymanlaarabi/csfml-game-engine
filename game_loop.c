/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** game_loop
*/

#include "game_loop.h"
#include <stdio.h>

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

void draw_entity(game_engine *engine, game_entity *entity)
{
    switch (entity->type) {
        case SPRITE:
            sfRenderWindow_drawSprite(
                engine->window, entity->element->sprite, NULL);
            break;
        case TEXT:
            sfRenderWindow_drawText(
                engine->window, entity->element->text, NULL);
            break;
        case ANIMATED_SPRITE:
            update_animation(
                entity->element->animated_sprite, 0.1);
            sfRenderWindow_drawSprite(
                engine->window,
                entity->element->animated_sprite->tiles->sprite,
                NULL);
    }
}

void process_entity(game_engine *engine, float delta_time)
{
    list_entity *temp;

    if (engine->scene == NULL)
        return;
    temp = engine->scene->entities;
    while (temp != NULL) {
        draw_entity(engine, temp->value);
        if (temp->value->on_update)
            temp->value->on_update(delta_time, temp->value);
        temp = temp->next;
    }
}
