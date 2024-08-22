/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** main
*/

#include <SFML/Graphics.h>
#include "engine.h"
#include "entity.h"
#include "entities/fps_display.h"
#include <stdio.h>
#include "lib/list/list.h"

const int speed = 400;

static void on_cat_update(float delta, game_entity *entity)
{
    sfVector2f position = sfSprite_getPosition(entity->element.sprite);

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        position.y -= speed * delta;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        position.y += speed * delta;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        position.x -= speed * delta;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        position.x += speed * delta;
    sfSprite_setPosition(entity->element.sprite, position);
}

void init_entities(game_engine *engine)
{
    sfFont *font = sfFont_createFromFile("assets/arial.ttf");
    game_entity *entity = create_game_entity(
        "assets/cat.png",
        SPRITE,
        &on_cat_update
    );
    game_entity *fps_displayer = create_fps_displayer(font);
    
    register_entity(engine, entity);
    register_entity(engine, fps_displayer);
}

int main()
{
    game_engine *engine = create_engine(
        "My Game",
        NULL,
        NULL
    );

    init_entities(engine);
    sfRenderWindow_setFramerateLimit(engine->window, 120);
    return run_game(engine);
}
