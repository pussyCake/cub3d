/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:28:17 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/20 19:04:51 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	is_valid_data(const char *s, char c, int n, char *err)
// {
// 	int i;
// 	int j;
// 	int spl;

// 	i = -1;
// 	while (s && s[++i])
// 		((s[i] < '0' || s[i] > '9') && s[i] != c)
// 		? exit_notify(err, 22) : 0;
// 	i = -1;
// 	j = 0;
// 	spl = 0;
// 	while (s[++i] != '\0')
// 	{
// 		if (s[i] && s[i] != c)
// 		{
// 			while (s[i] && s[i] != c)
// 				i++;
// 			i--;
// 			j++;
// 		}
// 		spl += (s[i] == c && c == ',' ? 1 : 0);
// 	}
// 	if (j != n || (c == ',' && spl != 2))
// 		exit_notify(err, 22);
// }

void		ft_parse_fc(char *s, char c, t_cub *cub)
{
	int		r;
	int		g;
	int		b;
	char	*tmp;

	tmp = s;
	//is_valid_data(s, ',', 3, "no valid clr!");
	r = ft_atoi(s);
	while (*(s - 1) != ',' && *s != '\0')
		s++;
	g = ft_atoi(s);
	while (*s != ',' && *s != '\0')
		s++;
	b = ft_atoi(s + 1);
	//(r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
	//? exit_notify("no valid clr!", 22) : 0;
	if (c == 'F')
		cub->f = create_trgb(0, r, g, b);
	else
		cub->c = create_trgb(0, r, g, b);
	free(tmp);
}

void		ft_get_win_sz(t_cub *cub, char *s)
{
	//is_valid_data(++s, ' ', 2, "No valid screen size");
	cub->win_w = ft_atoi(s);
	while (s && *s == ' ' && *s != '\0')
		s++;
	while (s && *s != ' ' && *s != '\0')
		s++;
	cub->win_h = ft_atoi(s);
	mlx_get_screen_size(cub->win->mlx, &cub->x_mx, &cub->y_mx);
	cub->win_w < 320 ? cub->win_w = 320 : 0;
	cub->win_h < 240 ? cub->win_h = 240 : 0;
	cub->win_w > cub->x_mx ? cub->win_w = cub->x_mx : 0;
	cub->win_h > cub->y_mx ? cub->win_h = --cub->y_mx : 0;
}

void	ft_record_cub(char *line, t_cub *cub)
{
	if (ft_strncmp("R ", line, 2) == 0 && cub->r == -1)
		ft_get_win_sz(line, cub);
	if (ft_strncmp("NO ", line, 3) == 0 && !cub->no)
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
	//if (n == -1)
	//	ft_notify_error();
	ft_check_line(&line, cub);
	//make_map(cub);
	//if (valid_map);
	//if (!cub->plr)
	//	ft_notify_error();
	//if (cub)
}