#include "../../../includes/global.h"

bool is_same(char *s, char *v)
{
    int i;

    i = 0;
    while (s[i] != '\0' && s[i] != '=' && i < (int)ft_strlen(v))
    {
        if (s[i] == v[i])
        {
            // printf("%c and %c\n", s[i], v[i]);
            i++;
        }
        else 
            return (false);
    }
    // printf(" %c -- \n", s[i]);
    // printf("====================================\n");
    if (v[i] == '\0' && s[i] == '=')
        return (printf("we are at the end of var \n")), (true);
    return (printf("done !\n"), false);
}
int same_varibale(char **envp, char *var)
{
    int i;
    
    i = 0;
    printf("var %s \n", var);
    while (envp[i] != NULL)
    {
        if (is_same(envp[i], var) == true)
            return (1);
        i++;
    }
    return (0);
}