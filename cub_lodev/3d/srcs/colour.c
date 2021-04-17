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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

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

void	ft_check_coloure(char **buff, t_cub *cub)
{
	int	i;

	i = -1;
	if (ft_size_buff(buff) == 3)
	{
		while (++i < 3)
			ft_check_buff(buff[i], cub);
		cub->col.r = ft_atoi(buff[0]);
		cub->col.g = ft_atoi(buff[1]);
		cub->col.b = ft_atoi(buff[2]);
	}
	else
	{
		ft_del_buff((void **)buff);
		ft_notify_error("fail in coloure", cub);
	}
    //if (!cub->col.r || !cub->col.g || !cub->col.b)
	//	ft_notify_error("fail malloc in coloure", cub);
	if (cub->col.r > 255 || cub->col.r < 0 || cub->col.g > 255
		|| cub->col.g < 0 || cub->col.b > 255 || cub->col.b < 0)
		ft_notify_error("fail in coloure", cub);
}

void	ft_get_coloure(t_cub *cub, char *s, char c)
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
	ft_check_coloure(buff, cub);
	ft_del_buff((void **)buff);
	if (c == 'F')
		cub->col.f = create_trgb(0, cub->col.r, cub->col.g, cub->col.b);
	else
		cub->col.c = create_trgb(0, cub->col.r, cub->col.g, cub->col.b);
}
