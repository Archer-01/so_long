/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:41:49 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/16 04:08:02 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"
#include "ft_errors.h"
#include <stdio.h>
#include "ft_init.h"
#include "ft_destroy.h"
#include <mlx.h>
#include "ft_render.h"
#include "ft_hooks.h"
#include "ft_utils.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*data;

	if (argc != 2)
	{
		ft_putstr_fd(E_BADARGS_MSG, STDERR_FILENO);
		exit(E_BADARGS);
	}
	map = ft_parser(argv[1]);
	data = ft_init_map((const char **) map);
	ft_render(data);
	ft_install_hooks(data);
	mlx_loop(data->mlx->mlx_ptr);
	return (0);
}
