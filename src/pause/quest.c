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
    sfText_setString(global->pause->st_quest->tquest2, "find and revenge the\
    \t\t\t\tfind the daughter of\npeople of the village of\t\t\t\t\
    KATARINA, who\nVILLEUS by killing\t\t\t\t\t\t\t\tis lost.\
    \nENDUS THE GREAT.");
    sfText_setCharacterSize(global->pause->st_quest->tquest2, 35);
    sfText_setColor(global->pause->st_quest->tquest2, sfBlack);
}