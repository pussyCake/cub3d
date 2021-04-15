/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:48:55 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/15 17:13:42 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_view(t_cub *cub, int side)
{
	double	dir;
	double	plane;

	dir = cub->rc.dir.x;
	plane = cub->rc.plane.x;
	cub->rc.dir.x = cub->rc.dir.x * cos(side * 0.05)
		- cub->rc.dir.y * sin(side * 0.05);
	cub->rc.dir.y = dir * sin(side * 0.05)
		+ cub->rc.dir.y * cos(side * 0.05);
	cub->rc.plane.x = cub->rc.plane.x * cos(side * 0.05)
		- cub->rc.plane.y * sin(side * 0.05);
	cub->rc.plane.y = plane * sin(side * 0.05)
		+ cub->rc.plane.y * cos(side * 0.05);
}

void	ft_left_right(t_cub *cub)
{
	if (cub->key_right == 1)
	{
		if (cub->map[(int)(cub->plr.y - cub->rc.dir.x *
			cub->rc.speed)][(int)(cub->plr.x)] == '0')
			cub->plr.y -= cub->rc.dir.x * cub->rc.speed;
		if (cub->map[(int)(cub->plr.y)][(int)(cub->plr.x
			+ cub->rc.dir.y * cub->rc.speed)] == '0')
			cub->plr.x += cub->rc.dir.y * cub->rc.speed;
	}
	if (cub->key_left == 1)
	{
		if (cub->map[(int)(cub->plr.y + cub->rc.dir.x *
			cub->rc.speed)][(int)(cub->plr.x)] == '0')
			cub->plr.y -= -cub->rc.dir.x * cub->rc.speed;
		if (cub->map[(int)(cub->plr.y)][(int)(cub->plr.x -
			cub->rc.dir.y * cub->rc.speed)] == '0')
			cub->plr.x -= cub->rc.dir.y * cub->rc.speed;
	}
}

void	ft_up_down(t_cub *cub)
{
	if (cub->key_w == 1)
	{
		if (cub->map[(int)(cub->plr.y)][(int)(cub->plr.x +
		cub->rc.dir.x * cub->rc.speed)] == '0')
			cub->plr.x += cub->rc.dir.x * cub->rc.speed;
		if (cub->map[(int)(cub->plr.y + cub->rc.dir.y *
			cub->rc.speed)][(int)(cub->plr.x)] == '0')
			cub->plr.y += cub->rc.dir.y * cub->rc.speed;
	}
	if (cub->key_a == 1)
	{
		if (cub->map[(int)(cub->plr.y)][(int)(cub->plr.x -
		cub->rc.dir.x * cub->rc.speed)] == '0')
			cub->plr.x -= cub->rc.dir.x * cub->rc.speed;
		if (cub->map[(int)(cub->plr.y - cub->rc.dir.y *
			cub->rc.speed)][(int)(cub->plr.x)] == '0')
			cub->plr.y -= cub->rc.dir.y * cub->rc.speed;
	}
}

void	ft_control(t_cub *cub)
{
	if (cub->key_w == 1 || cub->key_s == 1)
		ft_up_down(cub);
	if (cub->key_a == 1 || cub->key_d == 1)
		ft_left_right(cub);
	if (cub->key_left == 1)
		ft_view(cub, 1);
	if (cub->key_right == 1)
		ft_view(cub, -1);
}
