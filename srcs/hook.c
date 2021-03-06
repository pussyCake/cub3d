
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
		ft_exit(cub);
	return (0);
}

int	ft_loop_game(t_cub *cub)
{
	ft_del_img(cub);
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
	cub->win = mlx_new_window(cub->mlx, cub->win_w, cub->win_h, "GAME");
	if (!cub->win)
		ft_notify_error("fail mlx (create win)", cub);
	mlx_hook(cub->win, 2, 1L << 1, key_press, cub);
	mlx_hook(cub->win, 3, 0, key_unpress, cub);
	mlx_hook(cub->win, 17, 1L << 0, ft_exit, cub);
	if (mlx_loop_hook(cub->mlx, ft_loop_game, cub) != 0)
		ft_notify_error("loop_hook fail", cub);
	mlx_loop(cub->mlx);
}
