/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:58:05 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/15 13:58:05 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(int *)dst = color;
}

t_img	*ft_create_text(t_cub *cub, char *add)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img));
	if (!(texture))
		return (NULL);
	texture->img = mlx_xpm_file_to_image(cub->mlx, add, &texture->width,
			&texture->height);
	if (!(texture->img))
		return (NULL);
	texture->addr = mlx_get_data_addr(texture->img,
			&texture->bpp, &texture->line_length, &texture->endian);
	if (!(texture->addr))
		return (NULL);
	return (texture);
}

t_img	*ft_new_image(t_cub *cub)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!(img))
		ft_notify_error("img fail", cub);
	img->img = mlx_new_image(cub->mlx, cub->win_w, cub->win_h);
	if (!(img->img))
		ft_notify_error("img fail", cub);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	if (!(img->addr))
		ft_notify_error("img fail", cub);
	img->width = cub->win_w;
	img->height = cub->win_h;
	return (img);
}