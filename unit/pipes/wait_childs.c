#include "../includes/global.h"

void    wait_childs(pid_t *id, int nb_childs)
{
    int i;

    i = 0;
    while (i < nb_childs)
    {
        // printf("is working .. .. .. %d\n", nb_childs);
        waitpid(id[i], NULL, 0);
        i++;
    }
}