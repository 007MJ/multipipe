#include "test/pipes.h"

int execute_command(t_cmd *current, char **envp, char *envp_path)
{
     char	*cmd_path;

    // change_pipe(current);
    if (!current)
        return (printf("current is NULL"), -1);
    cmd_path = get_cmd_path(envp_path, current->cmd_name);
    if(!cmd_path)
        return (printf("shell_kai: %s: command found \n", current->cmd_name), exit(EXIT_FAILURE), 0);
    if ( execve(cmd_path, current->av_cmd, envp) == -1)
        return (perror("Command error"), exit(EXIT_FAILURE), 0);
    return (1);
}