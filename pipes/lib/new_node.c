#include "../pipes.h"

t_cmd *new_node()
{
	t_cmd *node = malloc(sizeof(t_cmd) * 1);
	if (!node)
		return (NULL);
	return (node);
}