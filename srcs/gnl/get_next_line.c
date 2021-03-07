/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:51:44 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/07 13:13:29 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*s;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	s = (char*)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	while (len >= 0)
	{
		s[len] = str[len];
		len--;
	}
	return (s);
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
