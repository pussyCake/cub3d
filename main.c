/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:05:25 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/10 18:51:37 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void            my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(int *)dst = color;
}

void	ft_p_big(t_win *img, int x, int y, int col)
{
	int mash;
	int x_start;
	int y_start;

	mash = 15;
	y = y * mash;
	x = x * mash;
	x_start = x;
	y_start = y;
	while ((y++ < y_start + mash))
	{
		x = x_start;
		while (x++ < x_start + mash)
			my_mlx_pixel_put(img, x, y, col);
	}
}

void	ft_print_map(t_cub *cub)
{
	int i;
	int j;

	j = 0;
	while (cub->map[j])
	{
		i = 0;
		while (cub->map[j][i])
		{
			if (cub->map[j][i] == '1')
				ft_p_big(cub->win, i, j, 0xFFFFFF);
			i++;
		}
		j++;
	}
	ft_p_big(cub->win, cub->plr->x, cub->plr->y, 0x8a2be2);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
}

int		key_hook(int keycode, t_win *win)
{
    printf("Hello from key_hook!\n");
	return (0);
}

int		ft_close(int key, t_cub *cub)
{
	if (key == 13)
		cub->plr->y -= 1;
	if (key == 1)
		cub->plr->y += 1;
	if (key == 0)
		cub->plr->x -= 1;
	if (key == 2)
		cub->plr->x += 1;
	if (key == 53)
		exit(0);
		//mlx_destroy_window(win->mlx, win->win);
	ft_print_map(cub);
	return (0);
}

// t_cub	ft_init_cub()
// {
// 	t_cub	cub;
// 	t_win	win;
// 	t_plr	plr;

// 	win.mlx = mlx_init();
// 	win.win = mlx_new_window(win.mlx, 500, 500, "lvl_0");
// 	win.img = mlx_new_image(win.mlx, 500, 500);
// 	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length,
// 				&win.endian);
// 	plr.x = -1;
// 	plr.y = -1;
// 	cub.win = &win;
// 	cub.plr = &plr;
// 	return (cub);
// }

int     main(int argc, char **argv)
{
	t_cub	cub;
	t_win	win;
	t_plr	plr;

	//cub = ft_init_cub();
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 500, 500, "lvl_0");
	win.img = mlx_new_image(win.mlx, 500, 500);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length,
				&win.endian);
	plr.x = -1;
	plr.y = -1;
	cub.win = &win;
	cub.plr = &plr;
	parse_map(argc, argv, &cub);
	ft_print_map(&cub);
	mlx_hook(cub.win->win, 2, 1L<<0, ft_close, &cub);
//	mlx_put_image_to_window(cub.win->mlx, cub.win->win, cub.win->img, 0, 0);
    mlx_loop(cub.win->mlx);
}    