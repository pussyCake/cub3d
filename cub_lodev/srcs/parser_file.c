/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:28:17 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/24 17:56:17 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
		//ft_putendl_fd(cub->tmap->content, 1);
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
		free(line);
	}
	ft_check_number_param(cub);
	ft_check_path(cub);
	


	// if ((info->error = path_fix(info)) != SUCCESS)
	// 	return (info->error);
	// return (SUCCESS);
	
	// ft_putendl_fd(cub->param.r, 1);
	// ft_putendl_fd(cub->param.n, 1);
	// ft_putendl_fd(cub->param.s, 1);
	// ft_putendl_fd(cub->param.w, 1);
	// ft_putendl_fd(cub->param.e, 1);
	// ft_putendl_fd(cub->param.sp, 1);
	// ft_putendl_fd(cub->param.f, 1);
	// ft_putendl_fd(cub->param.c, 1);
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
