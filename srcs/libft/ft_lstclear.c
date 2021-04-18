/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:30:15 by pantigon          #+#    #+#             */
/*   Updated: 2020/11/08 16:16:48 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buff;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		buff = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buff;
	}
}
