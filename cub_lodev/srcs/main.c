/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:05:25 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/18 15:51:12 by pantigon         ###   ########.fr       */
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
	int x_start;
	int y_start;

	y = y * SCALE;
	x = x * SCALE;
	x_start = x;
	y_start = y;
	while ((y++ < y_start + SCALE))
	{
		x = x_start;
		while (x++ < x_start + SCALE)
			my_mlx_pixel_put(img, x, y, col);
	}
}

void	ft_px_big(t_win *img, int x, int y, int col)
{
	int x_start;
	int y_start;

	//y = y * SCALE;
	x = x * SCALE;
	x_start = x;
	y_start = y;
	while ((y++ < y_start + SCALE))
	{
		x = x_start;
		while (x++ < x_start + SCALE)
			my_mlx_pixel_put(img, x, y, col);
	}
}

void	ft_print_column(t_cub *cub, int len, int x, int col)
{
	int i;
	int h;
	int d;
	int h_start;

	i = 0;
	d = 300 / tan(M_PI / 6);
	h = (SCALE * d) / len;
	if (h >= 500)
		h = 499;
	h_start = 250 - h / 2;
	//h_start = roundf(h_start);
	while (h_start + i < h_start + h)
	{
	 	my_mlx_pixel_put(cub->win, x, h_start + i++, col);
	}
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
}

static	int	ft_check_vert_wall(t_cub *cub, t_plr *p)
{
	int		step_y;
	int		step_x;
	t_plr	new_p;
	
	new_p = *p;
	if ((new_p.dir >= 0 && new_p.dir <= M_PI / 2) ||
	(new_p.dir >= (M_PI_2 * 3) && new_p.dir <= M_PI * 2))
	{
		step_x = SCALE;
		new_p.x = (int)((cub->plr->x / SCALE) * SCALE + SCALE);
	}
	else
	{
		step_x = -1 * SCALE;
		new_p.x = (int)((cub->plr->x / SCALE) * SCALE - 1);
	}
	new_p.y = (int)(cub->plr->y + ((cub->plr->x - new_p.x) / tan(new_p.dir)));
	step_y = (int)(SCALE / tan(M_PI / 3));
	while (cub->map[(int)(new_p.y / SCALE)][(int)(new_p.x / SCALE)] != '1')
	{
		new_p.y = new_p.y + step_y;
		new_p.x = new_p.x + step_x;
	}
	return ((int)(sqrt(pow((new_p.x - cub->plr->x), 2) + pow((new_p.y - cub->plr->y), 2))));
}

static	int	ft_check_hor_wall(t_cub *cub, t_plr *p)
{
	int		step_y;
	int		step_x;
	t_plr	new_p;
	
	new_p = *p;
	if (new_p.dir >= M_PI && new_p.dir <= M_PI * 2)
		new_p.y = (int)((cub->plr->y / SCALE) * SCALE - 1);
	else
		new_p.y = (int)((cub->plr->y / SCALE) * SCALE + SCALE);
	new_p.x = (int)(cub->plr->x + ((cub->plr->y - new_p.y) / tan(new_p.dir)));
	if (new_p.dir >= M_PI && new_p.dir <= M_PI * 2)
		step_y = -1 * SCALE;
	else
		step_y = SCALE;
	step_x = (int)(SCALE / tan(M_PI / 3));
	while (cub->map[(int)(new_p.y / SCALE)][(int)(new_p.x / SCALE)] != '1')
	{
		new_p.y = new_p.y + step_y;
		new_p.x = new_p.x + step_x;
	}
	return ((sqrt(pow((new_p.x - cub->plr->x), 2) + pow((new_p.y - cub->plr->y), 2))));
}

