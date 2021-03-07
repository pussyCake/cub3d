/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:28:17 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/07 15:02:32 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "get_next_line.h"

char	**make_map(t_list **head, int size)
{
	
}

void	parse_map(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_list	*head;
	
	line = NULL;
	head = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_listsize(head));
}