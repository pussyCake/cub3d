
#include "libft.h"

int	ft_isalnum(int chr)
{
	if (ft_isalpha(chr) == 0 && ft_isdigit(chr) == 0)
		return (0);
	return (1);
}
