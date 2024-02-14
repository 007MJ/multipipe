#include "pipes.h"

int main(int ac, char **av, char **envp)
{
    int i;
    int **pipes;
    int     nb_pipe = 2;

    i = 0;
    pipes = init_pipes(3);
    (void)av;
    (void)envp;
    t_cmd **head = (t_cmd **)malloc(sizeof(t_cmd **));
    if (ac == 1)
    {
        char *one[] = {"ls", "-l", NULL};
        char *two[] = {"wc", NULL};
        char *three[] = {"wc", NULL};
        char *four[] = {"ls -l", NULL};
        if (!head)
            return (printf("head did't malloc"), -1);
        append(head, 0, pipes, one, "ls", nb_pipe);
        append(head, 1, pipes, two, "wc", nb_pipe);
        append(head, 2, pipes, three, "wc", nb_pipe);
        append(head, 3, pipes, four, "ls", nb_pipe);
        run_command(envp, head);
    }
    close_pipes(*head, (*head)->nb_pipes);
    // printf("\n");
    return (0);
}