/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:28:17 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/22 14:24:19 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_parse_fc(char *s, char c, t_cub *cub)
{
	int		r;
	int		g;
	int		b;
	char	*tmp;

	tmp = s;
	if (!ft_check_valid(++s, ',', "0123456789,", 3, 2))
		ft_notify_error("no valid color!!!");
	r = ft_atoi(s);
	while (*(s - 1) != ',' && *s != '\0')
		s++;
	g = ft_atoi(s);
	while (*s != ',' && *s != '\0')
		s++;
	b = ft_atoi(s + 1);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		ft_notify_error("no valid color!");
	if (c == 'F')
		cub->f = create_trgb(0, r, g, b);
	else
		cub->c = create_trgb(0, r, g, b);
	free(tmp);
}

void		ft_get_win_sz(t_cub *cub, char *s)
{
	if (!ft_check_valid(s, ' ', "0123456789 ", 2, 1))
		ft_notify_error("no valid screen size!!!");
	if (!(cub->win_w = ft_atoi(s)))
		ft_notify_error("no work atoi in get screen size!!!");
	while (s && *s != ' ' && *s != '\0')
		s++;
	while (s && *s == ' ' && *s != '\0')
		s++;
	if (!(cub->win_h = ft_atoi(s)))
		ft_notify_error("no work atoi in get screen size!!!");
	mlx_get_screen_size(&cub->w_max, &cub->h_max);
	if (cub->win_w < 320)
		cub->win_w = 320;
	if (cub->win_h < 240)
		cub->win_h = 240;
	if (cub->win_w > cub->w_max)
		cub->win_w = cub->w_max;
	if (cub->win_h > cub->h_max) 
		cub->win_h = cub->h_max; //мб на один меньше?
}

void	ft_record_cub(char *line, t_cub *cub)
{
	//char	*tmp;
	//int		check;

	//tmp = line;
	//check = 1;
	if (ft_strncmp("R ", line, 2) == 0 && cub->win_h == -1)
		ft_get_win_sz(cub, ft_strtrim(line + 1, " "));
	else if (ft_strncmp("NO ", line, 3) == 0 && !cub->no)
		cub->no = ft_strtrim(line + 2, " ");
	else if (ft_strncmp("SO ", line, 3) == 0 && !cub->so)
		cub->so = ft_strtrim(line + 2, " ");
	else if (ft_strncmp("WE ", line, 3) == 0 && !cub->we)
		cub->we = ft_strtrim(line + 2, " ");
	else if (ft_strncmp("EA ", line, 3) == 0 && !cub->ea)
		cub->ea = ft_strtrim(line + 2, " ");
	else if (ft_strncmp("S ", line, 2) == 0 && !cub->s)
		cub->s = ft_strtrim(line + 1, " ");
	else if ((*line == 'F' && cub->f == -1) || (*line == 'C' && cub->c == -1))
		ft_parse_fc(ft_strtrim(line + 1, " "), *line, cub);
	else
		ft_lstadd_back(&cub->tmap, ft_lstnew(line));
	//free(line);
}

void	ft_check_line(char **line, t_cub *cub)
{
	if (*line != '\0' || (*line == '\0' && cub->tmap))
		ft_record_cub(*line, cub);                // нужно ли чистить лайн?
	if (*line == '\0')
		free(line);
}

void	parse_cub(char *argv, t_cub *cub)
{
	int		fd;
	int		n;
	char	*line;
	
	ft_init_cub(cub);
	fd = open(argv, O_RDONLY);
	while ((n = get_next_line(fd, &line)) > 0)
		ft_check_line(&line, cub);
	if (n == -1)
		ft_notify_error("crash read file\n");
	ft_check_line(&line, cub);
	make_map(cub);
	if (cub->plr->check != 1)
		ft_notify_error("must be 1 player in map!!!");
	if (cub->win_h == -1)
		ft_notify_error("no R in config!!!");
	//	ft_notify_error();
	//if (cub)
}