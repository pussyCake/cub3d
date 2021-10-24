
#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	while (str[i] != (char)ch)
	{
		if (str[i++] == '\0')
			return (NULL);
	}
	return ((char *)str + i);
}
