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

struct game_entity;

typedef void (*entity_update_func)(float, struct game_entity*);

typedef union {
    sfSprite *sprite;
    sfText *text;
} entity_element;

typedef enum EntityElementType {
    SPRITE,
    TEXT
} EntityElementType;

typedef struct game_entity {
    entity_update_func on_update;
    sfBool is_enabled;
    entity_element element;
    EntityElementType type;
} game_entity;

game_entity *create_game_entity(
    char *value,
    EntityElementType type,
    entity_update_func on_update
);

#endif
