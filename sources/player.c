/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** util.c
*/

#include "sokoban.h"

coord_t *player_init_pos(coord_t *player, map_t *map)
{
    int j;
    int i;
    player->x = 0;
    player->y = 0;
    player->map = get_x(map->str_map);

    for (i = 0; map->map_str[i]; i++) {
        for (j = 0; map->map_str[i][j]; j++) {
            if (map->map_str[i][j] == 'P') {
                player->x = j;
                player->y = i;
            }
        }
    }
    return (player);
}

static int check_box_movement(map_t *map, int key, coord_t *player)
{
    if (key == KEY_UP && (map->map_str[player->y - 1][player->x] == 'X' &&
    ((map->map_str[player->y - 2][player->x] == '#' ||
    map->map_str[player->y - 2][player->x] == 'X') || player->y - 2 <= 0)))
        return (1);
    if (key == KEY_DOWN && (map->map_str[player->y + 1][player->x] == 'X' &&
    ((map->map_str[player->y + 2][player->x] == '#' ||
    map->map_str[player->y + 2][player->x] == 'X') ||
    player->y + 2 >= get_x(map->str_map))))
        return (1);
    if (key == KEY_LEFT && (map->map_str[player->y][player->x - 1] == 'X' &&
    ((map->map_str[player->y][player->x - 2] == '#' ||
    map->map_str[player->y][player->x - 2] == 'X') || player->y - 2 <= 0)))
        return (1);
    if (key == KEY_RIGHT && (map->map_str[player->y][player->x + 1] == 'X' &&
    ((map->map_str[player->y][player->x + 2] == '#' ||
    map->map_str[player->y][player->x + 2] == 'X') ||
    player->x + 2 >= get_y(map->str_map))))
        return (1);
    return (0);
}

static int check_player_movement(map_t *map, int key, coord_t *player)
{
    if ((key == KEY_UP && (map->map_str[player->y - 1][player->x] == '#' ||
        check_box_movement(map, key, player) == 1)) ||
        (key == KEY_UP && (player->y - 1) <= 0))
        return (-1);
    if ((key == KEY_DOWN && (map->map_str[player->y + 1][player->x] == '#' ||
        check_box_movement(map, key, player) == 1)) ||
        (key == KEY_DOWN && (player->y + 1) >= get_x(map->str_map)))
        return (-1);
    if ((key == KEY_LEFT && (map->map_str[player->y][player->x - 1] == '#' ||
        check_box_movement(map, key, player) == 1)) ||
        (key == KEY_LEFT && (player->x - 1) <= 0))
        return (-1);
    if ((key == KEY_RIGHT && (map->map_str[player->y][player->x + 1] == '#' ||
        check_box_movement(map, key, player) == 1)) ||
        (key == KEY_RIGHT && (player->x + 1) >= get_y(map->str_map)))
        return (-1);
    return (0);
}

char **player_mvt_update(map_t *map, int key, coord_t *player,
coord_t *solution)
{
    if (check_player_movement(map, key, player) == (-1))
        return (map->map_str);
    if (key == KEY_UP)
        map->map_str = player_up(map->map_str, player);
    if (key == KEY_DOWN)
        map->map_str = player_down(map->map_str, player);
    if (key == KEY_LEFT)
        map->map_str = player_left(map->map_str, player);
    if (key == KEY_RIGHT)
        map->map_str = player_right(map->map_str, player);
    display_solutions(map, player, solution);
    return (map->map_str);
}

