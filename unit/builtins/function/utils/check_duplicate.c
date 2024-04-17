#include "../../../includes/global.h"

char **init_new(char **vars)
{
    char    **new;
    int     len;
    int     i;

    i = 0;
    len = size(vars);
    new =   malloc(sizeof(char *) * (len + 1));
    if (!new)
        return (new[len] = NULL, NULL);
    return (new);
}

char **check_duplicate(char **vars)
{
    char    **new;
    int     i;
    int     j;

    i = 0;
    j = 0;
    new = init_new(vars);
    while (vars[i] != NULL)
    {
        if (ft_strncmp((const char *)vars[i], (const char *)vars[i + 1], ft_strlen((const char *)vars[i])) != 0)
        {
            new[j] = ft_strdup(vars[i]);
            j++;
        }
        i++;
    }
    new[j] = NULL;
    return (new);
}