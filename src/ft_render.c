/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:42:13 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/16 08:04:59 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_render.h"

/**
 * @brief Put image to window.
 * Exits on error.
 * @param img_ptr: Image pointer
 * @param i: Line index in map matrix
 * @param j: Column index in map matrix
 * @param mlx: Mlx data
 */
void	ft_put_img(void *img_ptr, int i, int j, t_mlx *mlx)
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
 * @brief ft_render helper function.
 * (This function was made for norm reasons).
 * @param data: Game data
 * @param i: Current line index in map matrix
 * @param j: Current column index in map matrix
 */
static void	ft_render_helper(t_game *data, int i, int j)
{
	if (data->map[i][j] == '0')
		ft_put_img(data->empty, i, j, data->mlx);
	else if (data->map[i][j] == '1')
		ft_put_img(data->wall, i, j, data->mlx);
	else if (data->map[i][j] == 'C')
		ft_put_img(data->collectible, i, j, data->mlx);
	else if (data->map[i][j] == 'E')
		ft_put_img(data->exit, i, j, data->mlx);
	else if (data->map[i][j] == 'P')
	{
		ft_put_img(data->player_imgs->idle->frames[0], i, j, data->mlx);
		data->player_i = i;
		data->player_j = j;
	}
	else if (data->map[i][j] == 'X')
		ft_put_img(data->enemy, i, j, data->mlx);
}

/**
 * @brief Render map to window.
 *
 * @param map_data: Game data (images, dimensions, ...)
 * @param map: Map matrix
 */
void	ft_render(t_game *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i] != NULL)
	{
		j = -1;
		while (data->map[i][++j] != '\0')
			ft_render_helper(data, i, j);
	}
	ft_log_moves(data);
}
