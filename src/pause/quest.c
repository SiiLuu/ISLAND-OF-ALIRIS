/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

void init_texts_quest(global_t *global)
{
    global->pause->st_quest->tquest = create_text(
        global->pause->st_quest->tquest, global->pause->st_inv->eqf);
    global->pause->st_quest->tquest2 = create_text(
        global->pause->st_quest->tquest2, global->pause->st_inv->eqf);
    sfText_setString(global->pause->st_quest->tquest, "INVENTORY");
    sfText_setString(global->pause->st_quest->tquest,
    "PRIMARY QUEST\t  SECONDARY QUEST");
    sfText_setCharacterSize(global->pause->st_quest->tquest, 60);
    sfText_setColor(global->pause->st_quest->tquest, sfBlack);
    sfText_setString(global->pause->st_quest->tquest2, "INVENTORY");
    sfText_setString(global->pause->st_quest->tquest2,
    "Exterminate all threats\t\t\t\tFind the daughter of\
    \n of the island of Aliris.\t\t\t\t KATARINA, who is lost.\n\n\n\
    \nFind and kill\nENDUS THE GREAT.");
    sfText_setCharacterSize(global->pause->st_quest->tquest2, 35);
    sfText_setColor(global->pause->st_quest->tquest2, sfBlack);
}

void init_how_to_play(global_t *global)
{
    global->pause->st_htp->htp_bck = sfSprite_create();
    global->pause->st_htp->htpt_bck = sfTexture_createFromFile(
        "resource/bck_h.jpg", NULL);
    sfSprite_setTexture(global->pause->st_htp->htp_bck,
        global->pause->st_htp->htpt_bck, sfTrue);
    sfSprite_setScale(global->pause->st_htp->htp_bck, (sfVector2f){1, 1.15});
}

void init_instruct(global_t *global)
{
    global->pause->st_htp->ins1_bck = sfSprite_create();
    global->pause->st_htp->ins1t_bck = sfTexture_createFromFile(
        "resource/ins1_bck.jpg", NULL);
    sfSprite_setTexture(global->pause->st_htp->ins1_bck,
        global->pause->st_htp->ins1t_bck, sfTrue);
    sfSprite_setScale(global->pause->st_htp->ins1_bck, (sfVector2f){1, 1.15});
    global->pause->st_htp->ins2_bck = sfSprite_create();
    global->pause->st_htp->ins2t_bck = sfTexture_createFromFile(
        "resource/ins2_bck.jpg", NULL);
    sfSprite_setTexture(global->pause->st_htp->ins2_bck,
        global->pause->st_htp->ins2t_bck, sfTrue);
    sfSprite_setScale(global->pause->st_htp->ins2_bck, (sfVector2f){1, 1.15});
}