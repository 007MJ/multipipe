#include "test/pipes.h"

int	**init_pipes(int nb)
{
	int	**p;
	int	i;

	i = 0;
	p =  malloc(sizeof(int **) * nb);
	if (nb == 0)
		return (NULL);
	while(i < nb)
	{
		p[i] = malloc(sizeof(int *) * 2);
		pipe(p[i]);
		i++;
	}
	return (p);
}