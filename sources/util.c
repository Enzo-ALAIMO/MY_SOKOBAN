/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** util.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        my_putchar(str[a]);
    return (0);
}

int my_strlen(char *str)
{
    int i = 0;

    for (int b = 0; str[b] != '\0'; b++)
        i = i + 1;
    return (i);
}

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 126)
            return (0);
    }
    return (1);
}