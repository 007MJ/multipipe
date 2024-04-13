#include "unit.h"
#include <string.h>

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

t_files    *file_append(t_files *files, char *name)
{
    t_files *new;
    t_files *curr;
    printf("1\n");
    curr = files;;
    new = malloc(sizeof(t_files));
    new->name = malloc(sizeof(char *) * (ft_strlen(name) + 1));
    new->next = NULL;
    printf("2\n");
    if (new->name)
        strcpy(new->name, name);
    else
        return NULL;
    printf("3 %s\n", new->name);
    if (!curr)
    {
        files = new;
        printf("4\n");
        return files;
    }
    printf("5\n");
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new;
    return (files);
}

t_cmd   *fake(t_cmd *head,  char **av_cmd, int index, int nb_pipes)
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
int main (int ac, char **av, char **envp)
{
    (void)ac;
    (void)av;
    t_glob *shell;
    // t_files *files;
    shell = malloc(sizeof(t_glob));
    if (!shell)
        return (-1);
    shell->nb_cmds = 1; 
    shell->nb_pipes = 0;
    shell->envp = envp;
    shell->cmds = NULL;
    char *one[] = {"ls", NULL};
    shell->cmds = fake(shell->cmds, one, 0, shell->nb_pipes);
    unit(shell);
}