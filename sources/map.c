/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** map.c
*/

#include "sokoban.h"

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return (84);
    else
        return (fd);
}

char *read_map(int fd, char *buff, int size)
{
    int value = read(fd, buff, size);
    char *str_map = malloc(sizeof(char) *size + 1);

    if (value == -1) {
        exit(84);
    }
    if (value == 0) {
        exit(84);
    }
    if (value <= size) {
        for (int i = 0; i < size; i++)
            str_map[i] = buff[i];
        return (str_map);
    }
    return (NULL);
}

int check_dim_y(char *str)
{
    int i = 0;
    int j = 0;
    int cpt = 1;

    for (int i = 0; str[i] != '\n'; i++)
        cpt++;
    for (i = cpt; str[i] != '\n'; i++)
        j++;
    return (j);
}

char **mem_alloc_2d_array_char(int y, int x)
{
    int i;
    char **p;

    if (!(p = malloc(sizeof(char *) * x + 1)))
        return (NULL);
    i = 0;
    while (i < x)
        if (!(p[i++] = malloc(y)))
            return (NULL);
    return (p);
}

char **map_2d_array(char *str, int y, int x)
{
    char **arr = mem_alloc_2d_array_char(y, x);
    int t = 0;

    for (int i = 0; i < y; i++) {
        if (str[t] == '\n')
            t++;
        for (int j = 0; j < x; j++) {
            if (str[t] == '\n')
                break;
            arr[i][j] = str[t];
            t++;
        }
    }
    return (arr);
}