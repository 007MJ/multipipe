#include "../include/includes.h"

int is_quote(char *input, char quote)
{
    int is;
    int i;

    i = 0;
    is = 0;
    while (input[i])
    {
        if  (input[i] == quote && quote == 0)
            is++;
        if (input[i] == quote || input[i + 1] == ' '  || input[i + 1] == '\0')
            is++;
        i++;
    }
    if (is == 2)
        return (i);
    return (-1);
}

int manage_quote(char *s1, char quote, char *input)
{
    int i;
    int space;

    space = is_quote(input, quote);
    if (space == -1)
        return (-1)
    s1 = ft_calloc(space, sizeof(char *));
    i = 0;
    while (input[i]  && i < space)
    {
        s1[i] = input[i];
        i++;
    }
    s1[i] = '\0';
    return (i);
}