/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:04:17 by pantigon          #+#    #+#             */
/*   Updated: 2021/01/02 16:51:09 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*sum;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((sum = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_memmove(sum, s1, ft_strlen(s1));
	ft_memmove(sum + ft_strlen(s1), s2, ft_strlen(s2));
	sum[len] = '\0';
	return (sum);
}
