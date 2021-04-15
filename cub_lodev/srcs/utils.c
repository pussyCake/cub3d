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

t_img	*ft_create_text(t_cub *cub, char *add)
{
	t_img *texture;

	if (!(texture = malloc(sizeof(t_img))))
		return (NULL);
	if (!(texture->img = mlx_xpm_file_to_image(cub->mlx, add,
		&texture->width, &texture->height)))
		return (NULL);
	if (!(texture->addr = mlx_get_data_addr(texture->img,
		&texture->bpp, &texture->line_length, &texture->endian)))
		return (NULL);
	return (texture);
}

t_img   *ft_new_image(t_cub *cub)
{
	t_img *img;

	if (!(img = malloc(sizeof(t_img))))
		ft_notify_error("img fail", cub);
	if (!(img->img = mlx_new_image(cub->mlx, cub->win_w, cub->win_h)))
		ft_notify_error("img fail", cub);
	if (!(img->addr = mlx_get_data_addr(img->img, &img->bpp,
		&img->line_length, &img->endian)))
		ft_notify_error("img fail", cub);
	img->width = cub->win_w;
	img->height = cub->win_h;
	return (img);
}
