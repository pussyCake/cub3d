/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:05:25 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/21 20:33:48 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void            my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(int *)dst = color;
}

void	ft_pp_big(t_win *img, int x, int y, int col)
{
	int x_start;
	int y_start;
	int scale;
	
	scale = 5;
	x_start = x;
	y_start = y;
	while ((y++ < y_start + scale))
	{
		x = x_start;
		while (x++ < x_start + scale )
			my_mlx_pixel_put(img, x, y, col);
	}
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

void	ft_print_column(t_cub *cub, float len, int x, int col)
{
	int i;
	int h;
	int d;
	int h_start;

	i = 0;
	d = (cub->win_w / 2)  / tan(M_PI / 6);
	// h = (SCALE * d) / (int)len;
	h = (float)((SCALE * d) / len);
	if (h > cub->win_h)
		h = cub->win_h;
	h_start = cub->win_h / 2 - h / 2;
	while (h_start + i < h_start + h)
	{
	 	my_mlx_pixel_put(cub->win, x, h_start + i++, col);
	}
	//mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
}

// float		ft_check_vert_wall(t_cub *cub, t_plr *p)
// {
// 	float		step_y;
// 	float		step_x;
// 	t_plr	new_p;
	
// 	new_p = *p;
// 	if (cos(new_p.dir) < 0)
// 	{
// 		new_p.x = (int)(new_p.x / SCALE) * SCALE + SCALE;
// 		step_x = SCALE;
// 	}
// 	else
// 	{
// 		new_p.x = (int)(new_p.x / SCALE) * SCALE - 1;
// 		step_x = -1 * SCALE;
// 	}
// 	new_p.y = cub->plr->y + (tan(new_p.dir) * (new_p.x - cub->plr->x));
// 	step_y = tan(new_p.dir) * step_x * -1;
// 	while ((int)(new_p.y / SCALE) >= 0
// 	&& (int)(new_p.y / SCALE) < 18
// 	&& ((int)(new_p.x / SCALE)) < ft_strlen(cub->map[(int)(new_p.y / SCALE)])
// 	&& ((int)(new_p.x / SCALE)) >= 0
// 	&& cub->map[(int)(new_p.y / SCALE)][(int)(new_p.x / SCALE)] != '1')
// 	{
// 		new_p.y = new_p.y + step_y;
// 		new_p.x = new_p.x + step_x;
// 		//ft_pp_big(cub->win, new_p.x, new_p.y, 0xFF0000);
// 	}
// 	//ft_pp_big(cub->win, new_p.x, new_p.y, 0xFF0000);
// 	return ((sqrt(pow((new_p.x - cub->plr->x), 2) + pow((new_p.y - cub->plr->y), 2))));
// }

// float		ft_check_vert_wall(t_cub *cub, t_plr *p)
// {
// 	float		step_y;
// 	float		step_x;
// 	t_plr	new_p;
	
// 	new_p = *p;
// 	if (cos(new_p.dir) > 0)
// 		new_p.x = (int)(new_p.x / SCALE) * SCALE - 1;
// 	else
// 		new_p.x = (int)(new_p.x / SCALE) * SCALE + SCALE;
// 	new_p.y = cub->plr->y - (tan(new_p.dir) * (new_p.x - cub->plr->x));
// 	step_x = SCALE;
// 	if (cos(new_p.dir) > 0)
// 		step_x *= -1;
// 	step_y = -1 * tan(new_p.dir) * step_x;
// 	while ((int)(new_p.y / SCALE) >= 0
// 	&& (int)(new_p.y / SCALE) < 18
// 	&& ((int)(new_p.x / SCALE)) < ft_strlen(cub->map[(int)(new_p.y / SCALE)])
// 	&& ((int)(new_p.x / SCALE)) >= 0
// 	&& cub->map[(int)(new_p.y / SCALE)][(int)(new_p.x / SCALE)] != '1')
// 	{
// 		new_p.y = new_p.y + step_y;
// 		new_p.x = new_p.x + step_x;
// 	}
// 	return ((sqrt(pow((new_p.x - cub->plr->x), 2) + pow((new_p.y - cub->plr->y), 2))));
// }

// // float		ft_check_vert_wall(t_cub *cub, t_plr *p)
// // {
// // 	float		step_y;
// // 	float		step_x;
// // 	t_plr	new_p;
	
// // 	new_p = *p;
// // 	if (cos(new_p.dir) > 0)
// // 	{
// // 		new_p.x = (int)(cub->plr->x / SCALE) * SCALE;
// // 		step_x = SCALE;
// // 	}
// // 	else
// // 	{
// // 		new_p.x = (int)(cub->plr->x / SCALE) * SCALE;
// // 		step_x = -1 * SCALE;
// // 	}
// // 	step_y = SCALE * tan(new_p.dir);
// // 	if (sin(new_p.dir) < 0)
// // 		step_y *= -1;
// // 	//printf("--%f--\n", new_p.dir);
// // 	printf("--%f--\n", tan(new_p.dir));
// // 	new_p.y = (cub->plr->y + ((cub->plr->x - new_p.x) * tan(new_p.dir)));
// // 	while ((int)(new_p.y / SCALE) >= 0
// // 	&& (int)(new_p.y / SCALE) < 18
// // 	&& cub->map[(int)(new_p.y / SCALE)][(int)(new_p.x / SCALE)] != '1')
// // 	{
// // 		my_mlx_pixel_put(cub->win, new_p.x, new_p.y, 0xFF0000);
// // 		new_p.y = new_p.y + step_y;
// // 		new_p.x = new_p.x + step_x;
// // 	}
// // 	return ((sqrt(pow((new_p.x - cub->plr->x), 2) + pow((new_p.y - cub->plr->y), 2))));
// // }

// float		ft_check_hor_wall(t_cub *cub, t_plr *p)
// {
// 	float		step_y;
// 	float		step_x;
// 	t_plr	new_p;
	
// 	new_p = *p;
// 	if (new_p.dir >= M_PI && new_p.dir <= M_PI * 2)
// 	{
// 		new_p.y = (int)(cub->plr->y / SCALE) * SCALE - 1;
// 		step_y = -1 * SCALE;
// 		step_x = (SCALE / tan(new_p.dir));
// 	}
// 	else
// 	{
// 		new_p.y = (int)(cub->plr->y / SCALE) * SCALE + SCALE;
// 		step_y = SCALE;
// 		step_x = -1 * (SCALE / tan(new_p.dir));
// 	}
// 	new_p.x = (cub->plr->x + ((cub->plr->y - new_p.y) / tan(new_p.dir)));
// 	//printf("x:%f--y:%f\n", new_p.x, new_p.y);
// 	while ((int)(new_p.y / SCALE) >= 0
// 	&& (int)(new_p.y / SCALE) < 18
// 	&& ((int)(new_p.x / SCALE)) < ft_strlen(cub->map[(int)(new_p.y / SCALE)])
// 	&& ((int)(new_p.x / SCALE)) >= 0
// 	&& cub->map[(int)(new_p.y / SCALE)][(int)(new_p.x / SCALE)] != '1')
// 	{
// 		new_p.y = new_p.y + step_y;
// 		new_p.x = new_p.x + step_x;
// 		//printf("x:%f--y:%f\n", new_p.x, new_p.y);
// 		//ft_pp_big(cub->win, new_p.x, new_p.y, 0x00FF00);
// 		//my_mlx_pixel_put(cub->win, new_p.x, new_p.y, 0x00FF00);
// 	}
// 	//printf("\n");
// 	//ft_pp_big(cub->win, new_p.x, new_p.y, 0x00FF00);
// 	return ((sqrt(pow((new_p.x - cub->plr->x), 2) + pow((new_p.y - cub->plr->y), 2))));
// }

// float		ft_check_wall(t_cub *cub, float ray)
// {
// 	float		len_hor;
// 	float		len_vert;
// 	t_plr		new_p;

// 	new_p.dir = ray;
// 	new_p.x = cub->plr->x;
// 	new_p.y = cub->plr->y;
// 	len_hor = -1;
// 	len_vert = -1;
// 	if (fabs(cos(ray)) > 0.001f)
// 		len_vert = (ft_check_vert_wall(cub, &new_p));
// 	if (fabs(sin(ray)) > 0.001f)
// 		len_hor = (ft_check_hor_wall(cub, &new_p));
// 	if (len_vert < 0)
// 		return (len_hor);
// 	else if (len_hor < 0)
// 		return (len_vert);
// 	else if (len_hor < len_vert)
// 		return (len_hor);
// 	return (len_vert);
//  }

float		ft_check_vert_wall(t_cub *cub, t_plr *p)
{
	float		step_y;
	float		step_x;
	t_plr	new_p;
	
	new_p = *p;
	if (cos(new_p.dir) > 0)
		new_p.x = (int)(new_p.x / SCALE) * SCALE - 1;
	else
		new_p.x = (int)(new_p.x / SCALE) * SCALE + SCALE;
	new_p.y = cub->plr->y - (tan(new_p.dir) * (new_p.x - cub->plr->x));
	step_x = SCALE;
	if (cos(new_p.dir) > 0)
		step_x *= -1;
	step_y = -1 * tan(new_p.dir) * step_x;
	while ((int)(new_p.y / SCALE) >= 0
	&& (int)(new_p.y / SCALE) < cub->map_h
	&& ((int)(new_p.x / SCALE)) < ft_strlen(cub->map[(int)(new_p.y / SCALE)])
	&& ((int)(new_p.x / SCALE)) >= 0
	&& cub->map[(int)(new_p.y / SCALE)][(int)(new_p.x / SCALE)] != '1')
	{
		new_p.y = new_p.y + step_y;
		new_p.x = new_p.x + step_x;
		ft_pp_big(cub->win, new_p.x, new_p.y, 0xFF0000);
	}
	//ft_pp_big(cub->win, new_p.x, new_p.y, 0xFF0000);
	return ((sqrt(pow((new_p.x - cub->plr->x), 2) + pow((new_p.y - cub->plr->y), 2))));
}

// float		ft_check_vert_wall(t_cub *cub, t_plr *p)
// {
// 	float		step_y;
// 	float		step_x;
// 	t_plr	new_p;
	
// 	new_p = *p;
// 	if (cos(new_p.dir) > 0)
// 	{
// 		new_p.x = (int)(cub->plr->x / SCALE) * SCALE;
// 		step_x = SCALE;
// 	}
// 	else
// 	{
// 		new_p.x = (int)(cub->plr->x / SCALE) * SCALE;
// 		step_x = -1 * SCALE;
// 	}
// 	step_y = SCALE * tan(new_p.dir);
// 	if (sin(new_p.dir) < 0)
// 		step_y *= -1;
// 	//printf("--%f--\n", new_p.dir);
// 	printf("--%f--\n", tan(new_p.dir));
// 	new_p.y = (cub->plr->y + ((cub->plr->x - new_p.x) * tan(new_p.dir)));
// 	while ((int)(new_p.y / SCALE) >= 0
// 	&& (int)(new_p.y / SCALE) < 18
// 	&& cub->map[(int)(new_p.y / SCALE)][(int)(new_p.x / SCALE)] != '1')
// 	{
// 		my_mlx_pixel_put(cub->win, new_p.x, new_p.y, 0xFF0000);
// 		new_p.y = new_p.y + step_y;
// 		new_p.x = new_p.x + step_x;
// 	}
// 	return ((sqrt(pow((new_p.x - cub->plr->x), 2) + pow((new_p.y - cub->plr->y), 2))));
// }

float		ft_check_hor_wall(t_cub *cub, t_plr *p)
{
	float		step_y;
	float		step_x;
	t_plr	new_p;
	
	new_p = *p;
	if (new_p.dir >= M_PI && new_p.dir <= M_PI * 2)
	{
		new_p.y = (int)(cub->plr->y / SCALE) * SCALE - 1;
		step_y = -1 * SCALE;
		step_x = (SCALE / tan(new_p.dir));
	}
	else
	{
		new_p.y = (int)(cub->plr->y / SCALE) * SCALE + SCALE;
		step_y = SCALE;
		step_x = -1 * (SCALE / tan(new_p.dir));
	}
	new_p.x = (cub->plr->x + ((cub->plr->y - new_p.y) / tan(new_p.dir)));
	//printf("x:%f--y:%f\n", new_p.x, new_p.y);
	while ((int)(new_p.y / SCALE) >= 0
	&& (int)(new_p.y / SCALE) < cub->map_h
	&& ((int)(new_p.x / SCALE)) < ft_strlen(cub->map[(int)(new_p.y / SCALE)])
	&& ((int)(new_p.x / SCALE)) >= 0
	&& cub->map[(int)(new_p.y / SCALE)][(int)(new_p.x / SCALE)] != '1')
	{
		new_p.y = new_p.y + step_y;
		new_p.x = new_p.x + step_x;
		//printf("x:%f--y:%f\n", new_p.x, new_p.y);
		ft_pp_big(cub->win, new_p.x, new_p.y, 0x00FF00);
		//my_mlx_pixel_put(cub->win, new_p.x, new_p.y, 0x00FF00);
	}
	return ((sqrt(pow((new_p.x - cub->plr->x), 2) + pow((new_p.y - cub->plr->y), 2))));
}

float		ft_check_wall(t_cub *cub, float ray)
{
	float		len_hor;
	float		len_vert;
	t_plr		new_p;

	new_p.dir = ray;
	new_p.x = cub->plr->x;
	new_p.y = cub->plr->y;
	len_hor = -1;
	len_vert = -1;
	if (fabs(cos(ray)) > 0.001f)
		len_vert = (ft_check_vert_wall(cub, &new_p));
	if (fabs(sin(ray)) > 0.001f)
		len_hor = (ft_check_hor_wall(cub, &new_p));
	if (len_vert < 0)
		return (len_hor);
	else if (len_hor < 0)
		return (len_vert);
	else if (len_hor < len_vert)
		return (len_hor);
	return (len_vert);
 }

void	ft_cast_ray(t_cub *cub, int col)
{
	float		start;
	float		end;
	float		len;
	int		i;
	t_plr	ray; 

	ray = *cub->plr; 
	i = 0;
	start = ray.dir - M_PI / 6;
	end = ray.dir + M_PI / 6;
	while (start < end)
	{
		// ray.x = cub->plr->x;
		// ray.y = cub->plr->y;
		// while (cub->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		// {
		// 	ray.x += cos(start);
		// 	ray.y += sin(start);
		// 	//my_mlx_pixel_put(cub->win, ray.x, ray.y, col);
		// 	// mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
		// }
		// len = sqrt(pow((ray.x - cub->plr->x), 2) + pow((ray.y - cub->plr->y), 2));
		//len = sqrt(pow((cub->plr->x - ray.x), 2) + pow((cub->plr->y - ray.y), 2));
		//len = fabsf(((ray.x - cub->plr->x) / cos(start)));
		len = ft_check_wall(cub, start);
		//printf("%f-\n", len);
		//len = len * cos(ray.dir - start);
		//ft_print_column(cub, len, i++, col);
		start += (M_PI / 3) / cub->win_w;
		mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
		//mlx_do_sync(cub->win->mlx);
	}
}

void	ft_print_black_map(t_cub *cub, int col)
{
	int i;
	int x;
	int y;
	int j;

	j = 0;
	x = cub->win_w;
	y = cub->win_h;
	while (j < y)
	{
		i = 0;
		while (i < x)
			my_mlx_pixel_put(cub->win, i++, j, col);
		j++;
	}
	//ft_cast_ray(cub, col_plr);
	//ft_p_big(cub->win, cub->plr->x, cub->plr->y, col_plr);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
	//mlx_do_sync(cub->win->mlx);
}

void	ft_print_map(t_cub *cub, int col, int col_plr)
{
	int i;
	int j;

	j = 0;
	while (cub->map[j])
	{
		i = 0;
		while (cub->map[j][i])
		{
			my_mlx_pixel_put(cub->win, i * SCALE, j * SCALE, 0xFFFFFF);
			if (cub->map[j][i] == '1')
				ft_p_big(cub->win, i, j, col);
			i++;
		}
		j++;
	}
	ft_cast_ray(cub, col_plr);
	//ft_p_big(cub->win, cub->plr->x / SCALE, cub->plr->y / SCALE, col_plr);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->win->img, 0, 0);
}

int		ft_exit(t_win *win)
{
    exit(0);
	return (0);
}

int		ft_close(t_cub *cub)
{
	mlx_clear_window(cub->win->mlx, cub->win->win);
	//mlx_destroy_image(cub->win->mlx, cub->win->img);
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

int     main(int argc, char **argv)
{
	t_cub	cub;
	t_win	win;
	t_plr	plr;

	cub.plr = &plr;
	cub.win = &win;
	parse_cub(argv[1], &cub);
	cub.win->mlx = mlx_init();
	cub.win->win = mlx_new_window(cub.win->mlx, cub.win_w, cub.win_h, "lvl_0");
	cub.win->img = mlx_new_image(cub.win->mlx, cub.win_w, cub.win_h);
	cub.win->addr = mlx_get_data_addr(cub.win->img, &cub.win->bits_per_pixel,
	&cub.win->line_length, &cub.win->endian);

	ft_cast_ray(&cub, 0x808080);
	// //mlx_put_image_to_window(cub.win->mlx, cub.win->win, cub.win->img, 0, 0);
	
	//mlx_hook(cub.win->win, 2, 1L<<0, ft_close, &cub);
	mlx_hook(cub.win->win, 2, 1L << 1, key_press, &cub);
	mlx_hook(cub.win->win, 3, 0, key_unpress, &cub);
	mlx_hook(cub.win->win, 17, 1L<<0, ft_exit, &cub);
	mlx_loop_hook(cub.win->mlx, ft_close, &cub);
	mlx_loop(cub.win->mlx);
	//printf("%d\n", cub.map[(int)(cub.plr->y / SCALE) - 1][(int)(cub.plr->x / SCALE) - 1]);
	return (0);
}    