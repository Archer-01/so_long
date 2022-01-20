/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:38:59 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/19 23:24:25 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enemy.h"

/**
 * @brief Calculate enemy's next move
 *
 * @param enemy: Enemy to operate on
 * @param direction: Enemy direction
 * @param i: Pointer to line index
 * @param j: Pointer to column index
 */
static void	ft_calc_next_move(t_enemy *enemy, int direction, int *i, int *j)
{
	*i = enemy->i;
	*j = enemy->j;
	if (direction == ENEMY_LEFT)
		--(*j);
	else if (direction == ENEMY_RIGHT)
		++(*j);
	else if (direction == ENEMY_UP)
		--(*i);
	else if (direction == ENEMY_DOWN)
		++(*i);
}

/**
 * @brief Move enemy to appropriate direction
 *
 * @param data: Game data
 * @param index: Enemy index in enemies array
 * @param direction: Direction to move to
 * @return int: 1 if enemy moved, 0 otherwise
 */
static int	ft_move_enemy(t_game *data, int index, int direction)
{
	int	i;
	int	j;

	ft_calc_next_move(&data->enemies[index], direction, &i, &j);
	if (data->map[i][j] == '0')
	{
		ft_swap(&data->map[i][j],
			&data->map[data->enemies[index].i][data->enemies[index].j]);
		ft_put_img(data->empty, data->enemies[index].i,
			data->enemies[index].j, data->mlx);
		ft_put_img(data->enemy, i, j, data->mlx);
		data->enemies[index].i = i;
		data->enemies[index].j = j;
		return (1);
	}
	else if (data->map[i][j] == 'P')
	{
		printf("%sGame over\n", "\e[0;31m");
		ft_exit(data);
	}
	return (0);
}

/**
 * @brief Set next enemy move
 *
 * @param data: Game data
 * @param move_ret: ft_calc_next_move's return value
 * @param index: Enemy index in enemies array
 */
static void	ft_set_next_move(t_game *data, int move_ret, int index)
{
	if (move_ret != 0)
		return ;
	if (data->enemies[index].curr_direction == ENEMY_RIGHT)
		data->enemies[index].curr_direction = ENEMY_LEFT;
	else if (data->enemies[index].curr_direction == ENEMY_LEFT)
		data->enemies[index].curr_direction = ENEMY_RIGHT;
	else if (data->enemies[index].curr_direction == ENEMY_UP)
		data->enemies[index].curr_direction = ENEMY_DOWN;
	else if (data->enemies[index].curr_direction == ENEMY_DOWN)
		data->enemies[index].curr_direction = ENEMY_UP;
}

/**
 * @brief Make enemies patrol
 *
 * @param data: Game data
 * @return int: Zero
 */
int	ft_enemy_patrol(t_game *data)
{
	static int	i;
	int			move_ret;

	if (i == data->enemy_count)
		i = 0;
	if (data->enemies[i].curr_direction == 0)
	{
		if (data->enemies[i].type == 'H')
			data->enemies[i].curr_direction = ENEMY_RIGHT;
		else if (data->enemies[i].type == 'V')
			data->enemies[i].curr_direction = ENEMY_UP;
	}
	move_ret = ft_move_enemy(data, i, data->enemies[i].curr_direction);
	ft_set_next_move(data, move_ret, i);
	++i;
	return (0);
}
