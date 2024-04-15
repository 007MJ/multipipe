#include "../includes/global.h"

void call_built(t_cmd *current)
{
    (void)current;
}

void    which_cmd(t_cmd *current)
{
    if (current->type == BUILT)
    {
        // we make de commande and we look at the > redirection
        // exit();
    }
    if (current->type == HEREDOC)
    {
        // we make de les here and we look at the > redirection
        // exit();
    }
}