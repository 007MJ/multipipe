#include "../includes/global.h"

int unit(t_cmd *cmds)
{
    
    if (run_commands(cmds) == -1)
        return (-1);
    return (1);
}