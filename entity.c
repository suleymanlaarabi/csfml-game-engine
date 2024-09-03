/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** entity
*/

#include "entity.h"
#include "sprite_utils.h"
#include "engine.h"
#include <stdlib.h>
#include <stdio.h>

game_entity *create_game_entity(
    char *value,
    EntityElementType type,
    entity_element *from_element,
    game_engine *engine
)
{
    game_entity *entity = malloc(sizeof(game_entity));

    entity->element = malloc(sizeof(entity_element));
    if (from_element == NULL) {
        if (type == SPRITE)
            entity->element->sprite = create_sprite_with_texture(value);
        if (type == TEXT) {
            entity->element->text = sfText_create();
            sfText_setString(entity->element->text, value);
        }
    } else {
        entity->element = from_element;
    }
    entity->on_update = NULL;
    entity->engine = engine;
    entity->type = type;
    entity->is_enabled = sfTrue;
    return entity;
}

entity_element *create_entity_element(
    void *element
)
{
    entity_element *entity = malloc(sizeof(entity_element));

    entity->animated_sprite = element;
    return entity;
}

sfSprite *get_entity_sprite(game_entity *entity)
{
    switch (entity->type) {
        case ANIMATED_SPRITE:
            return entity->element->animated_sprite->tiles->sprite;
        case SPRITE:
            return entity->element->sprite;
    }
    return NULL;
}
