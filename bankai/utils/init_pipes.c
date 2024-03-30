#include "../include/includes.h"


int	**init_pipes(int nb)
{
	int	**p;
	int	i;

	i = 0;
	p =  malloc(sizeof(int **) * nb);
	while(i < nb)
	{
		p[i] = malloc(sizeof(int *) * 2); 
		i++;
	}
	return (p);
}