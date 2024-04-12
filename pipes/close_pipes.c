#include "test/pipes.h"
#include "../unit/unit.h"

void close_pipes(t_cmd *current, int nb)
{
    int i;

    i = 0;
    printf("current->nb_pipes %d and nb %d current->cmd %s \n", current->nb_pipes, nb, current->cmd_name);
    if (current->nb_pipes > 0)
    {
        while ( i < nb)
        {
            close(current->pipes[i][0]);
            close(current->pipes[i][1]);
            i++;
        }
    }
}