/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:00:32 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/17 22:00:51 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_texture(t_cub *cub)
{
	double	wallx;

	if (cub->rc.side == 0 || cub->rc.side == 2)
		wallx = cub->rc.ray.y + cub->rc.wall_dist * cub->rc.ray_dir.y;
	else
		wallx = cub->rc.ray.x + cub->rc.wall_dist * cub->rc.ray_dir.x;
	wallx -= floor((wallx));
	cub->rc.text.x = (int)(wallx * 64.0);
	if ((cub->rc.side == 0 || cub->rc.side == 2) && cub->rc.ray_dir.x > 0)
		cub->rc.text.x = 64 - cub->rc.text.x - 1;
	if ((cub->rc.side == 1 || cub->rc.side == 3) && cub->rc.ray_dir.y < 0)
		cub->rc.text.x = 64 - cub->rc.text.x - 1;
	if ((cub->rc.side == 0 || cub->rc.side == 2) && cub->rc.ray_dir.x >= 0)
		cub->rc.text.id = 2;
	else if ((cub->rc.side == 0 || cub->rc.side == 2) && cub->rc.ray_dir.x < 0)
		cub->rc.text.id = 0;
	else if ((cub->rc.side == 1 || cub->rc.side == 3) && cub->rc.ray_dir.y < 0)
		cub->rc.text.id = 1;
	else
		cub->rc.text.id = 3;
	cub->rc.step_text = 1.0 * 64 / cub->rc.wall_h;
	cub->rc.text_pos = (cub->rc.h_start - cub->win_h / 2
			+ cub->rc.wall_h / 2) * cub->rc.step_text;
}
