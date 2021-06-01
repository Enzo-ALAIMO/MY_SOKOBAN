/*
** EPITECH PROJECT, 2020
** B-PSU-200-PAR-2-1-mysokoban-enzo.alaimo
** File description:
** conditions.c
*/

#include <sokoban.h>

int solution_count(char *str_map)
{
    int cpt = 0;

    for (int i = 0; str_map[i]; i++) {
        if (str_map[i] == 'O')
            cpt++;
    }
    return (cpt);
}

int boxes_count(char *str_map)
{
    int cpt = 0;

    for (int i = 0; str_map[i]; i++) {
        if (str_map[i] == 'X')
            cpt++;
    }
    return (cpt);
}

coord_t *get_solution_pos(map_t *map)
{
    int i;
    int j;
    int cpt = 0;
    int nb_sol = solution_count(map->str_map);
    coord_t *sol_pos = malloc(sizeof(coord_t) * nb_sol);

    for (i = 0; map->map_str[i]; i++) {
        for (j = 0; map->map_str[i][j]; j++) {
            if (map->map_str[i][j] == 'O') {
                sol_pos[cpt].x = i;
                sol_pos[cpt].y = j;
                cpt++;
            }
        }
    }
    sol_pos->map = nb_sol;
    return (sol_pos);
}

coord_t *get_boxes_pos(map_t *map)
{
    int i;
    int j;
    int cpt = 0;
    int nb_box = boxes_count(map->str_map);
    coord_t *box_pos = malloc(sizeof(coord_t) * nb_box);

    for (i = 0; map->map_str[i]; i++) {
        for (j = 0; map->map_str[i][j]; j++) {
            if (map->map_str[i][j] == 'X') {
                box_pos[cpt].x = i;
                box_pos[cpt].y = j;
                cpt++;
            }
        }
    }
    return (box_pos);
}