/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** list
*/

#ifndef INCLUDED_LIST_H
    #define INCLUDED_LIST_H
    #include "../../entity.h"
    #include <SFML/Graphics.h>

typedef struct list_entity {
    game_entity *value;
    struct list_entity *next;
} list_entity;

list_entity *new_list_entity(void);
sfBool is_empty_list_entity(list_entity *li);
int list_entity_length(list_entity *li);
list_entity *push_back_entity(list_entity *li, game_entity *entity);
void for_entity(list_entity *li, void (*func)(game_entity*));

#endif
