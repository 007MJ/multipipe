#include "test/pipes.h"
#include "../unit/unit.h"

void    wait_childs(pid_t *id, int nb_childs)
{
    int i;

    i = 0;
    while (i < nb_childs)
    {
        printf("is working .. .. ..\n");
        waitpid(id[i], NULL, 0);
        i++;
    }
}