
#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	nn;

	nn = (long)n;
	if (nn == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen(nn);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		nn = nn * -1;
		str[0] = '-';
	}
	while (nn > 0)
	{
		str[len--] = (nn % 10) + '0';
		nn = nn / 10;
	}
	return (str);
}
