#include "../include/prototype.h"

int   run_command(char **envp, t_cmd **cmds)
{
    int     i;
    char	*envp_path;
    pid_t   *child_ids;

    i = 0;
    t_cmd   *current;
    current = *cmds;
    envp_path = get_envp_path(envp);
    child_ids = array_child_ids(current->nb_pipes);
    while (current != NULL)
    {
        current->id = fork();
        child_ids[i] = current->id;
        if (current->id == 0)
        {
           execute_commands(current, envp, envp_path);
           exit(1);
        }
        else if (current->id < 0)
            return (printf("fork fail\n"), 0);
        else
            current = current->next;
        i++;
    }
    close_pipes(*cmds, (*cmds)->nb_pipes);
    wait_childs(child_ids, (*cmds)->nb_pipes);
    return (1);
}