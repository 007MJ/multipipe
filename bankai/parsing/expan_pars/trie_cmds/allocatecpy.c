
#include "../../../include/includes.h"

char *    allocatecpy( char *src)
{
    // use ft_strdup();
    int i;
    char *new;

    i = 0;
    new = malloc(sizeof(char *) * ft_strlen(src) + 1);
    if (!new)
        return NULL;
    while (src[i] != '\0')
    {
        new[i] = src[i];
        i++;
    }
    new[i] = '\0';
    return new;
}
