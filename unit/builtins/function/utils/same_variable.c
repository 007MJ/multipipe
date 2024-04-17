#include "../../../includes/global.h"

int same_varibale(char **envp, char *var)
{
    int i;
    
    i = 0;
    while (envp[i] != NULL)
    {
        if (is_same(envp[i], var) == true)
            return (i);
        i++;
    }
    return (-1);
}