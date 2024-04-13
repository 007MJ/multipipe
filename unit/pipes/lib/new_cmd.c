#include "../../includes/global.h"


t_cmd *new_cmd()
{
	t_cmd *node = ft_calloc(1, sizeof(t_cmd));
	if (!node)
		return (NULL);
	return (node);
}