/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:59:28 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/13 12:59:38 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"

/**
 * @brief Initialize mlx data.
 * Establish mlx connection in mlx_ptr and create new window in win_ptr.
 * Exits on error
 * (Helper function for ft_init_map)
 * @param width: Window width
 * @param height: Window height
 * @param title: Window title
 * @return t_mlx*: Pointer on mlx data
 */
t_mlx	*ft_init_mlx(int width, int height, const char *title)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) ft_calloc(1, sizeof(t_mlx));
	if (mlx == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		ft_putstr_fd(E_MLX_INIT_MSG, STDERR_FILENO);
		exit(E_MLX_INIT);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width, height, (char *) title);
	if (mlx->win_ptr == NULL)
	{
		ft_putstr_fd(E_MLX_WIN_MSG, STDERR_FILENO);
		exit(E_MLX_WIN);
	}
	return (mlx);
}
