/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:05:04 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/15 22:00:11 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hooks.h"

/**
 * @brief Keyboard hooks handler.
 * (Helper function to ft_install_hooks)
 * @param keycode: Pressed key code
 * @param data: Game data
 * @return int: Zero
 */
static int	ft_key_hook_handler(int keycode, t_map *data)
{
	if (keycode == ESC_KEY)
		ft_exit(data);
	else if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY
		|| keycode == D_KEY)
		ft_move(data, keycode);
	return (0);
}

/**
 * @brief Install all necessary mlx hooks
 *
 * @param data:Game data
 */
void	ft_install_hooks(t_map *data)
{
	mlx_hook(data->mlx->win_ptr, ON_WIN_CLOSE, 0, &ft_exit, data);
	mlx_hook(data->mlx->win_ptr, ON_KEY_PRESS, 0, ft_key_hook_handler, data);
}
