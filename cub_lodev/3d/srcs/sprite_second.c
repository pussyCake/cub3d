/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_second.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:18:59 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/16 18:42:14 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// static void	add_sprite_part_two(t_cub *cub)
// {
// 	int d;
// 	int y;

// 	y = cub->sprt.drawstart_y;
// 	if (cub->sprt.transy > 0 && cub->sprt.stripe > 0 && cub->sprt.stripe <
// 	cub->win_w && cub->sprt.transy < cub->rc.zbuff[cub->sprt.stripe])
// 	{
// 		while (y < cub->sprt.drawend_y)
// 		{
// 			d = y * 256 - cub->win_h * 128 + cub->sprt.sprite_height * 128;
// 			cub->sprt.y =
// 			((d * 64) / cub->sprt.sprite_height) / 256;
// 			cub->col.text = cub->text_sp->addr[cub->text_sp->width *
// 			cub->sprt.y + cub->sprt.x];
// 			if (cub->col.text != PINK && cub->col.text != BLACK)
// 				put_pixel(cub->img, cub->col.text, cub->sprt.stripe, y);
// 			y++;
// 		}
// 	}
// }

static void	calc_end_start(t_cub *cub)
{
	if (cub->sprt.drawstart_y < 0)
		cub->sprt.drawstart_y = 0;
	cub->sprt.drawend_y = cub->sprt.sprite_height / 2 + cub->win_h / 2;
	if (cub->sprt.drawend_y >= cub->win_h)
		cub->sprt.drawend_y = cub->win_h - 1;
	cub->sprt.sprite_width = abs((int)(cub->win_h / (cub->sprt.transy)));
	cub->sprt.drawstart_x = -cub->sprt.sprite_width / 2 + cub->sprt.spritescreenx;
	if (cub->sprt.drawstart_x < 0)
		cub->sprt.drawstart_x = 0;
	cub->sprt.drawend_x = cub->sprt.sprite_width / 2 + cub->sprt.spritescreenx;
	if (cub->sprt.drawend_x >= cub->win_w)
		cub->sprt.drawend_x = cub->win_w - 1;
}

static void	sprite_calc(t_cub *cub, int i)
{
	double inv;

	cub->sprt.spcamx = cub->sprt_plc[cub->rc.sp_order[i]].x
	- cub->plr.x;
	cub->sprt.spcamy = cub->sprt_plc[cub->rc.sp_order[i]].y
	- cub->plr.y;
	inv = 1.0 / (cub->rc.plane.x * cub->rc.dir.y - cub->rc.dir.x *
		cub->rc.plane.y);
	cub->sprt.transx = inv * (cub->rc.dir.y * cub->sprt.spcamx - cub->rc.dir.x *
		cub->sprt.spcamy);
	cub->sprt.transy = inv * (-cub->rc.plane.y *
	cub->sprt.spcamx + cub->rc.plane.x * cub->sprt.spcamy);
	cub->sprt.spritescreenx = (int)((cub->win_w / 2) * (1 + cub->sprt.transx /
		cub->sprt.transy));
	cub->sprt.sprite_height = abs((int)(cub->win_h / cub->sprt.transy));
	cub->sprt.drawstart_y = -cub->sprt.sprite_height / 2 + cub->win_h / 2;
	calc_end_start(cub);
}

void		add_sprite(t_cub *cub)
{
	int i;

	i = -1;
	while (++i < cub->num_sprite)
	{
		sprite_calc(cub, i);
		cub->sprt.stripe = cub->sprt.drawstart_x;
		while (cub->sprt.stripe < cub->sprt.drawend_x)
		{
			cub->sprt.x = (int)(256 *
			(cub->sprt.stripe - (-cub->sprt.sprite_width
			/ 2 + cub->sprt.spritescreenx)) * cub->text_sp->width /
			cub->sprt.sprite_width / 256);
			add_sprite_part_two(cub);
			cub->sprt.stripe++;
		}
	}
}
