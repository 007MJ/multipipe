#include "../include/includes.h"

int execute_commands(t_cmd *current, char **envp, char *envp_path)
{
     char	*cmd_path;

    change_pipe(current);
    cmd_path = get_cmd_path(envp_path, current->cmd_name);
    if(!cmd_path)
        return (printf("command path no found: \"%s\"\n", current->cmd_name), 0);
    if ( execve(cmd_path, current->av_cmd, envp) == -1)
        return (perror("Command error"), exit(EXIT_FAILURE), 0);
    return (1);
}