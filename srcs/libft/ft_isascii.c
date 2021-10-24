
#include "libft.h"

int	ft_isascii(int chr)
{
	if (chr >= 0 && chr <= 127)
		return (1);
	return (0);
}
