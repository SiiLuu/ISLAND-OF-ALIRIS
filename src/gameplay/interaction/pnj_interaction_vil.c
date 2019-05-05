/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** pnj interaction
*/

#include "my.h"
#include "rpg.h"

void destroy_textures_papy_vil(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_papy);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}

void destroy_textures_garden_vil(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_pnj_garden);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}

void check_gardin_interaction(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 2450 && global->gameplay->x < 2600) &&
        (global->gameplay->y > 900 && global->gameplay->y < 1020)) {
        global->gameplay->pnj->p_garden = 1;
        }
    if (global->gameplay->pnj->p_garden == 1 &&
        ((global->gameplay->x < 2450 || global->gameplay->x > 2600) ||
        (global->gameplay->y < 900 || global->gameplay->y > 1020))) {
        global->gameplay->pnj->p_garden = 0;
        destroy_textures_garden_vil(global);
        }
}

void check_interaction_village(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 500 && global->gameplay->x < 710) &&
        (global->gameplay->y > 590 && global->gameplay->y < 750)) {
        global->gameplay->pnj->vil_papy = 1;
        }
    if (global->gameplay->pnj->vil_papy == 1 &&
        ((global->gameplay->x < 500 || global->gameplay->x > 710) ||
        (global->gameplay->y < 590 || global->gameplay->y > 750))) {
        global->gameplay->pnj->vil_papy = 0;
        global->gameplay->pnj->next_text = 0;
        destroy_textures_papy_vil(global);
        }
    check_gardin_interaction(global);
}

void display_text_vill(global_t *global)
{
    if (global->gameplay->pnj->vil_papy == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_papy = sfText_create();
        if (sfKeyboard_isKeyPressed(sfKeyTab))
            global->gameplay->pnj->next_text = 1;
        if (global->gameplay->pnj->next_text == 1)
            set_text_papy_1(global);
        else
            set_text_papy(global);
        set_vil_papy_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){550, global->gameplay->y + 380});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_papy, NULL);
    }
    set_garden_text(global);
}