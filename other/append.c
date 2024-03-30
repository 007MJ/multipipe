#include "mulit.h"

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        int file = open(av[1], O_WRONLY | O_APPEND | O_CREAT ,  07777);
        dup2(file, 1);
        printf("bonjour \n");
        if (file < 0)
        {
            printf("file faill\n");
            return (0);
        }
    }
    else
    {
        printf("no av\n");
    }
    return (0);
}