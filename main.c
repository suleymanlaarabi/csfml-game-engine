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
#include "animation.h"
#include "entities/fps_display.h"
#include <stdio.h>

const int speed = 400;

static void on_cat_update(float delta, game_entity *entity)
{
    sfVector2f position = sfSprite_getPosition(
        entity->element->animated_sprite->tiles->sprite);
    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp))
        position.y -= speed * delta;
    if (sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyDown))
        position.y += speed * delta;
    if (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyLeft))
        position.x -= speed * delta;
    if (sfKeyboard_isKeyPressed(sfKeyD) || sfKeyboard_isKeyPressed(sfKeyRight))
        position.x += speed * delta;
    sfSprite_setPosition(
        entity->element->animated_sprite->tiles->sprite, position);
}

scene_entity *default_scene(game_engine *engine)
{
    scene_entity *scene;
    entity_element *element = create_entity_element(
        create_animated_sprite(
        1, 8, 0.09, create_tiles_sprite("assets/sprites.png", 80, 80))
    );
    game_entity *background = create_game_entity(
        "assets/arena.png", SPRITE, NULL, NULL);
    game_entity *cat_entity = create_game_entity(
        NULL, ANIMATED_SPRITE, &on_cat_update, element);
    game_entity *fps_module = create_fps_displayer(
        sfFont_createFromFile("assets/arial.ttf"));

    scene = create_scene(
        new_list_entity(),
        NULL,
        NULL,
        "assets/coloss.mp3");
    register_entity(scene, background);
    register_entity(scene, cat_entity);
    register_entity(scene, fps_module);
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
