/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:27:28 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/15 17:54:15 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_raylen(t_cub *cub)
{
	if (cub->rc.wall == 0 || cub->rc.wall == 2)
		cub->rc.dist = (cub->rc.rmap.x - cub->rc.rpos.x
					+ (1 - cub->rc.step.x) / 2) / cub->rc.rdir.x;
	else
		cub->rc.dist = (cub->rc.rmap.y - cub->rc.rpos.y
					+ (1 - cub->rc.step.y) / 2) / cub->rc.rdir.y;
	cub->rc.rh = ((cub->win_h / cub->rc.dist));
	cub->rc.wstart = ((-cub->rc.rh)) / 2 + cub->win_h / 2;
	if (cub->rc.wstart < 0)
		cub->rc.wstart = 0;
	cub->rc.wend = cub->rc.rh / 2 + cub->win_h / 2;
	if (cub->rc.wend >= cub->win_h)
		cub->rc.wend = cub->win_h - 1;
	//cub->rc.textur.id = (cub->map.tab_map[cub->rc.rmap.y]
	//[cub->rc.rmap.x] - '0') - 1;
}

void	ft_check_hit(t_cub *cub)
{
	while (cub->rc.hit == 0)
	{
		if (cub->rc.rdist.x < cub->rc.rdist.y)
		{
			cub->rc.rdist.x += cub->rc.rdisd.x;
			cub->rc.rmap.x += cub->rc.step.x;
			if (cub->rc.rdir.x < 0)
				cub->rc.wall = 0;
			else
				cub->rc.wall = 2;
		}
		else
		{
			cub->rc.rdist.y += cub->rc.rdisd.y;
			cub->rc.rmap.y += cub->rc.step.y;
			if (cub->rc.rdir.y < 0)
				cub->rc.wall = 1;
			else
				cub->rc.wall = 3;
		}
		if (ft_strchr("1", cub->map[cub->rc.rmap.y][cub->rc.rmap.x]))
			cub->rc.hit = 1;
	}
}

void	ft_dir_ray(t_cub *cub)
{
	if (cub->rc.rdir.x < 0)
	{
		cub->rc.step.x = -1;
		cub->rc.rdist.x = (cub->rc.rpos.x - cub->rc.rmap.x) *
		cub->rc.rdisd.x;
	}
	else
	{
		cub->rc.step.x = 1;
		cub->rc.rdist.x = (cub->rc.rmap.x + 1.0 - cub->rc.rpos.x) *
		cub->rc.rdisd.x;
	}
	if (cub->rc.rdir.y < 0)
	{
		cub->rc.step.y = -1;
		cub->rc.rdist.y = (cub->rc.rpos.y - cub->rc.rmap.y) *
		cub->rc.rdisd.y;
	}
	else
	{
		cub->rc.step.y = 1;
		cub->rc.rdist.y = (cub->rc.rmap.y + 1.0 - cub->rc.rpos.y) *
			cub->rc.rdisd.y;
	}
}

void	ft_init_ray(t_cub *cub, int x)
{
	cub->rc.camera = 2 * x / (double)(cub->win_w) - 1;
	cub->rc.rpos.x = cub->plr.x;
	cub->rc.rpos.y = cub->plr.y;
	cub->rc.rdir.x = cub->rc.dir.x + cub->rc.plane.x * cub->rc.camera;
	cub->rc.rdir.y = cub->rc.dir.y + cub->rc.plane.y * cub->rc.camera;
	cub->rc.rmap.x = (int)cub->rc.rpos.x;
	cub->rc.rmap.y = (int)cub->rc.rpos.y;
	cub->rc.rdisd.x = fabs(1 / cub->rc.rdir.x);
	cub->rc.rdisd.y = fabs(1 / cub->rc.rdir.y);
	cub->rc.hit = 0;
}

void	ft_create_world(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < cub->win_w - 1)
	{
		ft_init_ray(cub, x);
		ft_dir_ray(cub);
		ft_check_hit(cub);
		ft_raylen(cub);
	}
}
