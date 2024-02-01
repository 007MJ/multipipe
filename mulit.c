#include "mulit.h"

int	**init_fd(int nb_pipe)
{
	int **fds = malloc(sizeof(int **) * nb_pipe);

	for (int i = 0; i < nb_pipe; i++)
	{
		fds[i] = malloc(sizeof(int *) * 2);
		pipe(fds[i]);
	}
	return (fds);
}

int	numbers_of_pipe(char **av)
{
	int i = 1;
	int j = 0;
	int pipe = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] == '|')
			{
				if (av[i][j + 1] == ' ' && av[i][j - 1] == ' ')
					pipe++;
			}
			j++;
		}
		i++;
	}
	return (pipe);
}

t_cmd *init_cmd(int index, int **fds, char **cmds)
{
	t_cmd *cmd= malloc(sizeof(char *) * 1);
	if (!cmd)
		return (NULL);
	cmd->fds = fds;
	cmd->cmds = cmds;
	cmd->index = index;
	return (cmd);
}
t_cmd *new_node()
{
	t_cmd *node = malloc(sizeof(t_cmd) * 1);
	if (!node)
		return (NULL);
	return (node);
}

void	append(t_cmd ** head, int data, int **fds, char **cmds)
{
	t_cmd *node = new_node();

	node->index = data;
	node->fds = fds;
	node->cmds = cmds;
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

// programme pour multi pipe
int main(int ac, char **av, char *envp[])
{
	pid_t pids;
	pids = -1;
	int i = 0;
	int p = 1;
	(void)av;
	(void)ac;
	(void)envp;
	int **fds = init_fd(p);
	char *one[] = {"ls", "-l", NULL};
	char *two[] = {"wc", "-l", NULL};
	t_cmd **node = malloc(sizeof(t_cmd) * 1);
	t_cmd *current;
	if (!node)
		return (-1);
	append(node, 0, fds, one);
	append(node, 1, fds, two);
	current = *node;
	while (current != NULL)
	{
		pids = fork();
		if ( pids == 0)
		{
			// printf(" cmds %s", one[0]);
			if (current->index == 0) {
				dup2(fds[current->index][1], 1);
				close(fds[current->index][1]);
				close(fds[current->index][0]);
				execve("/bin/ls", current->cmds, envp);
			}
			if (current->index == 1) {
				dup2(fds[current->index - 1][0], 0);
				close(fds[current->index - 1][0]);
				close(fds[current->index - 1][1]);
				execve("/usr/bin/wc", current->cmds, envp);
			}
			exit(1);
		}
		else
		{
			current = current->next;
		}
	}
	current = *node;
	i = 0;
	close(fds[current->index][0]);
	close(fds[current->index][1]);
	while (i < p)
	{
		wait(NULL);
		i++;
	}
	return (0);
}
