
#include "libft.h"

int	ft_tolower(int chr)
{
	if (chr >= 65 && chr <= 90)
		return (chr + 32);
	return (chr);
}
