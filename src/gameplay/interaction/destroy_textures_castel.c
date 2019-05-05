/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** destroy textures text in the castel
*/

#include "my.h"
#include "rpg.h"

void destroy_textures_knight_1(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_knight_1);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}

void destroy_textures_knight_2(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_knight_2);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}

void destroy_textures_princess(global_t *global)
{
    sfText_destroy(global->gameplay->pnj->text_princess);
    sfSprite_destroy(global->gameplay->pnj->s_text_box);
    sfTexture_destroy(global->gameplay->pnj->text_box);
}