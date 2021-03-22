/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:57:32 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/22 14:22:58 by pantigon         ###   ########.fr       */
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
		ft_check_map(cub->map[j], j, cub);
		while (cub->map[j][i])
		{
			if (ft_strrchr("NWES", cub->map[j][i]))
			{
				cub->plr->x = i * SCALE + (SCALE / 2);
				cub->plr->y = j * SCALE + (SCALE / 2);
				ft_get_direct(cub, cub->map[j][i]);
				cub->plr->check += 1;
			}
			i++;
		}
		//if (!ft_check_map(cub->map[j], j))
		///ft_notify_error("no valid map");
		j++;
	}
}

void	make_map(t_cub *cub)
{
	int		i;
	t_list	*tmp;

	cub->map_h = ft_lstsize(cub->tmap);
	cub->map = ft_calloc(cub->map_h + 1, sizeof(char*));
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