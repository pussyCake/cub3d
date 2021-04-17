/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:58:42 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/17 18:51:52 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_exit(t_cub *cub)
{
	ft_del_data(cub);
	ft_del_img(cub);
	ft_del_text(cub, cub->text_e);
	ft_del_text(cub, cub->text_n);
	ft_del_text(cub, cub->text_s);
	ft_del_text(cub, cub->text_w);
	//ft_del_text(cub, cub->text_sp);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		free(cub->mlx);
	exit(1);
}

void	ft_notify_error_param(char *msg, t_cub *cub, char *s)
{
	write(2, "\n", 1);
	write(2, "\033[1;31mError: \033[1;37m", 22);
	write(2, msg, ft_strlen(msg));
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	write(2, "\n", 1);
	ft_exit(cub);
}

void	ft_notify_error(char *msg, t_cub *cub)
{
	write(2, "\n", 1);
	write(2, "\033[1;31mError: \033[1;37m", 22);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	write(2, "\n", 1);
	ft_exit(cub);
}
