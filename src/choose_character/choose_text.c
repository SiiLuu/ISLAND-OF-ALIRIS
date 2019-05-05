/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** menu
*/

#include "my.h"
#include "rpg.h"

void string_p(global_t *global)
{
    sfText_setString(global->choose_char->te2,
    "Agile warrior, endowed\t\t\t Bloody sorceress, NEBULLA has\t\t  \
    Old mage, despite his\t\t\t\t  Knight of the Trooper of\t\t\t\t\t\
    \nwith a resistance and a\t\t    a lot of damage, however\t\t\t \
    advanced age Twisto remains\t\t\tCavelo, Lord is without\t\
    \nbalanced power, VENOS knows\tshe remains weak in the body\t  \
    one of the toughest opponents\t\t  a doubt the most ferocious\
    \nhow to do everything.\t\t\t   and quickly becomes vulnerable  \
    thanks to his knowledge of black\t  warrior and resistant to\
    \n\t\t\t\t\t\t\t\t\t\t\t in the fighting closer.\t\t\t\t\
    magic. It inflicts a lot of damage\t\tthe closes fight. He is\
    \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\tbut remains vulnerable to very\t\t endowed with great\
    \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\
    agile opponents.\t\t\t\t\t\t\t   courage pushing him\n\t\t\t\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t tamed all kinds of\
    \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\
    \t\t\t\t\t\t opponents.");
}

void choose_create3(global_t *global)
{
    global->choose_char->te = create_text(
        global->choose_char->te, global->pause->st_inv->eqf);
    sfText_setString(global->choose_char->te,
    "VENOS\t\t\tNEBULLA\t\t\tTWISTO\t\t\t    LORD");
    sfText_setCharacterSize(global->choose_char->te, 60);
    sfText_setPosition(global->choose_char->te, (sfVector2f){100, 200});
    global->choose_char->te2 = create_text(
        global->choose_char->te2, global->pause->st_inv->eqf);
    string_p(global);
    sfText_setCharacterSize(global->choose_char->te2, 25);
    sfText_setPosition(global->choose_char->te2, (sfVector2f){30, 735});
}