#include "../includes/global.h"

int _childs_fd(int fd[], int last_fd, t_cmd *curr, t_glob *shell)
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
        // Don't change put in next pipe if there an > or >>
        close(fd[1]);
        fd[1] = 1;
    }
    return (last_fd);
}

int expan_child(int fd[], t_cmd *curr, char **envp, char *envp_path)
{
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
    return (1);
}

void _curren_fd(int fd[], int last_fd, t_cmd *curr, t_glob *shell)
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
}
// free id_childs
int    commands(t_glob *shell, char **envp, char *envp_path)
{
    t_cmd *curr;
    pid_t *id_childs;
    int fd[2];
    int last_fd;
    
    id_childs = malloc(sizeof(pid_t) * shell->nb_cmds);
    curr = shell->cmds;
    while (curr != NULL)
    {
        last_fd = _childs_fd(fd, last_fd, curr, shell);
        *id_childs = fork();
        if (*id_childs == 0)
        {
            if (expan_child(fd, curr, envp, envp_path) == -1)
                return (-1);
        }
        else if (*id_childs < 0)
            printf("Error fork()\n");
        else
        {
            _curren_fd(fd, last_fd, curr, shell);
            curr = curr->next;
        } 
    }
    return ( wait_childs(id_childs, shell->nb_cmds), 1);
}
