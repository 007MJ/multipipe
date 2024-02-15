#include "../include/prototype.h"

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