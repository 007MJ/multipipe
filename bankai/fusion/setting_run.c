#include "../include/includes.h"

void    setting_run(t_glob *shell_kai)
{
    // check is built 
    // check redirection
    // check pour PIPE OR CMD ELSE
    run_command(shell_kai->envp, &shell_kai->cmds);
}