/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:04:43 by pantigon          #+#    #+#             */
/*   Updated: 2020/11/03 19:55:52 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s) - (size_t)start) < len)
		len = ft_strlen(s) - (int)start;
	if ((cpy = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_strlcpy(cpy, s + start, len + 1);
	cpy[len] = '\0';
	return (cpy);
}
