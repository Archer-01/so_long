/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 04:33:58 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/16 04:11:43 by hhamza           ###   ########.fr       */
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
		--(*i);
	else if (keycode == A_KEY)
		--(*j);
	else if (keycode == S_KEY)
		++(*i);
	else if (keycode == D_KEY)
		++(*j);
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
	ft_put_img(data->player_imgs->idle->frames[0], i, j, data->mlx);
	data->player_i = i;
	data->player_j = j;
}

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
 * @brief Move player.
 *
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
		ft_move_player(data, i, j);
		++(data->player_moves);
		ft_draw_walls(data);
		ft_log_moves(data);
	}
	else if (data->map[i][j] == 'E' && data->p_collect == data->collect_count)
	{
		++(data->player_moves);
		ft_draw_walls(data);
		ft_log_moves(data);
		printf("%sYou win!!\n", "\e[0;32m");
		ft_exit(data);
	}
}
