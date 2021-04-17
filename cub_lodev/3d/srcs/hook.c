/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:13:35 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/17 13:55:22 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_unpress( int key, t_cub *cub)
{
	if (key == KEY_W || key == KEY_UP)
		cub->key_w = 0;
	if (key == KEY_S || key == KEY_DW)
		cub->key_s = 0;
	if (key == KEY_A)
		cub->key_a = 0;
	if (key == KEY_D)
		cub->key_d = 0;
	if (key == KEY_L)
		cub->key_left = 0;
	if (key == KEY_R)
		cub->key_right = 0;
	return (0);
}

int	key_press( int key, t_cub *cub)
{
	if (key == KEY_W || key == KEY_UP)
		cub->key_w = 1;
	if (key == KEY_S || key == KEY_DW)
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
		ft_exit(cub); //обработтать чистку всего
	return (0);
}

// void	ft_p_big(t_cub *cub, int x, int y, int col)
// {
// 	int x_start;
// 	int y_start;
// 	int scale;

// 	scale = 16;
// 	y = y * scale;
// 	x = x * scale;
// 	x_start = x;
// 	y_start = y;
// 	while ((y++ < y_start + scale))
// 	{
// 		x = x_start;
// 		while (x++ < x_start + scale)
// 			my_mlx_pixel_put(cub->img, x, y, col);
// 	}
// }

// void	ft_print_map(t_cub *cub, int col, int col_plr)
// {
// 	int i;
// 	int j;

// 	j = 0;
// 	while (cub->map[j])
// 	{
// 		i = 0;
// 		while (cub->map[j][i])
// 		{
// 			//my_mlx_pixel_put(cub->win, i * 16, j * 16, 0xFFFFFF);
// 			if (cub->map[j][i] == '1')
// 				ft_p_big(cub, i, j, col);
// 			i++;
// 		}
// 		j++;
// 	}
// 	//ft_cast_ray(cub, col_plr);
// 	ft_p_big(cub, cub->plr.x, cub->plr.y, col_plr);
// 	//mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
// }

int	ft_loop_game(t_cub *cub)
{
	ft_free_img(cub);
	cub->img = ft_new_image(cub);
	if (!cub->img)
		ft_notify_error("fail in create img", cub);
	ft_control(cub);
	ft_create_world(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
	return (0);
}

void	ft_hook(t_cub *cub)
{
	// if (!(cub->win = mlx_new_window(cub->mlx, cub->win_w, cub->win_h, "GAME")))
	// 	ft_notify_error("fail mlx (create win)", cub);
	mlx_hook(cub->win, 2, 1L << 1, key_press, cub);
	mlx_hook(cub->win, 3, 0, key_unpress, cub);
	mlx_hook(cub->win, 17, 1L << 0, ft_exit, cub);
	if (mlx_loop_hook(cub->mlx, ft_loop_game, cub) != 0)
		ft_notify_error("loop_hook fail", cub);
	mlx_loop(cub->mlx);
}
