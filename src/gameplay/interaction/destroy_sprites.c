/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** destroy textures
*/

#include "my.h"
#include "rpg.h"

void destroy_textures_quetes_d(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_d);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}

void destroy_textures_quetes_ed(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_ed);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}

void destroy_textures_quetes_pech(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_pech);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}

void destroy_textures_quetes_bot(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_bot);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}

void destroy_textures_quetes_volc(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_volc);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}