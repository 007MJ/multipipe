#include "pipes.h"

void    printcmd(t_cmd *cmd)
{
    t_cmd *current;

    current = cmd;
    printf("=========================================================================\n");
    while (current != NULL)
    {
        printf(" current->cmd :: %s | current->nb_pipe :: %d | current->index  :: %d \n", current->cmd_name, current->nb_pipes, current->index);
        current = current->next;
    }
    printf("==========================================================================\n");
}

t_cmd   *fake(t_cmd *head, int **pipes, char **av_cmd, int index, int nb_pipes)
{
    t_cmd *new;
    t_cmd *curr;

    curr = NULL;
    new = malloc(sizeof(t_cmd));
    if (!new)
        return NULL;
    new->av_cmd = av_cmd;
    new->cmd_name = *av_cmd;
    new->index = index;
    new->nb_pipes = nb_pipes;
    new->pipes = pipes;
    new->next = NULL;
    if (head == NULL)
    {
        printf("is Head NULL\n");
        head = new;
        return head;
    }
    curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new;
    return (head);
}

int main(int ac, char **av, char **envp)
{
    (void)av;
    (void)ac;
    (void)envp;
    t_glob *shell;
    t_cmd   *current;
    int     index;

    index = 0;
    current = NULL;
    shell = malloc(sizeof(t_glob));
    if (!shell)
        return (-1);
    shell->nb_cmds = 2;
    shell->nb_pipes = 1;
    // shell->pipes = init_pipes(shell->nb_pipes);

    char *one[] = {"", NULL};
    char *two[] = {"wc", NULL};
    shell->cmds = fake(current, shell->pipes, one, index, shell->nb_pipes);
    shell->cmds->next = NULL;
    index++;
    shell->cmds = fake(shell->cmds, shell->pipes, two, index, shell->nb_pipes);
    // printcmd(shell->cmds);
    run_commands(envp, shell);
}