
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
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2
#define KEY_W 13
#define KEY_L 123
#define KEY_R 124
#define KEY_ESC 53

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
	int				check;
}				t_plr;

typedef struct				s_rc
{
	// t_pos					plane;
	// t_pos					step;
	// t_pos					dir;
	// t_pos_i					textur;
	// t_pos					rpos;
	// t_pos					rdir;
	// t_pos					rdisd;
	// t_pos					rdist;
	// t_pos_i					rmap;
	int						wall;
	int						wstart;
	int						wend;
	double					camera;
	int						hit;
	double					rh;
	double					step_textur;
	double					textur_pos;
	double					dist;
	double					speed;
	double					*zbuffer;
	int						*sp_order;
	double					*sp_distance;

}							t_rc;

typedef struct				s_param
{
	char					*r;
	char					*no;
	char					*n;
	char					*so;
	char					*s;
	char					*we;
	char					*w;
	char					*ea;
	char					*e;
	char					*spr;
	char					*sp;
	char					*f;
	char					*c;
}							t_param;

typedef struct s_cub
{
	t_win		*win;
	t_plr		*plr;
	t_list		*tmap;
	t_rc		rc;
	t_param		param;
	int			flag_n;
	int			flag_save;
	int			map_h;
	int			win_w;
	int			win_h;
	int			w_max;
	int			h_max;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f;
	int			c;
	char		**map;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_left;
	int			key_right;
	int			key_esc;
}				t_cub;

void	ft_parse_file(t_cub *cub, char *file);
void	ft_notify_error(char *msg, t_cub *cub);
void	ft_notify_error_param(char *msg, t_cub *cub, char *s);
//void	ft_params(char **str, char *s, char *line, t_cub *cub);
void	ft_init_param(t_cub *cub, char *file);
void	ft_open_file(t_cub *cub, char *file);
void	ft_check_number_param(t_cub *cub);
void	ft_check_path(t_cub *cub);
void	ft_get_param(t_cub *cub, char *line, int i, int *flag_map);
void	ft_check_map(t_cub *cub);
void	ft_valid_map(t_cub *cub);

// int		create_trgb(int t, int r, int g, int b);
// void	parse_cub(char *argv, t_cub *cub);
// void	make_map(t_cub *cub);
// void	ft_init_cub(t_cub *cub);
// int		key_press( int key, t_cub *cub);
// int		key_unpress( int key, t_cub *cub);
// int		ft_key_control(t_cub *cub);
// void	ft_check_all_conf(t_cub *cub);
// void	ft_check_map(char *l_pre, char *l_now, char *l_nxt, int num, int lst);
// int		ft_check_valid(char *s, char c, char *ch, int num_wrd, int num_c);

#endif
