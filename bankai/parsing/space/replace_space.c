#include "../../include/includes.h"

int len_quote(char *input, char quote)
{
    int is;
    int i;

    i = 0;
    is = 0;
    while (input[i] && input[i] != '\0')
    {
        if  (input[i] == quote)
            is++;
        if (is % 2 == 0)
            return (i);
        i++;
    }
    // printf(" is %d\n", is);
    if (is % 2 == 0)
        return (i);
    return (0);
}

char    *_remove_quote(char *s1)
{
    int     i;
    int     j;
    char    *s2;

    i = 1;
    j = 0;
    s2 = ft_calloc(ft_strlen(s1) -2, sizeof(char *));
    while (s1[i] && i < (int )ft_strlen(s1) - 1)
    {
        s2[j] = s1[i];
        i++;
        j++;
    }
    free(s1);
    s2[j] = '\0';
    return (s2);
}

int   replace(char *s, char c)
{
    int i;

    i = 1;
    while (s[i] != '\0' && s[i] != c)
    {
        if (s[i] == ' ')
            s[i] = 30;
        i += 1;
    }
    return (i);
}

void    replace_space(char *input)
{
    int i;

    i = 0;
    if (input)
    {
        while (input[i] != '\0')
        {
            if (input[i] == '\"' || input[i] == '\'')
               i += replace(&input[i], input[i]);
            i++;
        }
    }
}