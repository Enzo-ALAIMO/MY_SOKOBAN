/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** check.c
*/

#include <sokoban.h>

static void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, ");
    my_putstr(" containing ‘#’ for walls, \n");
    my_putstr("          ‘P’ for the player, ‘X’ for boxes and ‘O’");
    my_putstr(" for storage locations.\n");
    exit(0);
}

void handle_resize(int sig)
{
    if (sig != SIGWINCH)
        return;
    endwin();
    wresize(stdscr, LINES, COLS);
    refresh();
    clear();
}

void check_map(char *str_map)
{
    for (int i = 0; str_map[i]; i++)
        if (str_map[i] != '#' && str_map[i] != ' ' &&
        str_map[i] != 'X' && str_map[i] != 'O' &&
        str_map[i] != 'P' && str_map[i] != '\n')
            exit(84);
}

int check_error(int ac, char **av)
{
    if (ac != 2)
        return (1);
    if (my_str_isprintable(av[1]) == 0)
        return (1);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        help();
    return (0);
}

