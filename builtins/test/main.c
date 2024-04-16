#include "include.h"

/********************************************/ 
/*          test for echo                   */
/********************************************/ 
/*
int main(int ac, char **av)
{

    if (ac > 1)
        printAv(av, false);
    else
        printf("no argv \n"); 
}
*/

/********************************************/ 
/*          test for export                 */
/********************************************/ 

/* 
int main(int ac, char **av, char **envp)
{
    printf("main start ....\n");
    char *v[] = {"hello", "bonjour", "comment" "demain", "soir", "sinnoe", "var=sds", NULL};
    bool print = false;

    if (print)
        ft_export(envp, v, print);
    else
    {
        printf("VARs ARE ADD ....................");
        ft_export(envp, v, false);
    }
}
*/

int main (int ac, char **av, char **envp)
{
    char *one[] = {"hello", "hello", NULL};
    ft_export(envp, one, false);
    // printf("Hello World \n");
}