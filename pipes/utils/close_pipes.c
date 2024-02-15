#include "../include/prototype.h"

void close_pipes(t_cmd *current, int nb)
{
    int i;

    i = 0;
    while ( i < nb)
    {
        close(current->pipes[i][0]);
        close(current->pipes[i][1]);
        i++;
    }
}