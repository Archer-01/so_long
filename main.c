/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:41:49 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/13 21:30:00 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"
#include "ft_errors.h"
#include <stdio.h>
#include "ft_init.h"
#include "ft_destroy.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	char	**map;
	t_map	*map_data;

	if (argc != 2)
	{
		ft_putstr_fd(E_BADARGS_MSG, STDERR_FILENO);
		exit(E_BADARGS);
	}
	map = ft_parser(argv[1]);
	map_data = ft_init_map((const char **) map);
	return (0);
}
