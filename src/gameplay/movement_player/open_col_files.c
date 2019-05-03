/*
** EPITECH PROJECT, 2019
** open_col_files.c
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"


char **get_map(char *path, char **map)
{
    char *buffer = NULL;
    int fd = 0;
    int i = 0;
    struct stat filepath;

    stat(path, &filepath);
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    i = filepath.st_size;
    buffer = malloc(sizeof(char) * i);
    if (buffer == NULL)
        return (NULL);
    read(fd, buffer, i);
    close(fd);
    map = string_to_tab(buffer);
    free (buffer);
    return (map);
}

int open_file(global_t *global)
{

    global->gameplay->wmap = get_map("resource/CollisionWM.txt",
                    global->gameplay->wmap);
    global->gameplay->mapc_fcp = get_map("resource/CollisionFCP.txt",
                    global->gameplay->mapc_fcp);
    global->gameplay->mapc_vil = get_map("resource/CollisionVil.txt",
                    global->gameplay->mapc_vil);
    global->gameplay->mapc_cas = get_map("resource/CollisionCASL.txt",
                    global->gameplay->wmap);
    global->gameplay->mapc_vol = get_map("resource/CollisionVolc.txt",
                    global->gameplay->mapc_vol);
    global->gameplay->map = global->gameplay->wmap;
    if (global->gameplay->wmap == NULL || 
    global->gameplay->mapc_fcp == NULL || global->gameplay->mapc_vil == NULL)
        return (84);
    return (0);
}