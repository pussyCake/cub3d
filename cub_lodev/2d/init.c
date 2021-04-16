/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:05:15 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/22 10:57:22 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_cub(t_cub *cub)
{
	cub->tmap = 0;
	cub->map = 0;
	cub->map_h = 0;
	cub->win_w = -1;
	cub->win_h = -1;
	cub->w_max = 0;
	cub->h_max = 0;
	cub->no = 0;
	cub->so = 0;
	cub->we = 0;
	cub->ea = 0;
	cub->s = 0;
	cub->f = -1;
	cub->c = -1;
	cub->key_w = 0;
	cub->key_s = 0;
	cub->key_a = 0;
	cub->key_d = 0;
	cub->key_left = 0;
	cub->key_right = 0;
	cub->key_esc = 0;
}