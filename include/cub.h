/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:40:30 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/10 17:40:54 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "mlx.h"
#include "get_next_line.h"

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
	int			x;
	int			y;
}				t_plr;

typedef struct s_cub
{
	t_win		*win;
	t_plr		*plr;
	char		**map;
}				t_cub;


void	parse_map(int argc, char **argv, t_cub *cub);
void	make_map(t_list **head, int size, t_cub *cub);

#endif
