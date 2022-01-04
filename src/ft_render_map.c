/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:43:54 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/04 12:48:19 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_render_map.h"

static size_t	ft_map_len(const char **map)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
		++i;
	return (i);
}

void	ft_render_map(const char **map)
{
	size_t	win_width;
	size_t	win_height;
	void	*mlx_ptr;
	void	*win_ptr;

	win_width = ft_strlen(map[0]) * WIN_BLOCK_WIDTH;
	win_height = ft_map_len(map) * WIN_BLOCK_HEIGHT;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, win_width, win_height, WIN_TITLE);
	mlx_loop(mlx_ptr);
}
