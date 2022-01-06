/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:43:54 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/05 18:00:46 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_render_map.h"

static size_t	ft_map_len(const char **map)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
		++i;
	return (i);
}

/**
 * @brief Put background to window
 *
 * @param mlx: needed mlx data (mlx connection pointer, window pointer,
 *  window width and height)
 */
static void	ft_put_bg(t_mlx *mlx, int color)
{
	t_img	img;
	int		i;
	int		j;

	img.img = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	if (img.img == NULL)
	{
		write(STDERR_FILENO, "Error. Rendering failure\n", 25);
		exit(1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	i = -1;
	while (++i < mlx->width)
	{
		j = -1;
		while (++j < mlx->height)
			ft_mlx_pixel_put(&img, i, j, color);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img, 0, 0);
}

static void	ft_put_blocks(t_mlx *mlx, const char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			x = j * WIN_BLOCK_WIDTH;
			y = i * WIN_BLOCK_HEIGHT;
			if (map[i][j] == '1')
				ft_put_xpm_image(mlx, "assets/barrel.xpm", x, y);
			else
				continue ;
		}
	}
}

/**
 * @brief Render map to window
 *
 * @param map: Map to render
 */
void	ft_render_map(const char **map)
{
	t_mlx	mlx;
	int		color;

	mlx.width = ft_strlen(map[0]) * WIN_BLOCK_WIDTH;
	mlx.height = ft_map_len(map) * WIN_BLOCK_HEIGHT;
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
	{
		write(STDERR_FILENO, "Error. Rendering failure\n", 25);
		exit(1);
	}
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.width, mlx.height, WIN_TITLE);
	if (mlx.win_ptr == NULL)
	{
		write(STDERR_FILENO, "Error. Rendering failure\n", 25);
		exit(1);
	}
	color = ft_get_color(0, 24, 26, 36);
	ft_put_bg(&mlx, color);
	ft_put_blocks(&mlx, map);
	mlx_loop(mlx.mlx_ptr);
}
