#include "../../../includes/global.h"

char *ft_cpyvar(char *s)
{
    int i;
    char *c;

    i = 0;
    while (s[i] != '=' && s[i] == '\0')
        i++;
    c = malloc(sizeof(char *) * (i + 1));
    if (!c)
        return (NULL);
    i = 0;
    while (s[i] != '=' && s[i] != '\0')
    {
        c[i] = s[i];
        i++;
    }
    c[i] = '\0';
    return (c);
}

int same_var_value(char **envp, char *var)
{
    int i;

    i = 0;
    if (same_varibale(envp, ft_cpyvar(var)) == 1)
        return (1);
    return (0);
}