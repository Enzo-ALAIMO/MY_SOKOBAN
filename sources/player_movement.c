/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** util.c
*/

#include "sokoban.h"

char **player_up(char **map_str, coord_t *player)
{
    if (map_str[player->y - 1][player->x] == 'X') {
        map_str[player->y][player->x] = ' ';
        player->y--;
        map_str[player->y][player->x] = 'P';
        player->y--;
        map_str[player->y][player->x] = 'X';
        player->y++;
    } else {
        map_str[player->y][player->x] = ' ';
        player->y--;
        map_str[player->y][player->x] = 'P';
    }
    return (map_str);
}

char **player_down(char **map_str, coord_t *player)
{
    if (map_str[player->y + 1][player->x] == 'X') {
        map_str[player->y][player->x] = ' ';
        player->y++;
        map_str[player->y][player->x] = 'P';
        player->y++;
        map_str[player->y][player->x] = 'X';
        player->y--;
    } else {
        map_str[player->y][player->x] = ' ';
        player->y++;
        map_str[player->y][player->x] = 'P';
    }
    return (map_str);
}

char **player_left(char **map_str, coord_t *player)
{
    if (map_str[player->y][player->x - 1] == 'X') {
        map_str[player->y][player->x] = ' ';
        player->x--;
        map_str[player->y][player->x] = 'P';
        player->x--;
        map_str[player->y][player->x] = 'X';
        player->x++;
    } else {
        map_str[player->y][player->x] = ' ';
        player->x--;
        map_str[player->y][player->x] = 'P';
    }
    return (map_str);
}

char **player_right(char **map_str, coord_t *player)
{
    if (map_str[player->y][player->x + 1] == 'X') {
        map_str[player->y][player->x] = ' ';
        player->x++;
        map_str[player->y][player->x] = 'P';
        player->x++;
        map_str[player->y][player->x] = 'X';
        player->x--;
    } else {
        map_str[player->y][player->x] = ' ';
        player->x++;
        map_str[player->y][player->x] = 'P';
    }
    return (map_str);
}

char **display_solutions(map_t *map, coord_t *player, coord_t *sol_pos)
{
    int nb_sol = solution_count(map->str_map);

    for (int i = 0; i < nb_sol; i++)
        if (map->map_str[player->y][player->x] !=
        map->map_str[sol_pos[i].x][sol_pos[i].y] &&
        (map->map_str[sol_pos[i].x][sol_pos[i].y] != 'X'))
            map->map_str[sol_pos[i].x][sol_pos[i].y] = 'O';
    return (map->map_str);
}