/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:23:20 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/13 15:27:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		ft_place_plr(t_cub *cub, int y, int x)
{
	if (cub->flag_plr == 0 && (ft_strchr("NSWE", cub->map[y][x])))
	{
		cub->flag_plr = 1;
		cub->plr->plr = cub->map[y][x];
		cub->plr->x = x + 0.5;
		cub->plr->y = y + 0.5;
		cub->map[i][j] = '0';
	}
	if (cub->map[y][x] == '2')
		cub->num_sprite++;
}

void	ft_novalid_sym(t_cub *cub, int y, int x)
{
	if (!ft_strrchr("012SWEN ", cub->map[y][x]))
		ft_notify_error("no valid symbol in map", cub);
	if (cub->flag_plr == 1 && (ft_strchr("NSWE", cub->map[y][x])))
		ft_notify_error("no valid map", cub);
}

void	ft_walk_map(t_cub *cub)
{
	int x;
	int y;
	int k;

	y = 1;
	while (cub->map[y] && y < cub->map_h)
	{
		k = ft_strlen(info->map.tab_map[i]);
		cub->h_total += k;
		x = 1;
		while (cub->map[y][x])
		{
			ft_novalid_sym(cub, y, x);
			ft_place_plr(cub, y, x);
			x++;
		}
		y++;
	}
	cub->place_char = k;
}

void	ft_check_map(t_cub *cub)
{
	ft_valid_map(cub);
	cub->h_total = ft_strlen(cub->map[0] + ft_strlen(cub->map[cub->map_h -1]));
	ft_walk_map(cub);
	if (cub->flag_plr == 0)
		ft_notify_error("no valid map", cub);
}
