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

int	ft_check_coloure(char **buff, t_cub *cub)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = -1;
	if (ft_size_buff(buff) == 3)
	{
		while (++i < 3)
			ft_check_buff(buff[i], cub);
		r = ft_atoi(buff[2]);
		g = ft_atoi(buff[1]);
		b = ft_atoi(buff[0]);
	}
	else
	{
		ft_del_buff((void **)buff);
		ft_notify_error("fail in coloure", cub);
		return (0);
	}
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		ft_notify_error("fail in coloure", cub);
	return (1);
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
	if (!ft_check_coloure(buff, cub))
		ft_notify_error("fail in coloure", cub);
	col->rgb.r = ft_atoi(buff[2]);
	col->rgb.g = ft_atoi(buff[1]);
	col->rgb.b = ft_atoi(buff[0]);
	col->rgb.a = 0x00;
	ft_del_buff((void **)buff);
}
