/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:43:54 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/17 14:40:08 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_sort_sprt(t_cub *cub)
{
	int		i;
	int		buff;
	double	temp;

	i = 0;
	while (i < cub->num_sprite - 1)
	{
		if (cub->rc.sp_distance[i] < cub->rc.sp_distance[i + 1])
		{
			temp = cub->rc.sp_distance[i + 1];
			cub->rc.sp_distance[i + 1] = cub->rc.sp_distance[i];
			cub->rc.sp_distance[i] = temp;
			buff = cub->rc.sp_order[i + 1];
			cub->rc.sp_order[i + 1] = cub->rc.sp_order[i];
			cub->rc.sp_order[i] = buff;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_chain_sprt(t_cub *cub)
{
	int		i;

	i = 0;
	while (i < cub->num_sprite)
	{
		cub->rc.sp_order[i] = i;
		cub->rc.sp_distance[i] = ((cub->plr.x - cub->sprt_plc[i].x)
				* (cub->plr.x - cub->sprt_plc[i].x)
				+ (cub->plr.y - cub->sprt_plc[i].y)
				* (cub->plr.y - cub->sprt_plc[i].y));
		i++;
	}
	ft_sort_sprt(cub);
	add_sprite(cub);
}

void	ft_point_sprt(t_cub *cub)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < cub->map_h)
	{
		x = 0;
		while (x < cub->place_char)
		{
			if (cub->map[y][x] == '2')
			{
				cub->sprt_plc[i].x = x + 0.5;
				cub->sprt_plc[i].y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	ft_make_spr(t_cub *cub)
{
	cub->sprt_plc = malloc(sizeof(t_plr) * cub->num_sprite);
	if (!(cub->sprt_plc))
		ft_notify_error("fail sprite", cub);
	cub->rc.sp_order = malloc(sizeof(int) * cub->num_sprite);
	if (!(cub->rc.sp_order))
		ft_notify_error("fail sprite", cub);
	cub->rc.sp_distance = malloc(sizeof(double) * cub->num_sprite);
	if (!(cub->rc.sp_distance))
		ft_notify_error("fail sprite", cub);
	ft_point_sprt(cub);
	ft_chain_sprt(cub);
	if (cub->sprt_plc)
		free(cub->sprt_plc);
	if (cub->rc.sp_order)
		free(cub->rc.sp_order);
	if (cub->rc.sp_distance)
		free(cub->rc.sp_distance);
}
