#include "../includes/global.h"

void    change_pipe(t_cmd *current)
{
    if (current->next != NULL)
    {
        // printf("---current->index %d current-cmd %s current->nex_>pipes\n", current->index, current->cmd_name);
        if (current->pipes)
            dup2(current->pipes[current->index][1], 1);
    }
    if (current->index != 0)
    {
        // printf("|||||||||||||||||||||||||||||||||||||||||||||||||current->index %d current-cmd %s\n", current->index, current->cmd_name);
        if (current->pipes)
            dup2(current->pipes[current->index - 1][0], 0); 
    }
    // close_pipes(current, current->nb_pipes);
}