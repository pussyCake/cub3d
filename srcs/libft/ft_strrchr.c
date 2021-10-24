
#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	while (str[i] != (char)ch)
	{
		if (i-- == 0)
			return (NULL);
	}
	return ((char *)str + i);
}
