/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** entity
*/

#include "entity.h"
#include "sprite_utils.h"
#include <stdlib.h>
#include <stdio.h>

game_entity *create_game_entity(
    char *value,
    EntityElementType type,
    entity_update_func on_update,
    entity_element *from_element
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
    entity->type = type;
    entity->on_update = on_update;
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
