/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:13:47 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/07 15:02:37 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int     main(void)
{
    void    *mlx;
    void    *mlx_win;
	int 	x;
	int		y;

	y = 100;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	while (y++ < 200)
	{
		x = 100;
		while (x++ < 200)
			mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFF);
	}
    mlx_loop(mlx);
}    