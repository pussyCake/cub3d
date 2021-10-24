
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*arr;
	size_t	max;

	max = num * size;
	arr = malloc(max);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, max);
	return (arr);
}
