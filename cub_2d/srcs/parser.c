/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:28:17 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/16 19:57:22 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_plr(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	while (cub->map[j])
	{
		i = 0;
		while (cub->map[j][i])
		{
			if (cub->map[j][i] == 'N')
			{
				cub->plr->x = i * SCALE;
				cub->plr->y = j * SCALE;
				// cub->plr->x = i;
				// cub->plr->y = j;
			}
			i++;
		}
		j++;
	}
}

void	make_map(t_list **head, int size, t_cub *cub)
{
	int		i;
	t_list	*tmp;

	cub->map = ft_calloc(size + 1, sizeof(char*));
	i = -1;
	tmp = *head;
	while (tmp)
	{
		cub->map[++i] = tmp->content;
		tmp = tmp->next;
	}
	ft_init_plr(cub);
}

void	parse_map(int argc, char **argv, t_cub *cub)
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
	make_map(&head, ft_lstsize(head), cub);
}