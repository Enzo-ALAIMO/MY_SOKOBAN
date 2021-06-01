/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** map.c
*/

#include "sokoban.h"

int get_y(char *map)
{
    int i;

    for (i = 0; map[i] != '\n'; i++);
    return (i);
}

int get_x(char *map)
{
    int cpt = 0;

    for (int i = 0; map[i]; i++)
        if (map[i] == '\n')
            cpt++;
    return (cpt + 1);
}

char **init_map(char *filepath, map_t *map)
{
    struct stat st;
    int x;
    int y;
    char *buff;
    int res = fs_open_file(filepath);

    stat(filepath, &st);
    buff = malloc(sizeof(char) * st.st_size);
    map->str_map = read_map(res, buff, st.st_size);
    y = get_y(map->str_map);
    x = get_x(map->str_map);
    map->map_str = map_2d_array(map->str_map, x, y);
    return (map->map_str);
}

char **reset_map(char *filepath, coord_t *player, map_t *map)
{
    char **map_str = init_map(filepath, map);

    player = player_init_pos(player, map);
    return (map_str);
}