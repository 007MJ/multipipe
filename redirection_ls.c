#include "mulit.h"

// pour la cmd " ls > namefile"
int main(int ac, char **av, char **envp)
{
    int file = open(av[1], O_WRONLY | O_CREAT | O_TRUNC , 07777);
    if (ac == 1)
    {
        printf("Error agv\n");
        return (0);
    }
    char *one[] = {"ls", "-l", NULL};
    pid_t  pid = -1;
    if (file < 0)
    {
        printf("Error fd\n");
        return (0);
    }
    pid = fork();
    if (pid < 0)
    {
        printf("Error pid \n");
        return (0);
    }
    if (pid == 0)
    {
        dup2(file, 1);
        execve("/bin/ls", one, envp);
    }
    return (0);
}