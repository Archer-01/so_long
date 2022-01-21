/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 04:04:05 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/20 17:33:27 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

/**
 * @brief Draw 1st row walls.
 * (Used to avoid text overlapping when updating player moves)
 * @param data: Game data
 */
static void	ft_draw_walls(t_game *data)
{
	int	j;

	j = 0;
	while (j < data->width)
	{
		ft_put_img(data->wall, 0, j, data->mlx);
		++j;
	}
}

/**
 * @brief Log player moves
 *
 * @param data: Game data
 */
void	ft_log_moves(t_game *data)
{
	char	*move_count;
	char	*msg;
	int		color;

	ft_draw_walls(data);
	move_count = ft_itoa(data->player_moves);
	msg = ft_strjoin("Move count: ", move_count);
	color = 0xFFFFFF00;
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->win_ptr, 20, 10, color, msg);
	free(move_count);
	free(msg);
}
