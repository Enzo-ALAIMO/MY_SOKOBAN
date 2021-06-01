/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** main.c
*/

#include "sokoban.h"

static void map_init(void)
{
    curs_set(0);
    initscr();
    noecho();
    keypad(stdscr, true);
}

static void in_game (int key, map_t *map, struct_t *list, struct sigaction s)
{
    int mapX = get_x(map->str_map);
    int mapY = get_y(map->str_map) - 1;

    if (LINES < mapX || COLS < mapY)
        mvprintw(LINES / 2, COLS / 2 - 5, "Too small");
    else {
        for (int i = 0; map->map_str[i]; i++) {
            mvprintw(LINES / 2 - (mapX / 2) + i, COLS / 2 -
            (my_strlen(map->map_str[i]) / 2), "%s\n", map->map_str[i]);
            list->boxes = get_boxes_pos(map);
        }
    }
    refresh();
    sigaction(SIGWINCH, &s, NULL);
    check_end_condition(list, map);
    key = getch();
    if (key == ' ')
        map->map_str = reset_map(map->filepath, list->player, map);
    map->map_str = player_mvt_update(map, key, list->player,
    list->solution);
}

static void game_loop(int key, map_t *map, struct_t *list)
{
    struct sigaction s;

    s.sa_handler = handle_resize;
    map_init();
    while (key != 1) {
        in_game(key, map, list, s);
    }
    endwin();
}

void sokoban(int key, map_t *map, struct_t *list)
{
    list->solution = malloc(sizeof(coord_t));
    list->boxes = malloc(sizeof(coord_t));
    list->solution = get_solution_pos(map);
    game_loop(key, map, list);
}

int main(int ac, char **av)
{
    int key = -1;
    struct_t *list = malloc(sizeof(struct_t));
    list->player = malloc(sizeof(coord_t));
    map_t *map = malloc(sizeof(map_t));

    if (check_error(ac, av) == 1)
        return (84);
    map->filepath = av[1];
    map->map_str = init_map(av[1], map);
    list->player = player_init_pos(list->player, map);
    check_map(map->str_map);
    sokoban(key, map, list);
    return (0);
}