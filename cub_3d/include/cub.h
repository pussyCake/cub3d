
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:40:30 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/18 12:33:39 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include "libft.h"
#include "mlx.h"
#include "get_next_line.h"

#define SCALE 16
#define _USE_MATH_DEFINES 

typedef struct  s_win
{
	void		*mlx;
	void		*win;
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_win;

typedef struct	s_player
{
	float			x;
	float			y;
	float			dir;
}				t_plr;

typedef struct s_cub
{
	t_win		*win;
	t_plr		*plr;
	t_list		*tmap;
	int			r;
	int			win_w;
	int			win_h;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f;
	int			c;
	char		**map;
}				t_cub;

int		create_trgb(int t, int r, int g, int b);
void	parse_cub(char *argv, t_cub *cub);
void	make_map(t_cub *cub);
void	ft_init_cub(t_cub *cub);

#endif
