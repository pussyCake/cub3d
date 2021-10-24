
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*buff;

	buff = lst;
	if (buff == NULL)
		return (NULL);
	while (buff->next != NULL)
		buff = buff->next;
	return (buff);
}
