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
		col->rgb.r = ft_atoi(buff[2]);
		col->rgb.g = ft_atoi(buff[1]);
		col->rgb.b = ft_atoi(buff[0]);
		col->rgb.a = 0x00;
	}
	else
	{
		ft_del_buff((void **)buff);
		ft_notify_error("fail in coloure", cub);
	}
	if (col->rgb.r > 255 || col->rgb.r < 0 || col->rgb.g > 255
		|| col->rgb.g < 0 || col->rgb.b > 255 || col->rgb.g < 0)
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
