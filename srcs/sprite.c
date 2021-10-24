
#include "cub.h"

void	ft_sort_sprt(t_cub *cub)
{
	int		i;
	int		buff;
	double	temp;

	i = 0;
	while (i < cub->num_sprite - 1)
	{
		if (cub->sprt.spr_dist[i] < cub->sprt.spr_dist[i + 1])
		{
			temp = cub->sprt.spr_dist[i + 1];
			cub->sprt.spr_dist[i + 1] = cub->sprt.spr_dist[i];
			cub->sprt.spr_dist[i] = temp;
			buff = cub->sprt.spr_ord[i + 1];
			cub->sprt.spr_ord[i + 1] = cub->sprt.spr_ord[i];
			cub->sprt.spr_ord[i] = buff;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_chain_sprt(t_cub *cub)
{
	int		i;

	i = 0;
	while (i < cub->num_sprite)
	{
		cub->sprt.spr_ord[i] = i;
		cub->sprt.spr_dist[i] = ((cub->plr.x - cub->sprt_plc[i].x)
				* (cub->plr.x - cub->sprt_plc[i].x)
				+ (cub->plr.y - cub->sprt_plc[i].y)
				* (cub->plr.y - cub->sprt_plc[i].y));
		i++;
	}
	ft_sort_sprt(cub);
	ft_spr_crt(cub);
}

void	ft_point_sprt(t_cub *cub)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '2')
			{
				cub->sprt_plc[i].x = x + 0.5;
				cub->sprt_plc[i].y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	ft_make_spr(t_cub *cub)
{
	cub->sprt_plc = malloc(sizeof(t_plr) * cub->num_sprite);
	if (!(cub->sprt_plc))
		ft_notify_error("fail sprite", cub);
	cub->sprt.spr_ord = malloc(sizeof(int) * cub->num_sprite);
	if (!(cub->sprt.spr_ord))
		ft_notify_error("fail sprite", cub);
	cub->sprt.spr_dist = malloc(sizeof(double) * cub->num_sprite);
	if (!(cub->sprt.spr_dist))
		ft_notify_error("fail sprite", cub);
	ft_point_sprt(cub);
	ft_chain_sprt(cub);
	if (cub->sprt_plc)
		free(cub->sprt_plc);
	if (cub->sprt.spr_ord)
		free(cub->sprt.spr_ord);
	if (cub->sprt.spr_dist)
		free(cub->sprt.spr_dist);
}
