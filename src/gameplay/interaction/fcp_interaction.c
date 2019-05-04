/*
** EPITECH PROJECT, 2019
** rog
** File description:
** function to interact when we're in the fire camp
*/

#include "my.h"
#include "rpg.h"

void destroy_textures_chest_fcp(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_chest_1);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}

void set_fcp_chest_text(global_t *global)
{
    sfText_setFont(global->gameplay->pnj->text_chest_1,
    global->gameplay->pnj->font);
    sfText_setCharacterSize(global->gameplay->pnj->text_chest_1, 35);
    sfText_setColor(global->gameplay->pnj->text_chest_1, sfWhite);
    sfText_setPosition(global->gameplay->pnj->text_chest_1,
    (sfVector2f){800, 650 + 205});
}

void check_interaction_fcp(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        (global->gameplay->x > 1250 && global->gameplay->x < 1350) &&
        (global->gameplay->y > 600 && global->gameplay->y < 800)) {
        global->gameplay->pnj->rect_chest_1.top = 144;
        global->gameplay->pnj->op_chest = 1;
        global->gameplay->pnj->chest_nb1 = 1;
        }
    if (global->gameplay->pnj->chest_nb1 == 1 &&
        ((global->gameplay->x < 1250 || global->gameplay->x > 1350) ||
        (global->gameplay->y < 600 || global->gameplay->y > 800))) {
        global->gameplay->pnj->chest_nb1 = 0;
        destroy_textures_chest_fcp(global);
        }
}

void display_text_fcp(global_t *global)
{
    if (global->gameplay->pnj->chest_nb1 == 1) {
        set_text_box(global);
        global->gameplay->pnj->text_chest_1 = sfText_create();
        sfText_setString(global->gameplay->pnj->text_chest_1,
        "You found the lava boots !!!");
        set_fcp_chest_text(global);
        sfSprite_setPosition(global->gameplay->pnj->s_text_box,
        (sfVector2f){750, 650 + 180});
        sfRenderWindow_drawSprite(global->window,
        global->gameplay->pnj->s_text_box, NULL);
        sfRenderWindow_drawText(global->window,
        global->gameplay->pnj->text_chest_1, NULL);
    }
}