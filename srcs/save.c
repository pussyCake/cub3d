/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:00:56 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/18 20:56:24 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_make_char(int num, unsigned char *ch)
{
	ch[0] = (unsigned char)num;
	ch[1] = (unsigned char)(num >> 8);
	ch[2] = (unsigned char)(num >> 16);
	ch[3] = (unsigned char)(num >> 24);
}

void	ft_make_header(t_cub *cub, int fd, int size)
{
	unsigned char	header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	ft_make_char(size, header + 2);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	ft_make_char(cub->win_w, header + 18);
	ft_make_char(cub->win_h, header + 22);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	write(fd, header, 54);
}

void	ft_get_clr(t_cub *cub, int fd)
{
	int				x;
	int				y;
	unsigned char	rgb[3];

	ft_bzero(rgb, 3);
	y = cub->win_h - 1;
	while (y >= 0)
	{
		x = -1;
		while (++x < cub->win_w)
		{
			rgb[0] = (unsigned char)(cub->img->addr[y * cub->win_w + x]);
			rgb[1] = (unsigned char)(cub->img->addr[y * cub->win_w + x] >> 8);
			rgb[2] = (unsigned char)(cub->img->addr[y * cub->win_w + x] >> 16);
			write(fd, rgb, 3);
		}
		y--;
	}
}

void	ft_save(t_cub *cub)
{
	int	fd;
	int	size;

	ft_create_world(cub);
	size = 54 + cub->win_h * cub->win_w * 3;
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT
			| O_TRUNC, S_IRWXU);
	if (!fd)
		ft_notify_error("don't make screenshot", cub);
	ft_make_header(cub, fd, size);
	ft_get_clr(cub, fd);
	ft_exit(cub);
}
