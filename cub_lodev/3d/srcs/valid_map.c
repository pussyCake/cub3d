/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:28:41 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/17 14:50:15 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check_inmap(t_cub *cub, int y, int x)
{
	if (!ft_strchr("012NSWE", cub->map[y][x - 1]))
		ft_notify_error("map fail", cub);
	else if (!ft_strchr("012NSWE", cub->map[y][x + 1]))
		ft_notify_error("map fail", cub);
	else if (!ft_strchr("012NSWE", cub->map[y - 1][x]))
		ft_notify_error("map fail", cub);
	else if (!ft_strchr("012NSWE", cub->map[y + 1][x]))
		ft_notify_error("map fail", cub);
	else if (!ft_strchr("012NSWE", cub->map[y + 1][x - 1]))
		ft_notify_error("map fail", cub);
	else if (!ft_strchr("012NSWE", cub->map[y + 1][x + 1]))
		ft_notify_error("map fail", cub);
	else if (!ft_strchr("012NSWE", cub->map[y - 1][x - 1]))
		ft_notify_error("map fail", cub);
	else if (!ft_strchr("012NSWE", cub->map[y - 1][x + 1]))
		ft_notify_error("map fail", cub);
}

void	ft_skip_space(t_cub *cub, int y, int *x)
{
	while (cub->map[y][*x] != '1'
		&& cub->map[y][*x])
	{
		if (cub->map[y][*x] != ' ')
			ft_notify_error("map fail", cub);
		(*x)++;
	}
}

void	ft_parse(t_cub *cub, int y, int *x)
{
	if (x == 0)
		ft_skip_space(cub, y, x);
	if ((y == 0) || (y == cub->map_h - 1))
		if (cub->map[y][*x] != '1' && cub->map[y][*x] != ' ')
			ft_notify_error("fail map", cub);
	if ((ft_strchr("0NSEW", cub->map[y][*x])) && y != 0
		&& y != cub->map_h && *x != 0)
		ft_check_inmap(cub, y, *x);
	//printf("%d:%d\n", y, *x);
	//ft_putendl_fd("START", 0);
}

void	ft_valid_map(t_cub *cub)
{
	int	x;
	int	y;
	//int start_x;

	y = 0;
	while (y < cub->map_h)
	{
//		start_x = x;
		//ft_putendl_fd("START", 0);
		x = 0;
		while (cub->map[y][x])
		{
			ft_parse(cub, y, &x);
			x++;
			//printf("%c", cub->map[y][x]);
		}
		//printf("\n");
		y++;
	}
}
