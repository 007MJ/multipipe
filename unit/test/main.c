#include "../includes/global.h"
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

t_files    *file_append(t_files *files, char *name, int type)
{
    t_files *new;
    t_files *curr;
    // printf("1\n");
    curr = files;;
    new = malloc(sizeof(t_files));
    new->name = malloc(sizeof(char *) * (ft_strlen(name) + 1));
    new->type = type;
    new->next = NULL;
    // printf("2\n");
    if (new->name)
        strcpy(new->name, name);
    else
        return NULL;
    // printf("3 %s\n", new->name);
    if (!curr)
    {
        files = new;
        // printf("4\n");
        return files;
    }
    // printf("5\n");
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
        // printf("is Head NULL\n");
        head = new;
        return head;
    }
    curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new;
    return (head);
}
// int main (int ac, char **av, char **envp)
// {
//     (void)ac;
//     (void)av;
//     t_cmds *cmds;
//     t_files *files_var;
//     cmds = malloc(sizeof(t_glob));
//     if (!cmds)
//         return (-1);
//     cmds->nb_cmds = 1; 
//     cmds->nb_pipes = 0;
//     cmd->envp = envp;
//     cmds->next = NULL
//     files_var = NULL;
//     char *one[] = {"ls", NULL};
//     shell->files = file_append(files_var, "files.text", APPEND);
//     shell->cmds = fake(shell->cmds, one, 0, shell->nb_pipes);
//     unit(shell);
// }

/******************** one cmds ***********************/
// int main (int ac, char **av, char **envp)
// {   
    // t_cmd *cmds;

    // cmds = NULL;
    // (void)envp;
    // if (ac > 1)
        // return (printf("no argment %s \n", *av), -1);
    // else
    // {
        // cmds = malloc(sizeof(t_cmd));
        // if (!cmds)
        //     return (printf("cmds! did't malloc well !"), -1);
        // char *av[] = {"ls", NULL};
        // cmds->type = ARVG;
        // cmds->envp = envp;
        // cmds->nb_pipes = 0;
        // cmds->nb_cmds = 1;
        // cmds->index = 0;
        // cmds->cmd_name = "ls";
        // cmds->av_cmd = av;
        // cmds->files = NULL;
        /******************** test cmd with files ************************/
        // cmds->files = file_append(cmds->files, "test.fr", APPEND);
        /****************************************************************/
//         cmds->next = NULL;
//         unit(cmds);
//     }
// }

/******************** mulit cmds ***********************/
int main(int ac, char **av, char **envp)
{
    (void)av;
    (void)ac;
    char *av0[] = {"ls", NULL};
    char *av1[] = {"wc", NULL};

    t_cmd *one = malloc(sizeof(t_cmd));
    t_cmd *two = malloc(sizeof(t_cmd));
    if (!one)
        return (-1);
    one->av_cmd = av0;
    one->cmd_name = "ls";
    one->envp = envp;
    one->nb_cmds = 2;
    one->index = 0;
    one->nb_pipes = 1;
    one->files = NULL;
    // printf("======================================\n");
    one->next = two;
    two->av_cmd = av1;
    two->nb_cmds = 2;
    two->cmd_name = "wc";
    two->envp = envp;
    two->index = 1;
    two->nb_pipes = 1;
    two->files = NULL;
    two->next = NULL;
    // printf("%d cmd pipe\n", one->nb_cmds - 1);
    unit(one);
}

