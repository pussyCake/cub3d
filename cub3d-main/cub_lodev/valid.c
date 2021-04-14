/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:56:58 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/23 13:56:14 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_check_content(char *str, char *ch)
{
	int	i;
	int	check;

	while (*str)
	{
		if (!ft_strrchr(ch, *str))
			return (0);
		*str++;
	}
	return (1);
}

int		ft_check_amount(char *s, int num_wrd, char c, int num_c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			num_wrd--;
		}
		while (s[i] && s[i] == c)
		{
			i++;
			num_c--;
		}
	}
	if (num_c == 0 && num_wrd == 0)
		return (1);
	return (0);
}

int		ft_check_valid(char *s, char c, char *ch, int num_wrd, int num_c)
{
	int i;
	int wrd;
	int quote;

	i = 0;
	if (!ft_check_content(s, ch))
		return (0);
	if (!ft_check_amount(s, num_wrd, c, num_c))
		return (0);
	return (1);
}

void	ft_check_all_conf(t_cub *cub)
{
	if (cub->win_h == -1)
		ft_notify_error("no R in config!!!");
	if (!cub->no)
		ft_notify_error("no NO in config!!!");
	if (!cub->so)
		ft_notify_error("no SO in config!!!");
	if (!cub->we)
		ft_notify_error("no WE in config!!!");
	if (!cub->ea)
		ft_notify_error("no EA in config!!!");
	if (!cub->s)
		ft_notify_error("no S in config!!!");
	if (!cub->f)
		ft_notify_error("no F in config!!!");
	if (!cub->c)
		ft_notify_error("no C in config!!!");
}

void	ft_check_map(char *l_pre, char *l_now, char *l_nxt, int num, int lst)
{
	int i;
	int	len;

	i = 0;
	if (!ft_check_content(l_now, " 012NWSE"))
		ft_notify_error("forbidden element in map!!!");
	if (num == 0 || num == lst - 1)
		if (!ft_check_content(ft_strtrim(l_now, " "), "1 "))
			ft_notify_error("first & last line must contain only '1'!!!");
	if (num > 0 && num < lst - 1)
	{
		l_now
		len = ft_strlen(l_now);
		printf("%d", len);
		ft_putendl_fd(l_now, 1);
		while (l_now[i])
		{
			if ((i == 0 || i == len - 1) && l_now[i] != '1')
				ft_notify_error("first & last element must contain only '1'");
			else if ((l_pre[i] == ' ' || l_now[i - 1] == ' ' || l_now[i + 1]
			== ' ' || l_nxt[i] == ' '
			|| !l_pre[i] || !l_now[i - 1] || !l_now[i + 1]
			|| !l_nxt[i]) && l_now[i] != '1')
				ft_notify_error("govno karta!!!");
			i++;
		}
	}
}
