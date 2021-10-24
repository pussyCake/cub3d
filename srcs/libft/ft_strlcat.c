
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (dest[i] != '\0' && i < n)
		i++;
	if (i != n)
		return (ft_strlcpy(dest + i, src, n - i) + i);
	return (n + ft_strlen(src));
}
