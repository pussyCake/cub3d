/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:20:36 by pantigon          #+#    #+#             */
/*   Updated: 2020/11/02 14:48:42 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (dest[i] != '\0' && i < n)
		i++;
	if (i != n)
		return (ft_strlcpy(dest + i, src, n - i) + i);
	return (n + ft_strlen(src));
}
