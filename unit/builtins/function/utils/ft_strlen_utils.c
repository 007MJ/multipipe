#include "../../../includes/global.h"

// use the lib str 
int ft_strlen_utils(char *s)
{
    int i;

    i = 0;
    if(s)
        while (s[i])
            i++;
    return (i);
}