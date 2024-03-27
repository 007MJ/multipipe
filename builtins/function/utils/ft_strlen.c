#include "../../test/include.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    if(s)
        while (s[i])
            i++;
    return (i);
}