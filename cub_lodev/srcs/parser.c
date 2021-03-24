/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:28:17 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/24 07:04:58 by pantigon         ###   ########.fr       */
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

void	ft_read_line(t_cub *cub, char *line, int *i, int *flag_map)
{
	if (ft_isalpha(line[*i]))
		ft_get_param(cub, line, *i, flag_map);
	else if (ft_isdigit(line[*i]))
	{
		(*flag_map)++;
		*i = 0; //возможен лик, можно ли так создать список?
		if (!(ft_lstadd_back(&cub->tmap, ft_lstnew(line))))
			ft_notify_error("FAIL MALLOC WRITE LINE IN LIST", cub);
	}
}

void	ft_read_file(t_cub *cub, int fd)
{
	int		byte;
	char	*line;
	int		flag_map;
	int		i;

	flag_map = 0;
	byte = 1;
	while (byte != 0)
	{
		byte = get_next_line(fd, &line);
		i = 0;
		while ((line[i] == ' ' || line[i] == '\t') && line[i])
			i++;
		ft_read_line(cub, line, &i, &flag_map);
		// (info->error = stock_data(line, info, &i, &flag_map)) != SUCCESS)
		free(line);
	}
	ft_putendl_fd(cub->param.r, 1);
	ft_putendl_fd(cub->param.n, 1);
	ft_putendl_fd(cub->param.s, 1);
	ft_putendl_fd(cub->param.w, 1);
	ft_putendl_fd(cub->param.e, 1);
	ft_putendl_fd(cub->param.sp, 1);
	ft_putendl_fd(cub->param.f, 1);
	ft_putendl_fd(cub->param.c, 1);
	ft_putendl_fd(cub->tmap->content, 1); //говно
	// if ((info->error = check_data(info)) != SUCCESS)
	// 	return (info->error);
	// if ((info->error = path_fix(info)) != SUCCESS)
	// 	return (info->error);
	// return (SUCCESS);
}

void	ft_open_file(t_cub *cub, char *file)
{
	int		fd;
	t_list	map;
	int		i;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_notify_error("FAILED TO OPEN THE FILE", cub);
	ft_read_file(cub, fd);
	close(fd);
}

void	ft_parse_file(t_cub *cub, char *file)
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
