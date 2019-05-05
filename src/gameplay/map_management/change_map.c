/*
** EPITECH PROJECT, 2019
** change_map.c
** File description:
** manage the map scenes
*/

#include "rpg.h"
#include "my.h"

void create_map_sprites(global_t *global)
{
    global->gameplay->backg = sfTexture_createFromFile(
        "resource/World Map.jpg", NULL);
    global->gameplay->backg_fcp = sfTexture_createFromFile(
        "resource/Firecamp Plaine.jpg", NULL);
    global->gameplay->backg_fcn = sfTexture_createFromFile(
        "resource/FC Neige.jpg", NULL);
    global->gameplay->backg_fcf = sfTexture_createFromFile(
        "resource/FC Forest.jpg", NULL);
    global->gameplay->backg_vil = sfTexture_createFromFile(
        "resource/Village de départ.jpg", NULL);
    global->gameplay->backg_cas = sfTexture_createFromFile(
        "resource/Castle.jpg", NULL);
    global->gameplay->backg_vol = sfTexture_createFromFile(
        "resource/Volcano.jpg", NULL);
    global->gameplay->backg_viln = sfTexture_createFromFile(
        "resource/Snow Village.jpg", NULL);
    global->gameplay->backg_casn = sfTexture_createFromFile(
        "resource/Snow Castle.jpg", NULL);
}
bool check_scn_nbr(int scn)
{
    if (scn == 1 || scn == 10 || scn == 11 || scn == 12 || scn == 13
    || scn == 14 || scn == 15 || scn == 16 || scn == 17 || scn == 18
    || scn == 20 || scn == 21 || scn == 22 || scn == 23)
        return (true);
    return (false);
}

int check_map_change(global_t *global, int scn)
{
    int pos_x = (global->gameplay->x + 50);
    int pos_y = (global->gameplay->y + 50);
    int mpos_x = pos_x / 100;
    int mpos_y = pos_y / 100;

    if (scn == 1 || scn == 17) {
        scn = check_enter_builds(global, mpos_x, mpos_y, scn);
        return (scn);
    }
    else {
        scn = check_leave_builds(global, mpos_x, mpos_y, scn);
    }
    return (scn);
}