/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:20:18 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/24 13:58:41 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pixel_textur(t_img *text, t_cub *cub)
{
	cub->col_text = text->addr[64
		* cub->rc.text.y + cub->rc.text.x];
}

void	ft_get_col_text(t_cub *cub)
{
	if (cub->rc.text.id == 0)
		pixel_textur(cub->text_w, cub);
	else if (cub->rc.text.id == 1)
		pixel_textur(cub->text_n, cub);
	else if (cub->rc.text.id == 2)
		pixel_textur(cub->text_e, cub);
	else if (cub->rc.text.id == 3)
		pixel_textur(cub->text_s, cub);
}

void	ft_get_pixel_col(t_img *img, unsigned int colour, int x, int y)
{
	if (y >= img->height || x >= img->width || x < 0
		|| y < 0)
		return ;
	img->addr[y * img->width + x] = colour;
}

void	ft_get_pixel(t_cub *cub, int x)
{
	int	y;

	y = 0;
	while (y < cub->rc.h_start)
		ft_get_pixel_col(cub->img, cub->col_c.all, x, y++);
	while (y >= cub->rc.h_start && y <= cub->rc.h_end)
	{
		cub->rc.text.y = (int)cub->rc.text_pos & (64 - 1);
		cub->rc.text_pos += cub->rc.step_text;
		ft_get_col_text(cub);
		if (cub->col_text == (int)0xFF000000)
			ft_get_pixel_col(cub->img, 0x00000000, x, y);
		else
			ft_get_pixel_col(cub->img, cub->col_text, x, y);
		y++;
	}
	while (y < cub->win_h)
		ft_get_pixel_col(cub->img, cub->col_f.all, x, y++);
}
