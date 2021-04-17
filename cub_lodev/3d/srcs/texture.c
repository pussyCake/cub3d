/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:00:32 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/17 14:41:42 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_texture(t_cub *cub)
{
	double	wallx;

	if (cub->rc.wall == 0 || cub->rc.wall == 2)
		wallx = cub->rc.rpos.y + cub->rc.dist * cub->rc.rdir.y;
	else
		wallx = cub->rc.rpos.x + cub->rc.dist * cub->rc.rdir.x;
	wallx -= floor((wallx));
	cub->rc.text.x = (int)(wallx * 64.0);
	if ((cub->rc.wall == 0 || cub->rc.wall == 2) && cub->rc.rdir.x > 0)
		cub->rc.text.x = 64 - cub->rc.text.x - 1;
	if ((cub->rc.wall == 1 || cub->rc.wall == 3) && cub->rc.rdir.y < 0)
		cub->rc.text.x = 64 - cub->rc.text.x - 1;
	if ((cub->rc.wall == 0 || cub->rc.wall == 2) && cub->rc.rdir.x >= 0)
		cub->rc.text.id = 1;
	else if ((cub->rc.wall == 0 || cub->rc.wall == 2) && cub->rc.rdir.x < 0)
		cub->rc.text.id = 0;
	else if ((cub->rc.wall == 1 || cub->rc.wall == 3) && cub->rc.rdir.y < 0)
		cub->rc.text.id = 2;
	else
		cub->rc.text.id = 3;
	cub->rc.step_text = 1.0 * 64 / cub->rc.rh;
	cub->rc.text_pos = (cub->rc.wstart - cub->win_h / 2
			+ cub->rc.rh / 2) * cub->rc.step_text;
}
