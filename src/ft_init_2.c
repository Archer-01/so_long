/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:19:51 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/14 04:14:56 by hhamza           ###   ########.fr       */
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
