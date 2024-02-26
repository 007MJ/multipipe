#include "../include/includes.h"

int check_quote(char *input)
{
    int one_q;
    int two_q;
    int i;

    i = 0;
    one_q = 0;
    two_q = 0;
    while (input[i] && input[i] != '\0')
    {
        if (input[i] == '\'')
            one_q++;
        if (input[i] == '\"')
            two_q++;
        i++;
    }
    if (one_q % 2 == 0 && two_q  % 2 == 0)
        return (i);
    return (-1);
}