/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** list
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

list_entity *new_list_entity(void)
{
    list_entity *li = malloc(sizeof(list_entity));

    li = NULL;
    return li;
}

list_entity *push_back_entity(list_entity *li, game_entity *entity)
{
    list_entity *new_li = malloc(sizeof(list_entity));
    list_entity *temp;

    new_li->value = entity;
    new_li->next = NULL;
    if (is_empty_list_entity(li))
        return new_li;
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_li;
    return li;
}

sfBool is_empty_list_entity(list_entity *li)
{
    if (li == NULL)
        return sfTrue;
    return sfFalse;
}

void for_entity(list_entity *li, void (*func)(game_entity*))
{
    while (li != NULL) {
        func(li->value);
        li = li->next;
    }
}

int list_entity_length(list_entity *li)
{
    int i = 0;

    if (is_empty_list_entity(li))
        return i;
    while (li != NULL) {
        i++;
        li = li->next;
    }
    return i;
}
