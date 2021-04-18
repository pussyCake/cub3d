/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:57:58 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/15 13:57:58 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_size_buff(char **buff)
{
	int	i;

	i = 0;
	while (buff[i])
		i++;
	return (i);
}

void	ft_ckeck_isdigit(char *buf, t_cub *cub)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(buf);
	while (i < size)
	{
		if (!ft_isdigit(buf[i]) && buf[i] != ' ')
			ft_notify_error("error in resolution", cub);
		i++;
	}
}

void	ft_ckeck_isalpha(char *s, int i, t_cub *cub)
{
	while (s[i])
	{
		if (ft_isalpha(s[i]))
			ft_notify_error("error in resolution", cub);
		i++;
	}
}

void	ft_check_resolution(t_cub *cub, char ***buf)
{
	int	i;

	i = 0;
	while (!ft_isdigit(cub->param.r[i]))
	{
		if (cub->param.r[i] == '-')
			ft_notify_error("error in resolution", cub);
		i++;
	}
	ft_ckeck_isalpha(cub->param.r, i, cub);
	*buf = ft_split(cub->param.r + i, ' ');
	if (!(*buf))
		ft_notify_error("malloc error in resolution", cub);
}

void	ft_get_resolution(t_cub *cub)
{
	char	**buf;
	int		word;

	word = -1;
	ft_check_resolution(cub, &buf);
	if (ft_size_buff(buf) == 2)
	{
		while (++word < 2)
			ft_ckeck_isdigit(buf[word], cub);
		if (buf[0])
			cub->win_w = ft_atoi(buf[0]);
		if (buf[1])
			cub->win_h = ft_atoi(buf[1]);
	}
	else
		ft_notify_error("error in resolution", cub);
	ft_del_buff((void **)buf);
	if (!cub->win_w || !cub->win_h || cub->win_w < 0 || cub->win_h < 0)
		ft_notify_error("error in resolution", cub);
	mlx_get_screen_size(&cub->w_max, &cub->h_max);
	if (cub->win_w > cub->w_max)
		cub->win_w = cub->w_max;
	if (cub->win_h > cub->h_max)
		cub->win_h = cub->h_max;
}
