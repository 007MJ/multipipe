#include "include/includes.h"

// int main(int ac, char **av, char **envp)
// {
//     int     i;
//     int     **pipes;
//     int     nb_pipe = 3;


//     pipes = init_pipes(3);
//     i = 0;
//     (void)av;
//     (void)envp;
//     t_cmd **head = (t_cmd **)malloc(sizeof(t_cmd **));
//     if (ac == 1)
//     {
//         char *one[] = {"ls", "-l", NULL};
//         // char *two[] = {"wc", NULL};
//         // char *three[] = {"wc", NULL};
//         // char *four[] = {"ls -l", NULL};
//         if (!head)
//             return (printf("head did't malloc"), -1);
//         // append(head, 0, pipes, one, "ls", nb_pipe);
//         // append(head, 1, pipes, two, "wc", nb_pipe);
//         // append(head, 2, pipes, three, "wc", nb_pipe);
//         // append(head, 3, pipes, four, "ls", nb_pipe);
//         run_command(envp, head);
//     }
//     close_pipes(*head, (*head)->nb_pipes);
//     return (0);
// }

void run(t_glob *shell_kai)
{
    shell_kai->on = 1;
    while(shell_kai->on)
    {
        shell_kai->input = readline("shell_kai > ");
        if (!shell_kai->input)
            rl_on_new_line();
        if (shell_kai->input && *shell_kai->input)
        {
            add_history( shell_kai->input);
            printf("Run function -- %s -- \n", shell_kai->input);
            if (ft_strncmp( shell_kai->input, "exit", ft_strlen("exit")) == 0)
            {
                printf("%s\n", shell_kai->input);
                rl_clear_history();
                shell_kai->on = 0;
            }
            make_cmds(shell_kai);
            free(shell_kai->input);
        }
        rl_on_new_line();
    }
}

int main(int ac , char **av, char **envp)
{
    if (ac > 1)
        return (-1);
    t_glob *shell_kai = malloc(sizeof(t_glob) * 1);
    if (!shell_kai)
        return (-1);
    shell_kai->envp = envp;
    shell_kai->input = av[1];
    run(shell_kai);
    free(shell_kai);
    return (0);
}