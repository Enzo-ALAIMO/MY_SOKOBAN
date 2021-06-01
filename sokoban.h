/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H
#define _GNU_SOURCE

#include <ncurses.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef struct coord_s
{
    int map;
    int x;
    int y;
} coord_t;

typedef struct map_s
{
    char *str_map;
    char **map_str;
    char *filepath;
} map_t;

typedef struct struct_s
{
    coord_t *player;
    coord_t *solution;
    coord_t *boxes;
} struct_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char *str);
int fs_open_file(char const *filepath);
char *read_map(int fd, char *buff, int size);
int check_dim_y(char *str);
char **mem_alloc_2d_array_char(int y, int x);
char **map_2d_array(char *str, int y, int x);
char **init_map(char *filepath, map_t *map);
char **player_mvt_update(map_t *map, int key, coord_t *player,
    coord_t *solution);
char **player_up(char **map_str, coord_t *player);
char **player_down(char **map_str, coord_t *player);
char **player_left(char **map_str, coord_t *player);
char **player_right(char **map_str, coord_t *player);
char **display_solutions(map_t *map, coord_t *player, coord_t *sol_pos);
char **reset_map(char *filepath, coord_t *player, map_t *map);
int my_str_isprintable(char const *str);
int check_error(int ac, char **av);
void check_map(char *str_map);
int get_x(char *map);
int get_y(char *map);
int solution_count(char *str_map);
int boxes_count(char *str_map);
coord_t *player_init_pos(coord_t *player, map_t *map);
coord_t *get_solution_pos(map_t *map);
coord_t *get_boxes_pos(map_t *map);
int victory(coord_t *solution, coord_t *boxes, map_t *map);
int defeat (coord_t *boxes, map_t *map);
void check_end_condition(struct_t *list, map_t *map);
void handle_resize(int sig);

#endif