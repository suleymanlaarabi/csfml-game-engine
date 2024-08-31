/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** fps_display
*/

#include "fps_display.h"
#include <stdio.h>

void on_fps_display_update(float delta_time, game_entity *entity)
{
    char text[50];

    sprintf(text, "FPS=%d", (int)(1.0 / delta_time) + 1);
    sfText_setString(entity->element->text, text);
}

game_entity *create_fps_displayer(sfFont *font)
{
    game_entity *entity = create_game_entity(
        "",
        TEXT,
        &on_fps_display_update,
        NULL
    );
    sfVector2f position = {10, 10};

    sfText_setFont(entity->element->text, font);
    sfText_setCharacterSize(entity->element->text, 50);
    sfText_setColor(entity->element->text, sfWhite);
    sfText_setPosition(entity->element->text, position);
    return entity;
}
