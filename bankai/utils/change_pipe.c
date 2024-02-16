#include "../include/includes.h"


void    change_pipe(t_cmd *current)
{
    if (current->next != NULL)
    {
        dup2(current->pipes[current->index][1], 1);
    }
    if (current->index != 0)
        dup2(current->pipes[current->index - 1][0], 0); 
    close_pipes(current, current->nb_pipes);
}