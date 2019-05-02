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
}

void destroy_textures_quetes_ed(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_ed);
}

void destroy_textures_quetes_pech(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_pech);
}

void destroy_textures_quetes_bot(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_bot);
}