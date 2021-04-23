/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:54:28 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/23 15:48:47 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_add_atoi(int check)
{
	if (check > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	res;
	unsigned int	rres;
	int				check;

	check = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	else if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		i++;
		check = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rres = res;
		res = (res * 10) + (str[i++] - '0');
		if (rres > res)
			return (ft_add_atoi(check));
	}
	return (res * check);
}
