/*
** EPITECH PROJECT, 2019
** open_col_files.c
** File description:
** my_defender, main function
*/

#include "my.h"
#include "rpg.h"

void free_file(char **map)
{
    int i = 0;

    for (i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

int open_file_dungeons(global_t *global)
{
    global->gameplay->mapc_vol = get_map("resource/CollisionVolc.txt",
                    global->gameplay->mapc_vol);
    global->gameplay->mapc_inpy = get_map("resource/CollisionInPy.txt",
                    global->gameplay->mapc_inpy);
    global->gameplay->mapc_outpy = get_map("resource/CollisionOutpy.txt",
                    global->gameplay->mapc_outpy);
    return (0);
}

int open_file_fc(global_t *global)
{
    global->gameplay->mapc_fcp = get_map("resource/CollisionFCP.txt",
                    global->gameplay->mapc_fcp);
    global->gameplay->mapc_fcn = get_map("resource/CollisionFCN.txt",
                    global->gameplay->mapc_fcn);
    global->gameplay->mapc_fcf = get_map("resource/CollisionFCF.txt",
                    global->gameplay->mapc_fcf);
    return (0);
}

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
    buffer = malloc(sizeof(char) * i + 1);
    if (buffer == NULL)
        return (NULL);
    for (int j = 0; j != i + 1; j++)
        buffer[j] = '\0';
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
    global->gameplay->mapc_vil = get_map("resource/CollisionVil.txt",
                    global->gameplay->mapc_vil);
    global->gameplay->mapc_cas = get_map("resource/CollisionCASL.txt",
                    global->gameplay->wmap);
    global->gameplay->mapc_viln = get_map("resource/CollisionVILN.txt",
                    global->gameplay->mapc_viln);
    global->gameplay->mapc_casn = get_map("resource/CollisionCASN.txt",
                    global->gameplay->mapc_casn);
    global->gameplay->mapc_fcas = get_map("resource/CollisionCASF.txt",
                    global->gameplay->mapc_fcas);
    global->gameplay->map = global->gameplay->wmap;
    open_file_fc(global);
    open_file_dungeons(global);
    return (0);
}