/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:51:44 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/17 15:29:14 by pantigon         ###   ########.fr       */
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
	sum = (char *)malloc(sizeof(char) * (len + 1));
	if (sum == NULL)
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
	n = ft_strchr(box, '\n');
	if (!n)
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
	n = ft_strchr(box, '\n');
	if (n)
	{
		*n = '\0';
		line = ft_strdup(box);
		*n = '\n';
	}
	else
		line = ft_strdup(box);
	return (line);
}

int	ft_join(char **buff, char **box, int byte)
{
	if (byte == -1)
	{
		free(*buff);
		return (-1);
	}
	else
	{
		*buff[byte] = '\0';
		*box = ft_strjoin(*box, *buff);
		if (!(*box))
			return (-1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	int				byte;
	static char		*box;

	byte = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || !buff)
		return (-1);
	while ((!box || (box && !(ft_strchr(box, '\n')))) && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (ft_join(&buff, &box, byte) == -1)
			return (-1);
	}
	free(buff);
	*line = get_line(box);
	box = new_box(box);
	if (byte == 0)
		return (0);
	return (1);
}
