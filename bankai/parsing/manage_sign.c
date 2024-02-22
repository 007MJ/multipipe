#include "../include/includes.h"

int space_sign(char *input)
{
    int i;

    i = 0;
    while (input[i] != ' ')
        i++;
    return (i);
}

int manage_sign(char *s1, char *input)
{
    int i;

    i = 0;
    s1 = ft_calloc(space_sign(input), sizeof(char *));
    while (s1[i] != ' ')
    {
        s1[i] = input[i];
        i++;
    }
    s1[i] = '\0';
    return (i);
}