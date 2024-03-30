#include "mulit.h"

// pour la cmd " ls > namefile"
int output_redirection(char *name, int file, int is_ok)
{
    if (name)
    {
        file = open(name, O_WRONLY | O_CREAT | O_TRUNC , 07777);
        if (file < 0)
        {
            close(file);
            printf("darkshell: command not found: %s\n", name);
            return (-1);
        }
        if (is_ok == 1)
            dup2(file, 1);
        return (1);
    }
    return (-1);
}

// quand la command elle ne functione pas ferme le fd et ecire dans le terminal
int main(int ac, char **av, char **envp)
{
    // int file = open(av[1], O_WRONLY | O_CREAT | O_TRUNC , 07777);
    // if (ac == 1)
    // {
    //     printf("Error agv\n");
    //     return (0);
    // }
    (void)ac;
    int file;
    int is_ok;

    file = -12;
    is_ok = 1;
    char *path = "/bin/ls";
    char *one[] = {"ls", "-l", NULL};
    if (access(path, F_OK))
    {
        printf("darskshell: command not found: %s\n", *one);
        is_ok = -1;
    }
    pid_t  pid = -1;
    // if (file < 0)
    // {
    //     printf("Error fd\n");
    //     return (0);
    // }
    if (output_redirection(av[1], file, is_ok) == -1)
        return(-1);
    pid = fork();
    if (pid < 0)
    {
        printf("Error pid \n");
        return (0);
    }
    if (pid == 0)
    {
        if (execve(path, one, envp) == -1)
        {
            close(file);
            close(1);
            printf("darskshell: command not found: %s", *one);
        }
        exit(1);
    }
    return (0);
}