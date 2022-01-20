/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:39:38 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/19 23:19:10 by hhamza           ###   ########.fr       */
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

	imgs = ft_allocate(1, sizeof(t_player_imgs));
	imgs->idle = ft_init_animation("data/idle.animation", mlx);
	imgs->left = ft_init_animation("data/left.animation", mlx);
	imgs->right = ft_init_animation("data/right.animation", mlx);
	imgs->up = ft_init_animation("data/up.animation", mlx);
	imgs->down = ft_init_animation("data/down.animation", mlx);
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
 * Exits on error
 * @param mlx: Mlx data
 * @param map: Map matrix
 * @return t_map*: Pointer on map data structure
 */
t_game	*ft_init_map(const char **map)
{
	t_game	*data;

	data = ft_allocate(1, sizeof(t_game));
	data->width = ft_strlen(map[0]);
	data->height = ft_maplen(map);
	data->collect_count = ft_count_collectibles(map);
	data->mlx = ft_init_mlx(data->width * BLOCK_SIZE, data->height * BLOCK_SIZE,
			WIN_TITLE);
	data->player_imgs = ft_init_player_imgs(data->mlx);
	data->collectible = ft_init_img("assets/collectible.xpm", data->mlx);
	data->empty = ft_init_img("assets/empty.xpm", data->mlx);
	data->enemy = ft_init_img("assets/enemy.xpm", data->mlx);
	data->exit = ft_init_img("assets/exit.xpm", data->mlx);
	data->wall = ft_init_img("assets/wall.xpm", data->mlx);
	data->map = (char **) map;
	data->p_collect = 0;
	data->player_moves = 0;
	data->enemy_count = ft_count_enemies(map);
	data->enemies = ft_init_enemies(map, data->enemy_count);
	return (data);
}
