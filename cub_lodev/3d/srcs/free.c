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

void	ft_free_img(t_cub *cub)
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
