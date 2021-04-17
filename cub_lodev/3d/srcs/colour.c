/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:55:30 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/15 13:55:30 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check_buff(char *buff, t_cub *cub)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(buff);
	while (i < size && buff[i] == ' ')
		i++;
	while (i < size && ft_isdigit(buff[i]))
		i++;
	while (i < size)
	{
		if (ft_isdigit(buff[i]))
			ft_notify_error("fail in coloure", cub);
		i++;
	}
}

void	ft_check_coloure(t_coloure *col, char **buff, t_cub *cub)
{
	int	i;

	i = -1;
	if (ft_size_buff(buff) == 3)
	{
		while (++i < 3)
			ft_check_buff(buff[i], cub);
		col->trgb.r = ft_atoi(buff[2]);
		col->trgb.g = ft_atoi(buff[1]);
		col->trgb.b = ft_atoi(buff[0]);
		col->trgb.t = 0x0;
	}
	else
	{
		ft_del_buff((void **)buff);
		ft_notify_error("fail in coloure", cub);
	}
    //if (!cub->col.r || !cub->col.g || !cub->col.b)
	//	ft_notify_error("fail malloc in coloure", cub);
	if (col->trgb.r > 255 || col->trgb.r < 0 || col->trgb.g > 255
		|| col->trgb.g < 0 || col->trgb.b > 255 || col->trgb.g < 0)
		ft_notify_error("fail in coloure", cub);
}

void	ft_get_coloure(t_coloure *col, char *s, t_cub *cub)
{
	int		i;
	char	**buff;

	i = 0;
	while (!ft_isdigit(s[i]) && s[i] != '-')
		i++;
	ft_ckeck_isalpha(s, i, cub);
	buff = ft_split((s + i), ',');
	if (!(buff))
		ft_notify_error("fail malloc in colour", cub);
	ft_check_coloure(col, buff, cub);
	ft_del_buff((void **)buff);
}
