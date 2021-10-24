
#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	if (arr1 == NULL && arr2 == NULL)
		return (0);
	s1 = (unsigned char *)arr1;
	s2 = (unsigned char *)arr2;
	while (i < n && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
