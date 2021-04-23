/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:28:17 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/23 16:56:25 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_create_list(t_cub *cub, char *line, int *i, t_list *tmp)
{
	tmp->content = ft_strdup(line + *i);
	if (!(tmp->content))
		ft_notify_error("FAIL MALLOC WRITE LINE IN LIST", cub);
	tmp->next = 0;
	ft_lstadd_back(&cub->tmap, tmp);
}

void	ft_read_line(t_cub *cub, char *line, int *i, int *flag_map)
{
	t_list	*buff;

	if (ft_isalpha(line[*i]))
		ft_get_param(cub, line, *i, flag_map);
	else if (ft_isdigit(line[*i]))
	{
		(*flag_map)++;
		*i = 0;
		buff = malloc(sizeof(t_list));
		if (!buff)
			ft_notify_error("FAIL MALLOC WRITE LINE IN LIST", cub);
		ft_create_list(cub, line, i, buff);
	}
	// else if (line[])
	// {

	// }
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
	ft_check_format(cub, cub->param.no);
	ft_check_format(cub, cub->param.so);
	ft_check_format(cub, cub->param.we);
	ft_check_format(cub, cub->param.ea);
	ft_check_format(cub, cub->param.spr);
}

void	ft_create_map(t_cub *cub)
{
	int		i;
	t_list	*buff;

	cub->map = (char **)malloc(sizeof(char *) * ft_lstsize(cub->tmap) + 1);
	if (!(cub->map))
		ft_notify_error("MALLOC FAIL IN CREATE MAP", cub);
	i = 0;
	buff = cub->tmap;
	while (buff)
	{
		cub->map[i] = ft_strdup(buff->content);
		if (!(cub->map[i]))
			ft_notify_error("MALLOC FAIL IN CREATE MAP", cub);
		buff = buff->next;
		i++;
	}
	cub->map[i] = 0;
	cub->map_h = i;
}

void	ft_open_file(t_cub *cub, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_notify_error("FAILED TO OPEN THE FILE", cub);
	ft_read_file(cub, fd);
	close(fd);
	ft_create_map(cub);
}
