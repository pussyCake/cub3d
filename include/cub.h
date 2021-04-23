/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:40:30 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/24 01:25:21 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define	CUB_H
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"

# define _USE_MATH_DEFINES 

# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13

# define KEY_UP 126
# define KEY_DW 125
# define KEY_L 123
# define KEY_R 124

# define KEY_ESC 53

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_trgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}				t_rgb;

typedef union u_coloure
{
	unsigned int	all;
	char			tab[4];
	t_rgb			rgb;
}				t_coloure;

typedef struct s_player
{
	char	plr;
	double	x;
	double	y;			
}				t_plr;

typedef struct s_point
{
	int	x;
	int	y;
	int	id;
}				t_point;

typedef struct s_rc
{
	t_plr	plane;
	t_plr	step;
	t_plr	dir;
	t_point	text;
	t_plr	ray;
	t_plr	ray_dir;
	t_plr	del_dist;
	t_plr	side_dist;
	t_point	map;
	int		side;
	int		h_start;
	int		h_end;
	double	cam_x;
	int		hit;
	double	wall_h;
	double	step_text;
	double	text_pos;
	double	wall_dist;
	double	speed;
	double	*zbuff;

}				t_rc;

typedef struct s_sprite
{
	double	sp_dist;
	double	cam_x;
	double	cam_y;
	double	tf_x;
	double	tf_y;
	int		scrnx;
	int		h;
	int		start_y;
	int		end_y;
	int		w;
	int		start_x;
	int		end_x;
	int		column;
	int		*spr_ord;
	double	*spr_dist;
	int		x;
	int		y;
}				t_sprite;

typedef struct s_param
{
	char	*r;
	char	*no;
	char	*n;
	char	*so;
	char	*s;
	char	*we;
	char	*w;
	char	*ea;
	char	*e;
	char	*spr;
	char	*sp;
	char	*f;
	char	*c;
}				t_param;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_img		*text_n;
	t_img		*text_s;
	t_img		*text_e;
	t_img		*text_w;
	t_img		*text_sp;
	t_plr		plr;
	t_list		*tmap;
	t_rc		rc;
	t_param		param;
	t_coloure	col_f;
	t_coloure	col_c;
	t_sprite	sprt;
	t_plr		*sprt_plc;
	int			sum_param;
	int			col_text;
	int			place_char;
	int			num_sprite;
	int			flag_plr;
	int			flag_save;
	int			map_h;
	int			h_total;
	int			win_w;
	int			win_h;
	int			w_max;
	int			h_max;
	char		**map;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_left;
	int			key_right;
	int			key_esc;
}				t_cub;

void	ft_init_param(t_cub *cub, char *file);
void	ft_get_coloure(t_coloure *col, char *s, t_cub *cub);
void	ft_check_buff(char *buff, t_cub *cub);
void	ft_notify_error(char *msg, t_cub *cub);
void	ft_notify_error_param(char *msg, t_cub *cub, char *s);
int		ft_exit(t_cub *cub);
void	ft_del_buff(void **buff);
void	ft_check_map(t_cub *cub);
void	ft_check_number_param(t_cub *cub);
void	ft_get_param(t_cub *cub, char *line, int i, int *flag_map);
void	ft_check_path(t_cub *cub);
void	ft_open_file(t_cub *cub, char *file);
void	ft_get_resolution(t_cub *cub);
t_img	*ft_create_text(t_cub *cub, char *add);
t_img	*ft_new_image(t_cub *cub);
void	ft_valid_map(t_cub *cub);
void	ft_ckeck_isalpha(char *s, int i, t_cub *cub);
int		ft_size_buff(char **buff);
void	ft_hook(t_cub *cub);
void	ft_free_img(t_cub *cub);
void	ft_control(t_cub *cub);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	ft_create_world(t_cub *cub);
void	ft_texture(t_cub *cub);
void	ft_get_pixel(t_cub *cub, int x);
void	ft_get_pixel_col(t_img *img, unsigned int colour, int x, int y);
void	ft_del_data(t_cub *cub);
void	ft_del_text(t_cub *cub, t_img *text);
void	ft_del_img(t_cub *cub);
void	ft_make_spr(t_cub *cub);
void	ft_spr_crt(t_cub *cub);
void	ft_save(t_cub *cub);
void	ft_check_format(t_cub *cub, char *str);
void	ft_check(t_cub *cub);

#endif
