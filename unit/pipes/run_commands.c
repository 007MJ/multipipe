#include "../includes/global.h"

// int   run_command(char **envp, t_cmd **cmds)
// {
//     int     i;
//     char	*envp_path;
//     pid_t   *child_ids;

//     i = 0;
//     if (!cmds)
//         return (-1);
//     t_cmd   *current;
//     current = *cmds;
//     envp_path = get_envp_path(envp);
//     child_ids = array_child_ids(current->nb_pipes);
//     while (current->next != NULL)
//     {
//         // printf("current->cmd_name %s :::::: \n", current->cmd_name);
//         current->id = fork();
//         child_ids[i] = current->id;
//         if (current->id == 0)
//         {
//            execute_commands(current, envp, envp_path);
//            exit(1);
//         }
//         else if (current->id < 0)
//             return (printf("fork fail\n"), 0);
//         else
//             current = current->next;
//         i++;
//     }
//     wait_childs(child_ids, (*cmds)->nb_pipes);
//     close_pipes(*cmds, (*cmds)->nb_pipes);
//     return (1);
// }


int   run_commands(t_cmd *cmds)
{
    int     i;
    char	*envp_path;

    i = 0;
    if (!cmds)
        return (-1);
    envp_path = get_envp_path(cmds->envp);
    if (cmds->nb_cmds == 1 && cmds->nb_pipes == 0)
    {
        printf("printf nb pipes %d\n", cmds->nb_pipes);
        if (single_command(cmds, cmds->envp, envp_path) == -1)
            return (-1);
    }
    else
    {
        // printf("more than one command\n");
        commands(cmds, envp_path);
    }
    return (1);
}