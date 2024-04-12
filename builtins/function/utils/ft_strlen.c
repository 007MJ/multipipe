#include "../../test/include.h"

// use the lib str 
int ft_strlen(char *s)
{
    int i;

    i = 0;
    if(s)
        while (s[i])
            i++;
    return (i);
}