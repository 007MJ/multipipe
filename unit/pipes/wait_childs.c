#include "../includes/global.h"

void    wait_childs(t_cmd *cmds)
{
    t_cmd *curr;
    curr = NULL;
    if (cmds)
    {
        if (cmds->nb_pipes > 0)
        {
            curr = cmds;
            while (curr != NULL)
            {
                waitpid(curr->id, NULL, 0);
                curr = curr->next;
            }
        }
    }
}