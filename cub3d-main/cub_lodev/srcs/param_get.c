/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:15:46 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/24 17:16:21 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_params(char **str, char *s, char *line, t_cub *cub)
{
	if (ft_strncmp(s, line, ft_strlen(s)) == 0 && *str == NULL)
	{
		if (!(*str = ft_strdup(line)))
	 		ft_notify_error_param("MALLOC FAIL in PARAM: ", cub, s);
	}
	else
		ft_notify_error_param("FAIL PARAM: ", cub, s);
}

void	ft_get_param(t_cub *cub, char *line, int i, int *flag_map)
{
	if (*flag_map != 0)
		ft_notify_error("MAP MUST BE LAST IN FILE", cub);
	else if (line[i] == 'R')
		ft_params(&cub->param.r, "R ", line + i, cub);
	else if (line[i] == 'N')
		ft_params(&cub->param.n, "NO ", line + i, cub);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		ft_params(&cub->param.s, "SO ", line + i, cub);
	else if (line[i] == 'W')
		ft_params(&cub->param.w, "WE ", line + i, cub);
	else if (line[i] == 'E')
		ft_params(&cub->param.e, "EA ", line + i, cub);
	else if (line[i] == 'S' && line[i + 1] != 'O')
		ft_params(&cub->param.sp, "S ", line + i, cub);
	else if (line[i] == 'F')
		ft_params(&cub->param.f, "F ", line + i, cub);
	else if (line[i] == 'C')
		ft_params(&cub->param.c, "C ", line + i, cub);
	else
		ft_notify_error("INVALID READ PARAMS", cub);
}
