/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:05:25 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/14 13:23:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_check_save(t_cub *cub, int argc, char *s)
{
	if (argc == 3 && (ft_strncmp(s, "--save", 7) == 0))
		cub->flag_save = 1;
	else if (argc == 3)
		ft_notify_error( "for save screen input '--save'", cub);
}

int		check_name_cub(char *str, t_cub *cub)
{
	int		len;
	char	*s;

	s = ft_strchr(str, '.');
	if (!s || ft_strncmp(s, ".cub", 5) != 0)
		ft_notify_error("MUST BE '.cub' file", cub);
	return (1);
}

int		main(int argc, char **argv)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	if ((argc != 2 && argc != 3) || !check_name_cub(argv[1], &cub))
		ft_notify_error("MUST BE 2 or 3 ARGUMENTS", &cub);
	if (argc == 3)
		ft_check_save(&cub, argc, argv[2]);
	ft_init_param(&cub, argv[1]);

	// if ((info.error = init_var(&info, argv[1])) != SUCCESS)
	// 	return (re_errors(info.error, &info));
	// if (info.flag_save == 1)
	// {
	// 	if ((info.error = launch_save(&info)) != SUCCESS)
	// 		return (re_errors(info.error, &info));
	// 	return (SUCCESS);
	// }
	// if ((info.error = events(&info)) != SUCCESS)
	// 	return (re_errors(info.error, &info));
	// return (SUCCESS);
	return (0);
}