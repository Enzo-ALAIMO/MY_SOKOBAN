/*
** EPITECH PROJECT, 2020
** B-PSU-200-PAR-2-1-mysokoban-enzo.alaimo
** File description:
** end_conditions.c
*/

#include <sokoban.h>

int victory(coord_t *solution, coord_t *boxes, map_t *map)
{
    int nb_sol = solution_count(map->str_map);

    for (int i = 0; i < nb_sol; i++) {
        if ((solution[i].x == boxes[i].x) && (solution[i].y == boxes[i].y)) {
            continue;
        } else
            return (1);
    }
    return (0);
}

int defeat (coord_t *boxes, map_t *map)
{
    int nb_stuck = 0;

    for (int i = 0; i < boxes_count(map->str_map); i++) {
        if ((map->map_str[boxes[i].x - 1][boxes[i].y] == '#' ||
        map->map_str[boxes[i].x - 1][boxes[i].y] == 'X') &&
        (map->map_str[boxes[i].x][boxes[i].y - 1] == '#' ||
        map->map_str[boxes[i].x][boxes[i].y + 1] == '#' ||
        map->map_str[boxes[i].x][boxes[i].y - 1] == 'X' ||
        map->map_str[boxes[i].x][boxes[i].y + 1] == 'X'))
            nb_stuck++;
        if ((map->map_str[boxes[i].x + 1][boxes[i].y] == '#' ||
        map->map_str[boxes[i].x + 1][boxes[i].y] == 'X') &&
        (map->map_str[boxes[i].x][boxes[i].y - 1] == '#' ||
        map->map_str[boxes[i].x][boxes[i].y + 1] == '#' ||
        map->map_str[boxes[i].x][boxes[i].y - 1] == 'X' ||
        map->map_str[boxes[i].x][boxes[i].y + 1] == 'X'))
            nb_stuck++;
    }
    if (nb_stuck == boxes_count(map->str_map))
        return (1);
    return (0);
}

void check_end_condition(struct_t *list, map_t *map)
{
    if (victory(list->solution, list->boxes, map) == 0) {
        endwin();
        exit(0);
    }
    if (defeat(list->boxes, map) == 1) {
        endwin();
        exit(1);
    }
}