int		ft_check_wall(t_cub *cub, int ray)
{
	int		len_hor;
	int		len_vert;
	t_plr	new_p;

	new_p.dir = ray;
	new_p.x = cub->plr->x;
	new_p.y = cub->plr->y;
	len_hor = (int)(ft_check_hor_wall(cub, &new_p));
	len_vert = (int)(ft_check_vert_wall(cub, &new_p));
	if (len_hor < len_vert)
		return (len_hor);
	return (len_vert);
}

void	ft_cast_ray(t_cub *cub, int col)
{
	float	start;
	float	end;
	int		len;
	int		i;
	t_plr	ray = *cub->plr; 

	i = 0;
	start = ray.dir - M_PI / 6;
	end = ray.dir + M_PI / 6;
	while (start < end)
	{
		// ray.x = cub->plr->x;
		// ray.y = cub->plr->y;
		//while (ft_check_wall(cub, start) != '1')
		//while (cub->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		//{
			//ray.x += cos(start);
			//ray.y += sin(start);
			//my_mlx_pixel_put(cub->win, ray.x, ray.y, col);
			//mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
		//}
		//len = sqrt(pow((ray.x - cub->plr->x), 2) + pow((ray.y - cub->plr->y), 2));
		//len = sqrt(pow((cub->plr->x - ray.x), 2) + pow((cub->plr->y - ray.y), 2));
		//len = fabsf(((ray.x - cub->plr->x) / cos(start)));
		len = (int)ft_check_wall(cub, start);
		len = len * cos(ray.dir - start);
		ft_print_column(cub, len, i++, col);
		start += (M_PI / 3) / 600;
		//mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
	}
}

void	ft_print_map(t_cub *cub, int col)
{
	int i;
	int x;
	int y;
	int j;

	j = 0;
	x = 600;
	y = 500;
	while (j < y)
	{
		i = 0;
		while (i < x)
		my_mlx_pixel_put(cub->win, i++, j, col);
			//ft_p_big(cub->win, i++, j, col);
		j++;
	}
	//ft_cast_ray(cub, col_plr);
	//ft_p_big(cub->win, cub->plr->x, cub->plr->y, col_plr);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
}

int		ft_exit(t_win *win)
{
    exit(0);
	return (0);
}

int		ft_close(int key, t_cub *cub)
{
	mlx_clear_window(cub->win->mlx, cub->win->win);
	//mlx_destroy_image(cub->win->mlx, cub->win->img);
	ft_print_map(cub, 0x000000);
	if (key == 13)
	{
		cub->plr->y += sin(cub->plr->dir)* 4;
		cub->plr->x += cos(cub->plr->dir) * 4;
	}
	if (key == 1)
	{
		cub->plr->y -= sin(cub->plr->dir) * 4;
		cub->plr->x -= cos(cub->plr->dir) * 4;
	}
	if (key == 0)
		cub->plr->dir -= 0.05;
	if (key == 2)
		cub->plr->dir += 0.05;
	if (key == 53)
		exit(0);
		//mlx_destroy_window(win->mlx, win->win);
	ft_cast_ray(cub, 0x808080);
	//ft_print_map(cub, 0xFFFFFF, 0x991199);
	return (0);
}

int     main(int argc, char **argv)
{
	t_cub	cub;
	t_win	win;
	t_plr	plr;

	//cub = ft_init_cub();
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 600, 500, "lvl_0");
	win.img = mlx_new_image(win.mlx, 600, 500);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length,
				&win.endian);
	plr.x = -1;
	plr.y = -1;
	plr.dir = M_PI_2;
	cub.win = &win;
	cub.plr = &plr;
	parse_map(argc, argv, &cub);
	ft_cast_ray(&cub, 0x808080);
	//ft_print_map(&cub, 0xFFFFFF, 0x991199);
	//mlx_put_image_to_window(cub.win->mlx, cub.win->win, cub.win->img, 0, 0);
	mlx_hook(cub.win->win, 2, 1L<<0, ft_close, &cub);
	mlx_hook(cub.win->win, 17, 1L<<0, ft_exit, &cub);
    mlx_loop(cub.win->mlx);
}    