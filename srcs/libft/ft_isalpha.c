
#include "libft.h"

int	ft_isalpha(int chr)
{
	if ((chr >= 65 && chr <= 90) || ((chr >= 97 && chr <= 122)))
		return (1);
	return (0);
}
