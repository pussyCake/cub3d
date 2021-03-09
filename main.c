/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:13:47 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/09 14:50:18 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_p_big(void *mlx, void *win, int x, int y, int col)
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
			mlx_pixel_put(mlx, win, x, y, col);
	}
}

void	ft_print_map(void *mlx, void *win, char **map)
{
	int i;
	int j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				ft_p_big(mlx, win, i, j, 0xFFFFFF);
			//	mlx_pixel_put(mlx, win, i, j, 0xFFFFFF);
			i++;
		}
		j++;
	}
}

int     main(int argc, char **argv)
{
    void    *mlx;
    void    *mlx_win;
	char	**map;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	map = parse_map(argc, argv);
	ft_print_map(mlx, mlx_win, map);
	// while (y++ < 200)
	// {
	// 	x = 100;
	// 	while (x++ < 200)
	// 		mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFF);
	// }
    mlx_loop(mlx);
}    