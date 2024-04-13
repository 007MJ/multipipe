#include "unit.h"

int unit(t_glob *shell)
{
    if (run_commands(shell->envp, shell) == -1)
        return (-1);
    return (1);
}