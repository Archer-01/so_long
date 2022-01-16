/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 04:04:05 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/16 04:04:13 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

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

	move_count = ft_itoa(data->player_moves);
	msg = ft_strjoin("Move count: ", move_count);
	color = 0xFFFFFF00;
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->win_ptr, 20, 10, color, msg);
	free(move_count);
	free(msg);
}
