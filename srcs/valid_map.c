
#include "cub.h"

int	ft_check_close(t_cub *cub, int i, int j)
{
	if (cub->map[i][j] != '1' && cub->map[i][j] != '0'
	&& cub->map[i][j] != '2' && cub->map[i][j] != 'N'
	&& cub->map[i][j] != 'S' && cub->map[i][j] != 'E'
	&& cub->map[i][j] != 'W')
		return (0);
	return (1);
}

int	ft_check_inmap(t_cub *cub, int i, int j)
{
	if (ft_check_close(cub, i, j - 1) == 0)
		ft_notify_error("map fail", cub);
	else if (ft_check_close(cub, i, j + 1) == 0)
		ft_notify_error("map fail", cub);
	else if (ft_check_close(cub, i - 1, j) == 0)
		ft_notify_error("map fail", cub);
	else if (ft_check_close(cub, i + 1, j) == 0)
		ft_notify_error("map fail", cub);
	else if (ft_check_close(cub, i + 1, j - 1) == 0)
		ft_notify_error("map fail", cub);
	else if (ft_check_close(cub, i + 1, j + 1) == 0)
		ft_notify_error("map fail", cub);
	else if (ft_check_close(cub, i - 1, j - 1) == 0)
		ft_notify_error("map fail", cub);
	else if (ft_check_close(cub, i - 1, j + 1) == 0)
		ft_notify_error("map fail", cub);
	return (1);
}

void	ft_skip_space(t_cub *cub, int y, int *x)
{
	while (cub->map[y][*x] != '1'
		&& cub->map[y][*x])
	{
		if (cub->map[y][*x] != ' ')
			ft_notify_error("map fail", cub);
		(*x)++;
	}
}

void	ft_parse(t_cub *cub, int y, int *x)
{
	if (x == 0)
		ft_skip_space(cub, y, x);
	if ((y == 0) || (y == cub->map_h - 1))
		if (cub->map[y][*x] != '1' && cub->map[y][*x] != ' ')
			ft_notify_error("fail map", cub);
	if ((ft_strchr("02NSEW", cub->map[y][*x])) && y != 0
		&& y != cub->map_h && *x != 0)
		ft_check_inmap(cub, y, *x);
}

void	ft_valid_map(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->map_h)
	{
		x = 0;
		while (cub->map[y][x])
		{
			ft_parse(cub, y, &x);
			x++;
		}
		y++;
	}
}
