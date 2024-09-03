/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** entity
*/

#ifndef INCLUDED_ENTITY_H
    #define INCLUDED_ENTITY_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "animation.h"

struct game_entity;
struct game_engine;
struct animated_sprite;

typedef void (*entity_update_func)(float, struct game_entity *);

typedef union {
    sfSprite *sprite;
    sfText *text;
    struct animated_sprite *animated_sprite;
} entity_element;

typedef enum EntityElementType {
    SPRITE,
    ANIMATED_SPRITE,
    TEXT
} EntityElementType;

typedef struct game_entity {
    struct game_engine *engine;
    entity_update_func on_update;
    sfBool is_enabled;
    entity_element *element;
    EntityElementType type;
} game_entity;

game_entity *create_game_entity(
    char *value,
    EntityElementType type,
    entity_element *from_element,
    struct game_engine *engine
);

entity_element *create_entity_element(
    void *element
);

sfSprite *get_entity_sprite(game_entity *entity);

#endif
