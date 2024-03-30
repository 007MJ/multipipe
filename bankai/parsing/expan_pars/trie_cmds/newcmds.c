#include "../../../include/includes.h"

char **newcmds(char **olds, char *n)
{
    char **new;
    int size;

    size = sizecmds(olds, n);
    new = malloc(sizeof(char *) * (size + 1));
    new[size] = NULL;
    if (!new)
        return (NULL);
    ft_cpycmds(new, olds, n);
    return (new);
}