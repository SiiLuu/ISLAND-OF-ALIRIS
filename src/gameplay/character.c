/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function to the gameplay
*/

#include "my.h"
#include "rpg.h"

void check_next_events(global_t *global)
{
    if ((but_is_c(global->event, global->pause->quest) == 1) &&
        (global->scn == 2))
        global->scn = 4;
    if (global->event.key.code == sfKeyEscape && global->scn > 0 &&
        global->scn != 2) {
        if (global->scn != 4 && global->scn != 3)
            global->old_scn = global->scn;
        global->scn = 2;
    }
    if ((item_is_c(global->event, global->gameplay->item->boots) == 1) &&
        (global->scn == 3)) {
        sfSprite_setPosition(global->gameplay->item->boots,
            (sfVector2f){1045,320});
        sfSprite_setScale(global->gameplay->item->boots,
            (sfVector2f){3.45, 3.45});
    }
}

void check_events_scn(global_t *global)
{
    if ((item_is_c(global->event, global->gameplay->item->orbs) == 1) &&
        (global->scn == 3)) {
        sfSprite_setPosition(global->gameplay->item->orbs,
            (sfVector2f){1045, 490});
        sfSprite_setScale(global->gameplay->item->orbs,
            (sfVector2f){2.2, 1.8});
    }
    if ((item_is_c(global->event, global->gameplay->item->armors) == 1) &&
        (global->scn == 3)) {
        sfSprite_setPosition(global->gameplay->item->armors,
            (sfVector2f){1045,320});
        sfSprite_setScale(global->gameplay->item->armors,
            (sfVector2f){1.98, 2.1});
    }
    if ((item_is_c(global->event, global->gameplay->item->axes) == 1) &&
        (global->scn == 3)) {
        sfSprite_setPosition(global->gameplay->item->axes,
            (sfVector2f){1045, 150});
        sfSprite_setScale(global->gameplay->item->axes,
            (sfVector2f){2.15, 2.1});
    }
}

void check_events_scn_2(global_t *global)
{
    if ((item_is_c(global->event, global->gameplay->item->helmets) == 1) &&
        (global->scn == 3)) {
        sfSprite_setPosition(global->gameplay->item->helmets,
            (sfVector2f){1605, 320});
        sfSprite_setScale(global->gameplay->item->helmets,
            (sfVector2f){1.95, 2.0});
    }
    if (global->event.key.code == sfKeyTab && global->scn == -2)
        global->scn = -1;
    if (global->event.key.code == sfKeySpace && (global->scn == -2 ||
        global->scn == -1))
        global->scn = 0;
    move_character(global);
}

void check_first_events(global_t *global)
{
    if (global->event.type == sfEvtClosed)
        sfRenderWindow_close(global->window);
    if ((but_is_c(global->event, global->menu->start1) == 1) &&
        (global->scn == 2)) {
        global->scn = global->old_scn;
        move_vue(global);
    }
    if ((but_is_c(global->event, global->menu->quit1) == 1) &&
        (global->scn == 2))
        sfRenderWindow_close(global->window);
    if ((but_is_c(global->event, global->pause->inv) == 1) &&
        (global->scn == 2))
        global->scn = 3;
}

void set_position_boss_volc(global_t *global)
{
    sfSprite_setTextureRect(global->gameplay->boss->sp_hl_boss,
    global->gameplay->boss->rect_hl_boss);
    sfSprite_setPosition(global->gameplay->boss->sp_hl_boss,
    (sfVector2f){400, 5700});
    sfSprite_setScale(global->gameplay->boss->sp_hl_boss,
    (sfVector2f){1.5, 1.5});
    sfSprite_setTextureRect(global->gameplay->boss->sp_volc_boss,
    global->gameplay->boss->rect_volc_boss);
    sfSprite_setPosition(global->gameplay->boss->sp_volc_boss,
    (sfVector2f){1200, 1325});
    sfSprite_setScale(global->gameplay->boss->sp_volc_boss,
    (sfVector2f){1.5, 1.5});
}