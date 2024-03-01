#include "../include/includes.h"

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
    printf(" is %d\n", is);
    if (is % 2 == 0)
        return (i);
    return (-1);
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
char    *manage_quote(int *i, char quote, char *input)
{
    char    *s1;
    int space;

    space = len_quote(input, quote);
    if (space == -1)
        return (NULL);
    s1 = ft_calloc(space, sizeof(char *));
    // printf("[Manage quote ]Start -- pars -- %s  .....\n", input);
    while (input[*i]  && *i <= space && input[*i] != '\0')
    {
        // printf("while quote %c :.. \n", s1[i]);
        s1[*i] = input[*i];
        *i += 1;
    }
    s1[*i] = '\0';
    s1 = _remove_quote(s1);
    // printf("End pars -- [%s]-- \n", s1);
    return (s1);
}