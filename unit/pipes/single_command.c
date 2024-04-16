#include "../includes/global.h"

int    single_command(t_cmd *cmd, char **envp, char *envp_path)
{
    if (cmd)
    {
        // printf("is cmd good\n");
        // cmd->id = malloc(sizeof(pid_t));
        cmd->id = fork();
        if (cmd->id == 0)
        {
            // is on doit change le stdint ou le out ?
            if (execute_command(cmd, envp, envp_path) == -1)
                return (-1);
        }
        else if (cmd->id < 0)
            printf("------Error fork()\n");
        wait_childs(cmd);
        return (1);
    }
    return (-1);   
}