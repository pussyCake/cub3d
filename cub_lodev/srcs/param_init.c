/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:12:13 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/02 13:22:51 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_param(t_cub *cub, char *file)
{
	cub->rc.speed = 0.05;
	
	ft_open_file(cub, file);
	
	// if ((info->error = get_map(info, s)) != SUCCESS)
	// 	return (info->error);

	// if ((info->error = parse_map(info)) != SUCCESS)
	// 	return (info->error);
	// if ((info->error = get_colour(&info->colour_floor,
	// 	info->data.f)) != SUCCESS)
	// 	return (info->error);
	// if ((info->error = get_colour(&info->colour_ceiling,
	// 	info->data.c)) != SUCCESS)
	// 	return (info->error);
	// if ((info->error = get_resolution(info)) != SUCCESS)
	// 	return (info->error);
	// if ((info->error = init_info_pos(info)) != SUCCESS)
	// 	return (info->error);
	// if (!(info->rc.zbuffer = malloc(sizeof(double) * info->width)))
	// 	return (MALLOC_FAIL);
	// if ((info->error = init_texture(info)) != SUCCESS)
	// 	return (info->error);
	// return (SUCCESS);
}