/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:41:27 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/05 18:00:32 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_images.h"

void	ft_put_xpm_image(t_mlx *mlx, const char *path, int x, int y)
{
	void	*img_ptr;
	int		w;
	int		h;

	img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, (char *)path, &w, &h);
	if (img_ptr == NULL)
	{
		write(STDERR_FILENO, "Error. Render failure\n", 22);
		exit(1);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img_ptr, x, y);
}
