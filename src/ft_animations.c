/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:41:29 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/21 13:48:24 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_animations.h"

/**
 * @brief Get proper animation
 *
 * @param data: Game data
 * @return t_animation*: Proper animation to display
 */
static t_animation	*ft_get_animation(t_game *data)
{
	if (ft_strncmp(data->player_direction, "run-left", 8) == 0
		|| ft_strncmp(data->player_direction, "idle-left", 9) == 0)
		return (data->player_imgs->idle_left);
	else if (ft_strncmp(data->player_direction, "run-right", 9) == 0
		|| ft_strncmp(data->player_direction, "idle-right", 10) == 0)
		return (data->player_imgs->idle_right);
	else if (ft_strncmp(data->player_direction, "run-up", 6) == 0
		|| ft_strncmp(data->player_direction, "idle-up", 7) == 0)
		return (data->player_imgs->idle_up);
	else if (ft_strncmp(data->player_direction, "run-down", 8) == 0
		|| ft_strncmp(data->player_direction, "idle-down", 9) == 0)
		return (data->player_imgs->idle_down);
	else
	{
		ft_putstr_fd(E_INVAL_DIR_MSG, STDERR_FILENO);
		exit(E_INVAL_DIR);
	}
}

/**
 * @brief Player idle animation
 *
 * @param data: Game data
 */
void	ft_idle(t_game *data)
{
	static int	i;
	static int	j;
	t_animation	*animation;

	animation = ft_get_animation(data);
	if (j == animation->duration)
	{
		j = 0;
		++i;
	}
	if (i == animation->frame_count)
		i = 0;
	ft_put_img(animation->frames[i], data->player_i, data->player_j, data->mlx);
	++j;
}
