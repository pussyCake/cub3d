/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_second.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:18:59 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/24 15:23:22 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_sprt_for_loop(t_cub *cub)
{
	int	d;
	int	y;

	y = cub->sprt.start_y;
	if (cub->sprt.tf_y > 0 && cub->sprt.column > 0 && cub->sprt.column
		< cub->win_w && cub->sprt.tf_y < cub->rc.zbuff[cub->sprt.column - 1])
	{
		while (y < cub->sprt.end_y)
		{
			d = y * 256 - cub->win_h * 128 + cub->sprt.h * 128;
			cub->sprt.y = ((d * 64) / cub->sprt.h) / 256;
			//cub->col_text = 0x000000;
			cub->col_text = cub->text_sp->addr[cub->text_sp->width
				* cub->sprt.y + cub->sprt.x];
			if (cub->col_text != (int)0xFF000000)
				ft_get_pixel_col(cub->img, cub->col_text, cub->win_w
					- cub->sprt.column, y);
			y++;
		}
	}
}

void	ft_for_draw_sprt(t_cub *cub)
{
	if (cub->sprt.start_y < 0)
		cub->sprt.start_y = 0;
	cub->sprt.end_y = cub->sprt.h / 2 + cub->win_h / 2;
	if (cub->sprt.end_y > cub->win_h)
		cub->sprt.end_y = cub->win_h;
	cub->sprt.w = abs((int)(cub->win_h / (cub->sprt.tf_y)));
	cub->sprt.start_x = -cub->sprt.w / 2 + cub->sprt.scrnx;
	if (cub->sprt.start_x < 0)
		cub->sprt.start_x = 0;
	cub->sprt.end_x = cub->sprt.w / 2 + cub->sprt.scrnx;
	if (cub->sprt.end_x > cub->win_w)
		cub->sprt.end_x = cub->win_w - 1;
}

void	ft_sprtcast(t_cub *cub, int i)
{
	double	inv_det;

	cub->sprt.cam_x = cub->sprt_plc[cub->sprt.spr_ord[i]].x
		- cub->plr.x;
	cub->sprt.cam_y = cub->sprt_plc[cub->sprt.spr_ord[i]].y
		- cub->plr.y;
	inv_det = 1.0 / (cub->rc.plane.x * cub->rc.dir.y - cub->rc.dir.x
			* cub->rc.plane.y);
	cub->sprt.tf_x = inv_det * (cub->rc.dir.y * cub->sprt.cam_x - cub->rc.dir.x
			* cub->sprt.cam_y);
	cub->sprt.tf_y = inv_det * (-cub->rc.plane.y
			* cub->sprt.cam_x + cub->rc.plane.x * cub->sprt.cam_y);
	cub->sprt.scrnx = (int)((cub->win_w / 2) * (1 + cub->sprt.tf_x
				/ cub->sprt.tf_y));
	cub->sprt.h = abs((int)(cub->win_h / cub->sprt.tf_y));
	cub->sprt.start_y = -cub->sprt.h / 2 + cub->win_h / 2;
	ft_for_draw_sprt(cub);
}

void	ft_spr_crt(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->num_sprite)
	{
		ft_sprtcast(cub, i);
		cub->sprt.column = cub->sprt.start_x;
		while (cub->sprt.column < cub->sprt.end_x)
		{
			cub->sprt.x = (int)(256
					* (cub->sprt.column - (-cub->sprt.w / 2 + cub->sprt.scrnx))
					* cub->text_sp->width / cub->sprt.w / 256);
			ft_sprt_for_loop(cub);
			cub->sprt.column++;
		}
	}
}
