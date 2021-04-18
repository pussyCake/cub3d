/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:50:09 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/17 15:03:05 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*s;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	while (len >= 0)
	{
		s[len] = str[len];
		len--;
	}
	return (s);
}
