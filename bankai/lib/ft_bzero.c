#include "../include/includes.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c;
	size_t			i;

	i = 0;
	c = (unsigned char *)s;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
}
