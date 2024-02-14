#include "mulit.h"
int  input_redirection(char *name)
{
    int file;

    if (name)
    {
        file =  open(name, O_RDONLY);
        if (file < 0)
        {
            close (file);
            printf("darkshell: no such file or directory: %s\n", name);
            return (-1); // code erreur 
        }
        else
            dup2(file, 0);
        return (1);
    }
    return (-1); // code erreur 
}

// programme prend entre un file 
 int main(int ac, char **av, char **envp)
 {
    char *two[] = {"cat", NULL};
    (void)two;
    (void)ac;
    // int file = open(av[1], O_RDONLY);
    // if (ac == 1 || file < 0)
    // {
    //     if (file < 0)
    //         printf("Error fd\n");
    //     else 
    //         printf("Error av\n");
    //     return (0);
    // }
    if (input_redirection(av[1]) == -1)
        return (-1);
    pid_t pid = -1;
    pid = fork();
    if (pid < 0)
    {
        printf("Error pid\n");
        return (0);
    }
    if (pid == 0)
    {
        execve("/bin/cat", two, envp);
        return (0);
    }
    return (0);
 }