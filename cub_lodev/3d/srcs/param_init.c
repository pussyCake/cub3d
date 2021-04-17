/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:12:13 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/17 14:13:21 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_texture(t_cub *cub)
{
	cub->text_n = ft_create_text(cub, cub->param.no);
	if ((cub->text_n) == NULL)
		ft_notify_error("fail in texture", cub);
	cub->text_s = ft_create_text(cub, cub->param.so);
	if ((cub->text_s) == NULL)
		ft_notify_error("fail in texture", cub);
	cub->text_w = ft_create_text(cub, cub->param.we);
	if ((cub->text_w) == NULL)
		ft_notify_error("fail in texture", cub);
	cub->text_e = ft_create_text(cub, cub->param.ea);
	if ((cub->text_e) == NULL)
		ft_notify_error("fail in texture", cub);
	cub->text_sp = ft_create_text(cub, cub->param.spr);
	if ((cub->text_sp) == NULL)
		ft_notify_error("fail in texture", cub);
}

void	ft_init_plr(t_cub *cub)
{
	if (cub->plr.plr == 'N')
	{
		cub->rc.dir.y = -1;
		cub->rc.plane.x = -0.80;
	}
	if (cub->plr.plr == 'S')
	{
		cub->rc.dir.y = 1;
		cub->rc.plane.x = 0.80;
	}
	if (cub->plr.plr == 'E')
	{
		cub->rc.dir.x = 1;
		cub->rc.plane.y = -0.80;
	}
	if (cub->plr.plr == 'W')
	{
		cub->rc.dir.x = -1;
		cub->rc.plane.y = 0.80;
	}
}

void	ft_init_for_start(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!(cub->mlx))
		ft_notify_error("fail mlx", cub);
	cub->win = mlx_new_window(cub->mlx, cub->win_w, cub->win_h, "GAME");
	if (!(cub->win))
		ft_notify_error("fail mlx (create win)", cub);
	//cub->img = ft_new_image(cub);
	ft_init_plr(cub);
}

void	ft_init_param(t_cub *cub, char *file)
{
	cub->rc.speed = 0.05;
	ft_open_file(cub, file);
	ft_check_map(cub);
	ft_get_coloure(cub, cub->param.f, 'F');
	ft_get_coloure(cub, cub->param.c, 'C');
	ft_get_resolution(cub);
	ft_init_for_start(cub);
	cub->rc.zbuff = malloc(sizeof(double) * cub->win_w);
	if (!(cub->rc.zbuff))
		ft_notify_error("fail malloc", cub);
	//ft_init_texture(cub);
}
