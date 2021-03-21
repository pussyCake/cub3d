/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:57:32 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/21 12:15:27 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_get_direct(t_cub *cub, char c)
{
	if (c == 'E')
		cub->plr->dir = 0;
	else if (c == 'W')
		cub->plr->dir = M_PI;
	else if (c == 'N')
		cub->plr->dir = M_PI_2;
	else if (c == 'S')
		cub->plr->dir = M_PI_2 * 3;
}

void	ft_make_plr(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	while (cub->map[j])
	{
		i = 0;
		while (cub->map[j][i])
		{
			if (ft_strrchr("NWES", cub->map[j][i]))
			{
				cub->plr->x = i * SCALE + (SCALE / 2);
				cub->plr->y = j * SCALE + (SCALE / 2);
				ft_get_direct(cub, cub->map[j][i]);
			}
			i++;
		}
		j++;
	}
}

void	make_map(t_cub *cub)
{
	int		i;
	int		size;
	t_list	*tmp;

	size = ft_lstsize(cub->tmap);
	cub->map = ft_calloc(size + 1, sizeof(char*));
	i = 0;
	//tmp = *head;
	while (cub->tmap)
	{
		if (cub->tmap->content)
			cub->map[i++] = cub->tmap->content;
		else
			free(cub->tmap->next);
		cub->tmap = cub->tmap->next;
	}
	ft_make_plr(cub);
}