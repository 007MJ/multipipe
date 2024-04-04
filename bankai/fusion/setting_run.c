#include "../include/includes.h"

void    setting_run(t_glob *shell_kai)
{
    // regarde les redirection de sortie avant de faire des action
    // files(shell_kai);
    // check is built 
    // check redirection change le PIPE AVANT DE RUN COMMAND 
    // check pour PIPE OR CMD ELSE
    run_command(shell_kai->envp, shell_kai->cmds);
}