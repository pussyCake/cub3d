/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:40:30 by pantigon          #+#    #+#             */
/*   Updated: 2021/03/09 14:50:48 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H
#include <fcntl.h>
#include "libft.h"
#include "mlx.h"
#include "get_next_line.h"

char	**parse_map(int argc, char **argv);
char	**make_map(t_list **head, int size);

#endif
