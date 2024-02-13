#include "pipes.h"

void close_pipes(t_cmd *current, int nb)
{
    int     i;

    i = 0;

    while ( i < nb)
    {
        close(current->pipes[i][0]);
        close(current->pipes[i][1]);
        i++;
    }
}
int	**init_pipes(int nb)
{
	int **p = malloc(sizeof(int **) * nb);

	for (int i = 0; i < nb; i++)
	{
		p[i] = malloc(sizeof(int *) * 2); // should be a while 
		pipe(p[i]);
	}
	return (p);
}
void only_first_pipe(t_cmd *current)
{
    dup2(current->pipes[current->index][1], 1);
    close(current->pipes[current->index][1]);
    close(current->pipes[current->index][0]);
}

void    change_pipe(t_cmd *current)
{

    if (current->index == 0)
        only_first_pipe(current);
    if (current->index > 0)
    {
        if (current->next != NULL)
            dup2(current->pipes[current->index][1], 1);
        if (current->index != 0)
            dup2(current->pipes[current->index - 1][0], 0); // A test cela function 
        close_pipes(current, current->nb_pipes);
    }
}

int execute_commands(t_cmd *current, char **envp, char *envp_path)
{
     char	*cmd_path;

    change_pipe(current);
    cmd_path = get_cmd_path(envp_path, current->first_cmd);
    if(!cmd_path)
        return (printf("command path no found: \"%s\"\n", current->first_cmd), 0);
    if ( execve(cmd_path, current->cmds, envp) == -1)
        return (perror("Command error"), exit(EXIT_FAILURE), 0);
    return (1);
}

void    add_pipes_nodes(int **pipes, t_cmd **node)
{
    t_cmd *current;

    current = *node;
    while (current != NULL)
    {
        current->pipes = pipes;
        current = current->next;
    }
}
int   *array_child_ids(int nb_id)
{
    int     *waitchild;

    waitchild = (pid_t *)malloc(sizeof(pid_t) * (nb_id));
    if (!waitchild)
    {
        *waitchild  = -1;
        return (waitchild);
    }
    return (waitchild);
}
void    main_process_wait_childs(pid_t *id, int nb)
{
    int i;

    i = 0;
    while (i < nb)
    {
        waitpid(id[i], NULL, 0);
        i++;
    }
}
// list avec tout le pipe
int   run_pipe(char **envp, t_cmd **cmds)
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
        {
            current = current->next;
        }
        i++;
    }
    close_pipes(*cmds, (*cmds)->nb_pipes);
    main_process_wait_childs(child_ids, (*cmds)->nb_pipes);
    return (1);
}
t_cmd *new_node()
{
	t_cmd *node = malloc(sizeof(t_cmd) * 1);
	if (!node)
		return (NULL);
	return (node);
}

void	append(t_cmd **head, int i, int **pipes, char **cmds, char *fcmd, int nb_pipes)
{
	t_cmd *node = new_node();

	node->index = i;
	node->pipes = pipes;
	node->nb_pipes = nb_pipes;
	node->cmds = cmds;
	node->first_cmd = fcmd;
	node->next = NULL;
	if ((*head) == NULL)
	{
		*head = node;
		return ;
	}
	t_cmd *current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
}

int main(int ac, char **av, char **envp)
{
    int i;
    int **pipes;
    int     nb_pipe = 2;

    i = 0;
    pipes = init_pipes(2);
    (void)av;
    (void)envp;
    if (ac == 1)
    {
        char *one[] = {"ls", "-l", NULL};
        char *two[] = {"wc", NULL};
        char *three[] = {"wc", NULL};
        t_cmd **head = (t_cmd **)malloc(sizeof(t_cmd **));
        if (!head)
            return (printf("head did't malloc"), -1);
        append(head, 0, pipes, one, "ls", nb_pipe);
        append(head, 1, pipes, two, "wc", nb_pipe);
        append(head, 2, pipes, three, "wc", nb_pipe);
        run_pipe(envp, head);
    }
    // printf("\n");
    return (0);
}
// quand tu as plusieurs pipes c'est pas la meme chose qui arriver je pense 