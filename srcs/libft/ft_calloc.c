/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:24:56 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/17 14:56:12 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*arr;
	size_t	max;

	max = num * size;
	arr = malloc(max);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, max);
	return (arr);
}
