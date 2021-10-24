
#include "libft.h"

void	ft_putlist(char *str)
{
	ft_putstr_fd(str, 0);
	write(1, "\n", 1);
}
