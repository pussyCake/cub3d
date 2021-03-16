/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:24:11 by pantigon          #+#    #+#             */
/*   Updated: 2020/11/01 17:25:17 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	if (arr1 == NULL && arr2 == NULL)
		return (0);
	s1 = (unsigned char *)arr1;
	s2 = (unsigned char *)arr2;
	while (i < n && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
