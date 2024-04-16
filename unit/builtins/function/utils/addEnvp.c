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

int ft_strchr(char *s, char c)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}
char **new_envp(char **envp, char **vars)
{
     char    **new;
    int     len;
    int     len2;
    int     i;

    i = 0;
    len = size(envp);
    len2 = size(vars);
    new = malloc(sizeof(char **) * (len + len2 + 1));
    if (!new)
        return (NULL);
    new[len + len2] = NULL;
    while ( i < len)
    {
        new[i] = envp[i];
        i++;
    }
    return (new);
}
char **addEnvp(char **envp, char **vars)
{
    int     i;
    int     j;
    int     is;
    char    **new;

    i = size(envp);
    j = 0;
    new = new_envp(envp, vars);
    while (j < size(vars))
    {
        is = is_add(new, vars[j], ft_strchr(vars[j], '='));
        if (is == 0)
            new[i] = vars[j];
        i++;
        j++;
    }
    return (new);
}
