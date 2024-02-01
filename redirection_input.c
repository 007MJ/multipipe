#include "mulit.h"

// programme prend entre un file 
 int main(int ac, char **av, char **envp)
 {
    char *two[] = {"cat", NULL};
    (void)two;
    int file = open(av[1], O_RDONLY);
    if (ac == 1 || file < 0)
    {
        if (file < 0)
            printf("Error fd\n");
        else 
            printf("Error av\n");
        return (0);
    }
    pid_t pid = -1;
    pid = fork();
    if (pid < 0)
    {
        printf("Error pid\n");
        return (0);
    }
    if (pid == 0)
    {
        dup2(file , 0);
        printf("%s\n", av[1]);
        execve("/bin/cat", two, envp);
        return (0);
    }
    return (0);
 }