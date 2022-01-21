/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 04:33:58 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/21 11:39:06 by hhamza           ###   ########.fr       */
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
static void	ft_calc_new_coords(int keycode, t_game *data, int *i, int *j)
{
	*i = data->player_i;
	*j = data->player_j;
	if (keycode == W_KEY)
	{
		--(*i);
		data->player_direction = "run-up";
	}
	else if (keycode == A_KEY)
	{
		--(*j);
		data->player_direction = "run-left";
	}
	else if (keycode == S_KEY)
	{
		++(*i);
		data->player_direction = "run-down";
	}
	else if (keycode == D_KEY)
	{
		++(*j);
		data->player_direction = "run-right";
	}
}

/**
 * @brief Move player to appropriate position
 *
 * @param data: Game data
 * @param i: New position line index in map matrix
 * @param j: New position column index in map matrix
 */
static void	ft_move_player(t_game *data, int i, int j)
{
	ft_swap(&data->map[data->player_i][data->player_j], &data->map[i][j]);
	if (data->map[data->player_i][data->player_j] == 'C')
	{
		data->map[data->player_i][data->player_j] = '0';
		++(data->p_collect);
	}
	ft_put_img(data->empty, data->player_i, data->player_j, data->mlx);
	data->player_i = i;
	data->player_j = j;
}

/**
 * @brief Move player.
 * Move on empty, collectible and exit if possible.
 * Game over on enemy.
 * @param data: Game data
 * @param keycode: Pressed key code
 */
void	ft_move(t_game *data, int keycode)
{
	int	i;
	int	j;

	ft_calc_new_coords(keycode, data, &i, &j);
	if (data->map[i][j] == '0' || data->map[i][j] == 'C')
	{
		++(data->player_moves);
		ft_move_player(data, i, j);
		ft_log_moves(data);
	}
	else if (data->map[i][j] == 'V' || data->map[i][j] == 'H')
	{
		++(data->player_moves);
		ft_log_moves(data);
		printf("%sGame over\n", "\e[0;31m");
		ft_exit(data);
	}
	else if (data->map[i][j] == 'E' && data->p_collect == data->collect_count)
	{
		++(data->player_moves);
		ft_log_moves(data);
		printf("%sYou win!!\n", "\e[0;32m");
		ft_exit(data);
	}
}
