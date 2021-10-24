
#include "cub.h"

void	ft_check_rgb(char *s, int i, t_cub *cub)
{
	i++;
	while ((ft_isdigit(s[i]) != 1))
	{
		if (s[i] != ' ')
			ft_notify_error("incorrect data in color", cub);
		i++;
	}
}

void	ft_check_fc(char *color, t_cub *cub)
{
	int	i;
	int	num;

	i = 1;
	num = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i])
			&& (color[i] != ' ') && (color[i] != ','))
			ft_notify_error("not valid symbol in color", cub);
		if (ft_isdigit(color[i]))
			num = 1;
		if (color[i] == ',')
		{
			if (num == 0)
				ft_notify_error("incorrect data in color", cub);
			ft_check_rgb(color, i, cub);
		}
		i++;
	}
}

void	ft_check_number_param(t_cub *cub)
{
	int	i;

	if (!cub->param.r || !cub->param.n || !cub->param.s || !cub->param.w
		|| !cub->param.e || !cub->param.sp || !cub->param.f || !cub->param.c
		|| !cub->tmap)
		ft_notify_error("INVALID PARAMS or MAP", cub);
	i = 1;
	while (cub->param.r[i])
		if (ft_isalpha(cub->param.r[i++]))
			ft_notify_error("incorrect data in R", cub);
	ft_check_fc(cub->param.f, cub);
	ft_check_fc(cub->param.c, cub);
}
