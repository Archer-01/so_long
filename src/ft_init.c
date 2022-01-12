/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:32 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/12 19:43:52 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"

/**
 * @brief Create new mlx image.
 * Exits on error
 * @param path; Image file path
 * @param mlx: Mlx data
 * @return void*: Newly created image pointer
 */
void	*ft_init_img(const char *path, t_mlx *mlx)
{
	void	*img_ptr;
	int		w;
	int		h;

	img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, (char *)path, &w, &h);
	if (img_ptr == NULL)
	{
		ft_putstr_fd(E_MLX_IMG_MSG, STDERR_FILENO);
		exit(E_MLX_IMG);
	}
	return (img_ptr);
}

/**
 * @brief Create mlx images for all player animations.
 * Exits on error
 * @param mlx: Mlx data
 * @return t_player_imgs*: Pointer on newly created images bundled into
 * a data structure
 */
t_player_imgs	*ft_init_player_imgs(t_mlx *mlx)
{
	t_player_imgs	*imgs;

	imgs = (t_player_imgs *) ft_calloc(1, sizeof(t_player_imgs));
	if (imgs == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	imgs->idle = ft_init_idle(mlx);
	imgs->left = ft_init_left(mlx);
	imgs->right = ft_init_right(mlx);
	imgs->up = ft_init_up(mlx);
	imgs->down = ft_init_down(mlx);
	return (imgs);
}

/**
 * @brief Get map line count
 *
 * @param map: Map to operate on
 * @return int: Map line count
 */
static int	ft_maplen(const char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		++i;
	return (i);
}

/**
 * @brief Count collectibles
 *
 * @param map: Map to operate on
 * @return int: Collectibles count
 */
static int	ft_count_collectibles(const char **map)
{
	int	i;
	int	j;
	int	collectible_count;

	collectible_count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				++collectible_count;
			++j;
		}
		++i;
	}
	return (collectible_count);
}

/**
 * @brief Initialize map data (images, map dimensions and collectibles count).
 *
 * @param mlx: Mlx data
 * @param map: Map matrix
 * @return t_map*: Pointer on map data structure
 */
t_map	*ft_init_map(t_mlx *mlx, const char **map)
{
	t_map	*map_data;

	map_data = (t_map *) ft_calloc(1, sizeof(t_map));
	if (map == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	map_data->player_imgs = ft_init_player_imgs(mlx);
	map_data->collectible = ft_init_img("assets/collectible.xpm", mlx);
	map_data->empty = ft_init_img("assets/empty.xpm", mlx);
	map_data->exit = ft_init_img("assets/exit.xpm", mlx);
	map_data->wall = ft_init_img("assets/barrel.xpm", mlx);
	map_data->width = ft_strlen(map[0]) * BLOCK_SIZE;
	map_data->height = ft_maplen(map) * BLOCK_SIZE;
	map_data->collectible_count = ft_count_collectibles(map);
	return (map_data);
}
