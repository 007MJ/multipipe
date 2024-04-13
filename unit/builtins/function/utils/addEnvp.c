#include "../../../includes/global.h"

int size(char **env)
{
    int i;

    i = 0;
    if (env)
        while (env[i] != NULL)
            i++;
    return (i);
}
void free_str_envp(char **str)
{
    int i;

    i = 0;
    while (str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
}
char **addEnvp(char **envp, char **vars)
{
    char    **new;
    int     len;
    int     len2;
    int     i;
    int     j;

    i = 0;
    j = 0;
    len = size(envp);
    len2 = size(vars);
    new = malloc(sizeof(char **) * (len + len + 1));
    if (!new)
        return (NULL);
    new[len + len2] = NULL;
    while ( i < len)
    {
        new[i] = envp[i];
        i++;
    }
    while (j < len2)
    {
        new[i] = vars[j];
        i++;
        j++;
    }
    free_str_envp(envp);
    return (new);
}