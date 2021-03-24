/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:58:42 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/24 06:49:24 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_exit(t_cub *cub)
{
	// free_tab(info);
	// free_img(info);
	// free_textur(info, info->textur1);
	// free_textur(info, info->textur2);
	// free_textur(info, info->textur3);
	// free_textur(info, info->textur4);
	// free_textur(info, info->sprite);
	// if (info->win_ptr)
	// 	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	// if (info->mlx_ptr)
	// 	free(info->mlx_ptr);
	exit(1);
}

void	ft_notify_error_param(char *msg, t_cub *cub, char *s)
{
	write(2, "\n", 1);
	write(2, "\033[1;31mError: \033[1;37m", 22);
	write(2, msg, ft_strlen(msg));
	write(2, s, ft_strlen(s));
	// if (c == 'R')
	// 	write(2, "R", 1);
	// if (c == 'N')
	// 	write(2, "NO", 2);
	// if (c == 'S')
	// 	write(2, "S or SO", 7);
	// if (c == 'W')
	// 	write(2, "WE", 2);
	// if (c == 'E')
	// 	write(2, "EA", 2);
	// if (c == 'F' || c == 'C')
	// 	write(2, "F or C", 6);
	write(2, "\n", 1);
	write(2, "\n", 1);
	exit(1);
}

void	ft_notify_error(char *msg, t_cub *cub)
{
	write(2, "\n", 1);
	write(2, "\033[1;31mError: \033[1;37m", 22);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	write(2, "\n", 1);
	exit(1);
	//ft_exit(cub);
}
