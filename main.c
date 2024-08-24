/*
** EPITECH PROJECT, 2024
** csfml-game-engine
** File description:
** main
*/

#include <SFML/Graphics.h>
#include "engine.h"
#include "entity.h"
#include "scenes.h"
#include "entities/fps_display.h"
#include <stdio.h>

const int speed = 400;

static void on_cat_update(float delta, game_entity *entity)
{
    sfVector2f position = sfSprite_getPosition(entity->element.sprite);

    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp))
        position.y -= speed * delta;
    if (sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyDown))
        position.y += speed * delta;
    if (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyLeft))
        position.x -= speed * delta;
    if (sfKeyboard_isKeyPressed(sfKeyD) || sfKeyboard_isKeyPressed(sfKeyRight))
        position.x += speed * delta;
    sfSprite_setPosition(entity->element.sprite, position);
}

scene_entity *default_scene(game_engine *engine)
{
    scene_entity *scene;
    sfFont *font = sfFont_createFromFile("assets/arial.ttf");
    game_entity *cat_entity = create_game_entity(
        "assets/cat.png",
        SPRITE,
        &on_cat_update
    );
    game_entity *fps_displayer_entity = create_fps_displayer(font);

    scene = create_scene(
        new_list_entity(),
        NULL,
        NULL,
        "assets/coloss.mp3"
    );
    register_entity(scene, cat_entity);
    register_entity(scene, fps_displayer_entity);
    return scene;
}

int main()
{
    game_engine *engine = create_engine(
        "My Game",
        NULL,
        NULL
    );
    scene_entity *scene = default_scene(engine);

    engine->scene = scene;
    sfRenderWindow_setFramerateLimit(engine->window, 120);
    return run_game(engine);
}
