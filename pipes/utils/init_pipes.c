#include "../include/prototype.h"

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