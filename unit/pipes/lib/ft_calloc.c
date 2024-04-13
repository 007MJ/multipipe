#include "../../includes/global.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (count == 0 && size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
