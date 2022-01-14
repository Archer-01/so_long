/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:42:13 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/14 20:10:10 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_render.h"

/**
 * @brief Put image to window.
 * Exits on error.
 * @param img_ptr: Image pointer
 * @param x: x position of image in window
 * @param y: y position of image in window
 * @param mlx: Mlx data
 */
static void	ft_put_img(void *img_ptr, int i, int j, t_mlx *mlx)
{
	if (img_ptr == NULL)
	{
		ft_putstr_fd(E_NULL_ARG_MSG, STDERR_FILENO);
		exit(E_NULL_ARG);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img_ptr,
		j * BLOCK_SIZE, i * BLOCK_SIZE);
}

/**
 * @brief Render map to window.
 *
 * @param map_data: Map data (images, dimensions, ...)
 * @param map: Map matrix
 */
void	ft_render(t_map *data, const char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == '0')
				ft_put_img(data->empty, i, j, data->mlx);
			else if (map[i][j] == '1')
				ft_put_img(data->wall, i, j, data->mlx);
			else if (map[i][j] == 'C')
				ft_put_img(data->collectible, i, j, data->mlx);
			else if (map[i][j] == 'E')
				ft_put_img(data->exit, i, j, data->mlx);
			else if (map[i][j] == 'P')
			{
				ft_put_img(data->player_imgs->idle->frames[0], i, j, data->mlx);
				data->player_x = j * BLOCK_SIZE;
				data->player_y = i * BLOCK_SIZE;
			}
		}
	}
}
