#include "../pipes.h"

void    wait_childs(pid_t *id, int nb)
{
    int i;

    i = 0;
    while (i < nb)
    {
        waitpid(id[i], NULL, 0);
        i++;
    }
}