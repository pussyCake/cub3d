/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:58:42 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/22 13:00:33 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_notify_error(char *msg)
{
	write(2, "\n", 1);
	write(2, "\033[1;31mError: \033[1;37m", 22);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	write(2, "\n", 1);
	exit(1);
}