#include "../../../include/includes.h"

char **newav(char *av)
{
    char    **v;
    int     i;
    int     j;

    j = 0;
    i = 0;
    v = malloc(sizeof(char *) * 2);
    if (!v)
        return (NULL);
    v[i] =  malloc(sizeof(char *) * (ft_strlen(av) + 1));
    while (av[j] != '\0')
    {
        v[i][j] = av[j];
        j++;
    }
    v[i][j] = '\0';
    v[i + 1] = NULL;
    return (v);  
}