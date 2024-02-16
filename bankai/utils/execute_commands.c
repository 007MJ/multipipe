#include "../include/includes.h"


int execute_commands(t_cmd *current, char **envp, char *envp_path)
{
     char	*cmd_path;

    change_pipe(current);
    cmd_path = get_cmd_path(envp_path, current->first_cmd);
    if(!cmd_path)
        return (printf("command path no found: \"%s\"\n", current->first_cmd), 0);
    if ( execve(cmd_path, current->cmds, envp) == -1)
        return (perror("Command error"), exit(EXIT_FAILURE), 0);
    return (1);
}