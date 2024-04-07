#include "test/pipes.h"

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

int    single_command(t_cmd *cmd, char **envp, char *envp_path)
{
    if (cmd)
    {
        printf("is cmd good\n");
        cmd->id = malloc(sizeof(pid_t));
        cmd->next = NULL;
        if(!cmd->id)
            return (-1);
        *cmd->id = fork();
        if (*cmd->id == 0)
        {
            printf("is fork() good\n");
            if (execute_command(cmd, envp, envp_path) == -1)
                return (-1);
        }
        else if (*cmd->id < 0)
            printf("------Error fork()\n");
        wait_childs(cmd->id, 1);
        return (1);
    }
    return (-1);   
}
int    commands(t_glob *shell, char **envp, char *envp_path)
{
    (void)shell;
    (void)envp;
    (void)envp_path;
    t_cmd *curr;
    pid_t *id_childs;
    curr = shell->cmds;
    int fd[2];
    int last_fd;
    // printf("==============================\n");
    id_childs = malloc(sizeof(pid_t) * shell->nb_cmds);
    // while (curr != NULL)
    // {
        // printf("curr->index %d | curr->cmd %s | curr->pipes %d\n", curr->index, curr->cmd_name, curr->nb_pipes);
        // curr = curr->next;
    // }
    // printf("==============================\n");
    curr = shell->cmds;
    last_fd = -1;
    while (curr != NULL)
    {
        pipe(fd);
        if (curr->index == 0)
        {
            last_fd = fd[0];
            fd[0] = 0;
        }
        else
        {
            last_fd ^= fd[0];
            fd[0] ^= last_fd;
            last_fd ^= fd[0];
        }
        if (curr->index == shell->nb_cmds -1)
        {
            close(fd[1]);
            fd[1] = 1;
        }
        curr->pipes = shell->pipes;
        if (!curr->id)
            return (-1);
        *id_childs = fork();
        if (*id_childs == 0)
        {
            // close(fd[0])
            if (fd[0] != 0)
            {
                dup2(fd[0], 0);
                close(fd[0]);
            }
            if (fd[1] != 1)
            {
                dup2(fd[1], 1);
                close(fd[1]);
            }
            if (execute_command(curr, envp, envp_path) == -1)
                return (-1);
        }
        else if (*id_childs < 0)
            printf("Error fork()\n");
        else
        {
            if (curr->index != 0)
                close(fd[0]);
            if (curr->index != shell->nb_cmds -1)
            {
                close(fd[1]);
            }
            else 
            {
                close(last_fd);
            }
            curr = curr->next;
        } 
    }
    wait_childs(id_childs, shell->nb_cmds);
    return (1);
}

int   run_commands(char **envp, t_glob *shell)
{
    int     i;
    char	*envp_path;

    i = 0;
    if (!shell->cmds)
        return (-1);
    t_cmd   *current;
    current = shell->cmds;
    envp_path = get_envp_path(envp);
    if (shell->nb_cmds == 1)
    {
        printf("cmd->pipes\n");
        if (single_command(current, envp, envp_path) == -1)
            return (-1);
    }
    else
        commands(shell, envp, envp_path);
    return (1);
}