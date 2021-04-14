

#include "cub.h"

void	ft_del_buff(void **buff)
{
	int i;

	i = 0;
	if (buff)
	{
		while (buff[i])
			free(buff[i++]);
		free(buff);
	}
}
