#include "../../../include/includes.h"

void	ft_cpycmds(char **new, char **olds, const char *n)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (olds)
    {
        while (olds[i] != NULL)
        {
            new[i] = allocatecpy(olds[i]);
            i++;   
        }
        free(olds);
    }
    new[i] = allocatecpy((char *)n);
}