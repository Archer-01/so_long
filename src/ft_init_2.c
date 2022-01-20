/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:19:51 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/20 13:40:12 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"

/**
 * @brief Initialize animation.
 * Exits on error
 * @param path: Path to animation file
 * @param mlx: Mlx data
 * @return t_animation*: Pointer on animations bundled in structure
 */
t_animation	*ft_init_animation(const char *path, t_mlx *mlx)
{
	int			fd;
	t_animation	*animation;
	char		*str;
	int			i;

	fd = ft_open(path);
	animation = ft_allocate(1, sizeof(t_animation));
	str = get_next_line(fd);
	animation->duration = ft_atoi(str);
	free(str);
	str = get_next_line(fd);
	animation->frame_count = ft_atoi(str);
	free(str);
	animation->frames = ft_allocate(animation->frame_count, sizeof(void *));
	i = 0;
	while (i < animation->frame_count)
	{
		str = get_next_line(fd);
		*ft_strchr(str, '\n') = '\0';
		animation->frames[i] = ft_init_img(str, mlx);
		free(str);
		++i;
	}
	close(fd);
	return (animation);
}

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

/**
 * @brief Count enemies on map
 *
 * @param map: Map to operate on
 * @return int: Enemy count
 */
int	ft_count_enemies(const char **map)
{
	int	i;
	int	j;
	int	enemies_count;

	enemies_count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'V' || map[i][j] == 'H')
				++enemies_count;
			++j;
		}
		++i;
	}
	return (enemies_count);
}

/**
 * @brief Save enemies type (H|V) and position (i, j)
 *
 * @param map: Map to operate on
 * @param enemies_count: Enemies count
 * @return t_enemy*: Array of enemy data
 */
t_enemy	*ft_init_enemies(const char **map, int enemies_count)
{
	t_enemy	*enemies_pos;
	int		i;
	int		j;
	int		k;

	if (enemies_count == 0)
		return (NULL);
	enemies_pos = (t_enemy *) ft_allocate(enemies_count, sizeof(t_enemy));
	k = 0;
	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == 'V' || map[i][j] == 'H')
			{
				enemies_pos[k].i = i;
				enemies_pos[k].j = j;
				enemies_pos[k].type = map[i][j];
				enemies_pos[k++].curr_direction = 0;
			}
		}
	}
	return (enemies_pos);
}
