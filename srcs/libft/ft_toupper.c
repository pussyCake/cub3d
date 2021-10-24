
#include "libft.h"

int	ft_toupper(int chr)
{
	if (chr >= 97 && chr <= 122)
		return (chr - 32);
	return (chr);
}
