
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s) - (size_t)start) < len)
		len = ft_strlen(s) - (int)start;
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s + start, len + 1);
	cpy[len] = '\0';
	return (cpy);
}
