/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:51:44 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/16 20:52:50 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	free((char *)s1);
	return (sum);
}

char	*new_box(char *box)
{
	char	*n;
	char	*tmp;

	if (!box)
		return (0);
	if (!(n = ft_strchr(box, '\n')))
	{
		free(box);
		return (0);
	}
	n++;
	tmp = ft_strdup(n);
	free(box);
	return (tmp);
}

char	*get_line(char *box)
{
	int		i;
	char	*n;
	char	*line;

	i = 0;
	if (!box)
		return (0);
	if ((n = ft_strchr(box, '\n')))
	{
		*n = '\0';
		line = ft_strdup(box);
		*n = '\n';
	}
	else
		line = ft_strdup(box);
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	int				byte;
	static char		*box;

	byte = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || \
	!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((!box || (box && !(ft_strchr(box, '\n')))) && byte != 0)
	{
		if ((byte = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[byte] = '\0';
		if (!(box = ft_strjoin(box, buff)))
			return (-1);
	}
	free(buff);
	*line = get_line(box);
	box = new_box(box);
	if (byte == 0)
		return (0);
	return (1);
}
