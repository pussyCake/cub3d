/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:27:28 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/24 15:19:49 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_raylen(t_cub *cub)
{
	if (cub->rc.side == 0 || cub->rc.side == 2)
		cub->rc.wall_dist = (cub->rc.map.x - cub->rc.ray.x
				+ (1 - cub->rc.step.x) / 2) / cub->rc.ray_dir.x;
	else
		cub->rc.wall_dist = (cub->rc.map.y - cub->rc.ray.y
				+ (1 - cub->rc.step.y) / 2) / cub->rc.ray_dir.y;
	cub->rc.wall_h = (cub->win_h / cub->rc.wall_dist);
	cub->rc.h_start = (-cub->rc.wall_h) / 2 + cub->win_h / 2;
	if (cub->rc.h_start < 0)
		cub->rc.h_start = 0;
	cub->rc.h_end = cub->rc.wall_h / 2 + cub->win_h / 2;
	if (cub->rc.h_end >= cub->win_h || cub->rc.h_end == -2147483648)
		cub->rc.h_end = cub->win_h - 1;
}

void	ft_check_hit(t_cub *cub)
{
	while (cub->rc.hit == 0)
	{
		if (cub->rc.side_dist.x < cub->rc.side_dist.y)
		{
			cub->rc.side_dist.x += cub->rc.del_dist.x;
			cub->rc.map.x += cub->rc.step.x;
			if (cub->rc.ray_dir.x < 0)
				cub->rc.side = 0;
			else
				cub->rc.side = 2;
		}
		else
		{
			cub->rc.side_dist.y += cub->rc.del_dist.y;
			cub->rc.map.y += cub->rc.step.y;
			if (cub->rc.ray_dir.y < 0)
				cub->rc.side = 1;
			else
				cub->rc.side = 3;
		}
		if (ft_strchr("1", cub->map[cub->rc.map.y][cub->rc.map.x]))
			cub->rc.hit = 1;
	}
}

void	ft_dir_ray(t_cub *cub)
{
	if (cub->rc.ray_dir.x < 0)
	{
		cub->rc.step.x = -1;
		cub->rc.side_dist.x = (cub->rc.ray.x - cub->rc.map.x)
			* cub->rc.del_dist.x;
	}
	else
	{
		cub->rc.step.x = 1;
		cub->rc.side_dist.x = (cub->rc.map.x + 1.0 - cub->rc.ray.x)
			* cub->rc.del_dist.x;
	}
	if (cub->rc.ray_dir.y < 0)
	{
		cub->rc.step.y = -1;
		cub->rc.side_dist.y = (cub->rc.ray.y - cub->rc.map.y)
			* cub->rc.del_dist.y;
	}
	else
	{
		cub->rc.step.y = 1;
		cub->rc.side_dist.y = (cub->rc.map.y + 1.0 - cub->rc.ray.y)
			* cub->rc.del_dist.y;
	}
}

void	ft_init_ray(t_cub *cub, int x)
{
	cub->rc.cam_x = 2 * x / (double)(cub->win_w) - 1;
	cub->rc.ray.x = cub->plr.x;
	cub->rc.ray.y = cub->plr.y;
	cub->rc.ray_dir.x = cub->rc.dir.x + cub->rc.plane.x * cub->rc.cam_x;
	cub->rc.ray_dir.y = cub->rc.dir.y + cub->rc.plane.y * cub->rc.cam_x;
	cub->rc.map.x = (int)cub->rc.ray.x;
	cub->rc.map.y = (int)cub->rc.ray.y;
	cub->rc.del_dist.x = fabs(1 / cub->rc.ray_dir.x);
	cub->rc.del_dist.y = fabs(1 / cub->rc.ray_dir.y);
	cub->rc.hit = 0;
}

void	ft_create_world(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < cub->win_w)
	{
		ft_init_ray(cub, x);
		ft_dir_ray(cub);
		ft_check_hit(cub);
		ft_raylen(cub);
		ft_texture(cub);
		ft_get_pixel(cub, cub->win_w - x - 1);
		cub->rc.zbuff[x] = cub->rc.wall_dist;
		x++;
	}
	ft_make_spr(cub);
}
