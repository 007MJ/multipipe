#include "mulit.h"


void    cmd(char *str)
{
    int i = 0;
    int space = 0;
    int start = 0;
    if (str)
    {
        while (str[i])
        {
            if (str[i] == '<' && str[i + 1] == '<')
            {
                i++;
                while (str[i] == ' ')
                    i++;
                start = i;
                while (str[i] != ' ')
                {
                    space++;
                    i++;
                }
                char    *here = malloc(sizeof(char *) * (space + 1));
                i = 0;
                while (str[start])
                {
                    here[i] = str[start];
                    i++;
                    start++;
                }

                return ;
            }
            i++;
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        cmd(av[1]);
    }
    else
    {
        printf("sdsfb");
        return (-0);
    }
}