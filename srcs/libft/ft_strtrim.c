
#include "libft.h"

size_t	ft_chrfind(char const s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	ind_start;
	size_t	ind_end;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	ind_start = 0;
	ind_end = ft_strlen(s1) - 1;
	while (ft_chrfind(s1[ind_start], set) == 1)
		ind_start++;
	if (ind_start != ind_end + 1)
	{
		while (ft_chrfind(s1[ind_end], set) == 1)
			ind_end--;
	}
	str = (char *)malloc(sizeof(char) * (ind_end - ind_start + 2));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + ind_start, ind_end - ind_start + 2);
	return (str);
}
