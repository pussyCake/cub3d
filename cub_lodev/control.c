/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:50:37 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/22 10:55:39 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_key_control(t_cub *cub)
{
	ft_print_black_map(cub, 0x000000);
	if (cub->key_w == 1)
	{
		cub->plr->y += sin(cub->plr->dir) * 4;
		cub->plr->x -= cos(cub->plr->dir) * 4;
	}
	if (cub->key_s == 1)
	{
		cub->plr->y -= sin(cub->plr->dir) * 4;
		cub->plr->x += cos(cub->plr->dir) * 4;
	}
	if (cub->key_left == 1)
	{
		cub->plr->dir -= 0.05;
		if (cub->plr->dir < 0)
			cub->plr->dir += M_PI * 2;
		if (cub->plr->dir > M_PI * 2)
			cub->plr->dir -= M_PI * 2;
	}if (cub->key_right == 1)
	{
		cub->plr->dir += 0.05;
		if (cub->plr->dir > M_PI * 2)
			cub->plr->dir -= M_PI * 2;
	}
	if (cub->key_a == 1)
	{
		cub->plr->y += sin(cub->plr->dir + M_PI_2) * 4;
		cub->plr->x += cos(cub->plr->dir + M_PI_2) * 4;
	}
	if (cub->key_d == 1)
	{
		cub->plr->y -= sin(cub->plr->dir + M_PI_2) * 4;
		cub->plr->x -= cos(cub->plr->dir + M_PI_2) * 4;
	}
	if (cub->key_esc == 1)
		exit(0);
		//mlx_destroy_window(win->mlx, win->win);
	ft_print_map(cub, 0x808080, 0xfcf5a4);
	//ft_cast_ray(cub, 0x808080);
	//ft_print_map(cub, 0xFFFFFF, 0x991199);
	return (0);
}

int		key_unpress( int key, t_cub *cub)
{
	if (key == KEY_W)
		cub->key_w = 0;
	if (key == KEY_S)
		cub->key_s = 0;
	if (key == KEY_A)
		cub->key_a = 0;
	if (key == KEY_D)
		cub->key_d = 0;
	if (key == KEY_L)
		cub->key_left = 0;
	if (key == KEY_R)
		cub->key_right = 0;
	if (key == KEY_ESC)
	 	cub->key_w = 0;
	return (0);
}

int		key_press( int key, t_cub *cub)
{
	if (key == KEY_W)
		cub->key_w = 1;
	if (key == KEY_S)
		cub->key_s = 1;
	if (key == KEY_A)
		cub->key_a = 1;
	if (key == KEY_D)
		cub->key_d = 1;
	if (key == KEY_L)
		cub->key_left = 1;
	if (key == KEY_R)
		cub->key_right = 1;
	if (key == KEY_ESC)
	 	cub->key_esc = 1;
	return (0);
}
