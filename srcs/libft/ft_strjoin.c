
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*sum;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	sum = (char *)malloc(sizeof(char) * (len + 1));
	if (sum == NULL)
		return (NULL);
	ft_memmove(sum, s1, ft_strlen(s1));
	ft_memmove(sum + ft_strlen(s1), s2, ft_strlen(s2));
	sum[len] = '\0';
	return (sum);
}
