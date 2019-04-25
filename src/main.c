/*
** EPITECH PROJECT, 2019
** main fonction
** File description:
** my_defender, main function
*/
#include "my.h"
#include "rpg.h"

void game_parameters(gameplay_t *gameplay, global_t *global)
{
    check_events(global, gameplay);
    draw_sprites(gameplay, global);
}


int main_loop(global_t *global, gameplay_t *gameplay)
{
    gameplay->clocks = sfClock_create();
    gameplay->view = sfView_create();

    gameplay->x = 300;
    gameplay->y = 600;
    init_texture(gameplay);
    sfRenderWindow_setFramerateLimit(global->window, 60);
    if (menu_start(global, 0) || global->event.type == sfEvtClosed) {
        sfClock_destroy(gameplay->clocks);
        return (0);
    }
    sfView_reset(gameplay->view, (sfFloatRect){0, 98, 1920, 1080});
    sfRenderWindow_setView(global->window, gameplay->view);
    while (sfRenderWindow_isOpen(global->window)) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(gameplay->clocks)) > 5) {
            game_parameters(gameplay, global);
            sfClock_restart(gameplay->clocks);
        }
    }
    return (0);
}

void destroy_all(global_t *global)
{
    sfSprite_destroy(global->menu->wp);
    sfSprite_destroy(global->menu->start1);
    sfSprite_destroy(global->menu->quit1);
    sfSprite_destroy(global->menu->start2);
    sfSprite_destroy(global->menu->sounds);
    sfSprite_destroy(global->menu->nosound);
    sfSprite_destroy(global->menu->settingsa);
    sfTexture_destroy(global->menu->wpt);
    sfTexture_destroy(global->menu->start1t);
    sfTexture_destroy(global->menu->quit1t);
    sfTexture_destroy(global->menu->start2t);
    sfTexture_destroy(global->menu->soundt);
    sfTexture_destroy(global->menu->no_soundt);
    sfTexture_destroy(global->menu->settings->settingst);
}

void main_function(gameplay_t *gameplay)
{
    global_t *global;

    global = malloc(sizeof(global_t) * 1);
    global->menu = malloc(sizeof(menu_t) * 1);
    global->choose_char = malloc(sizeof(choose_char_t) * 1);
    global->menu->settings = malloc(sizeof(settings_t) * 1);
    sfVideoMode mode = {1920, 1080, 32};
    global->window = sfRenderWindow_create(mode, "my_RPG",
                                            sfFullscreen | sfClose, NULL);
    global->menu->settings->sound = 0;
    global->menu->settings->nbr_bar = 4;
    music_game(global);
    main_loop(global, gameplay);
    music_destroy(global);
    sfRenderWindow_destroy(global->window);
    destroy_all(global);
    free(global->menu->settings);
    free(global->menu);
    free(global);
}

int open_file(char **av, gameplay_t *gameplay)
{
    struct stat filepath;
    char *buffer = NULL;
    int fd = 0;
    int i = 0;

    stat(av[1], &filepath);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (84);
    i = filepath.st_size;
    buffer = malloc(sizeof(char) * i);
    if (buffer == NULL)
        return (84);
    read(fd, buffer, i);
    close(fd);
    gameplay->buffer = buffer;
    string_to_tab(gameplay);
    return (0);
}

int main(int ac, char **av)
{
    gameplay_t *gameplay;

    gameplay = malloc(sizeof(gameplay_t) * 1);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("USAGE:\n        ./my_defender\n");
        my_putstr("DESCRIPTION:\n\tto win prevent the enemies to save\n");
        my_putstr("\tthemselves in the water. for that place turrets on\n");
        my_putstr("\tthe map to kill enemies, attention your money is\n");
        my_putstr("\tnot infinite and all the turrets are different\n ");
        my_putstr("\twith different abilities. GOOD LUCK TO YOU !\n");
        return (1);
    }
    if (ac != 2)
        return (84);
    if (open_file(av, gameplay) == 84)
        return (84);
    else
        main_function(gameplay);
    free(gameplay);
    return (1);
}
