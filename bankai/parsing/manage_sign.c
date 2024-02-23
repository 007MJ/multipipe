#include "../include/includes.h"

int space_sign(char *input)
{
    int i;

    i = 0;
    while (input[i] != ' ' && input[i] != '\0')
        i++;
    return (i);
}

int manage_sign(char *s1, char *input)
{
    int i;

    i = 0;
    s1 = ft_calloc(space_sign(input), sizeof(char *));
     printf("[Manage sign ]Start -- pars -- %s  .....\n", input);
    if (s1)
    {
        while (input[i] != ' ' && input[i] != '\0')
        {
            printf("while sign %c :.. \n", s1[i]);
            s1[i] = input[i];
            i++;
        }
        s1[i] = '\0';
    }
    printf("End pars -- [%s]-- \n", s1);
    return (i);
}