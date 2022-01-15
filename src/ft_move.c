/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 04:33:58 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/15 22:24:38 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_move.h"

/**
 * @brief Calculate new player coordinates based on pressed key.
 * (Helper function to ft_move)
 * @param keycode: Pressed key code
 * @param data: Game data
 * @param i: Pointer to line index
 * @param j: Pointer to column index
 */
static void	ft_calc_new_coords(int keycode, t_map *data, int *i, int *j)
{
	*i = data->player_i;
	*j = data->player_j;
	if (keycode == W_KEY)
		--(*i);
	else if (keycode == A_KEY)
		--(*j);
	else if (keycode == S_KEY)
		++(*i);
	else if (keycode == D_KEY)
		++(*j);
}

static void	ft_log_moves(t_map *data)
{
	++(data->player_moves);
	printf("%sMove count: %d\n", "\e[0;33m", data->player_moves);
}

/**
 * @brief Move player.
 *
 * @param data: Game data
 * @param keycode: Pressed key code
 */
void	ft_move(t_map *data, int keycode)
{
	int	i;
	int	j;

	ft_calc_new_coords(keycode, data, &i, &j);
	if (data->map[i][j] == '0' || data->map[i][j] == 'C')
	{
		ft_swap(&data->map[data->player_i][data->player_j], &data->map[i][j]);
		if (data->map[data->player_i][data->player_j] == 'C')
		{
			data->map[data->player_i][data->player_j] = '0';
			++(data->player_collectibles);
		}
		ft_put_img(data->empty, data->player_i, data->player_j, data->mlx);
		ft_put_img(data->player_imgs->idle->frames[0], i, j, data->mlx);
		data->player_i = i;
		data->player_j = j;
		ft_log_moves(data);
	}
	else if (data->map[i][j] == 'E'
		&& data->player_collectibles == data->collectible_count)
	{
		ft_log_moves(data);
		printf("%sYou win!!\n", "\e[0;32m");
		ft_exit(data);
	}
}
