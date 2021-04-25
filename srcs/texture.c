/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:00:32 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/24 17:32:16 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_texture(t_cub *cub, t_img *text, int x)
{
	double	wallx;

	if (cub->rc.text.id == 0 || cub->rc.text.id == 2)
		wallx = cub->rc.ray.y + cub->rc.wall_dist * cub->rc.ray_dir.y;
	else
		wallx = cub->rc.ray.x + cub->rc.wall_dist * cub->rc.ray_dir.x;
	wallx -= floor((wallx));
	cub->rc.text.x = (int)(wallx * text->height);
	if ((cub->rc.text.id == 0 || cub->rc.text.id == 2) && cub->rc.ray_dir.x > 0)
		cub->rc.text.x = text->height - cub->rc.text.x - 1;
	if ((cub->rc.text.id == 1 || cub->rc.text.id == 3) && cub->rc.ray_dir.y < 0)
		cub->rc.text.x = text->height - cub->rc.text.x - 1;
	cub->rc.step_text = 1.0 * text->height / cub->rc.wall_h;
	cub->rc.text_pos = (cub->rc.h_start - cub->win_h / 2
			+ cub->rc.wall_h / 2) * cub->rc.step_text;
	ft_get_pixel(cub, cub->win_w - x - 1, text);
}
