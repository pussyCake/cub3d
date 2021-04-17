/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:04 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/15 13:56:04 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_del_img(t_cub *cub)
{
	if (cub->img)
	{
		mlx_destroy_image(cub->mlx, cub->img->img);
		free(cub->img);
		cub->img = NULL;
	}
}

void	ft_del_buff(void **buff)
{
	int	i;

	i = 0;
	if (buff)
	{
		while (buff[i])
			free(buff[i++]);
		free(buff);
	}
}

void	ft_del_text(t_cub *cub, t_img *text)
{
	if (text)
	{
		mlx_destroy_image(cub->mlx, text->img);
		free(text);
		text = NULL;
	}
}

void	ft_del_data(t_cub *cub)
{
	if (cub->rc.zbuff)
		free(cub->rc.zbuff);
	if (cub->map)
		ft_del_buff((void *)cub->map);
	if (cub->param.r)
		free(cub->param.r);
	if (cub->param.no)
		free(cub->param.no);
	if (cub->param.so)
		free(cub->param.so);
	if (cub->param.we)
		free(cub->param.we);
	if (cub->param.ea)
		free(cub->param.ea);
	if (cub->param.f)
		free(cub->param.f);
	if (cub->param.c)
		free(cub->param.c);
	// if (cub->param.sp)
	// 	free(cub->param.sp);
}
