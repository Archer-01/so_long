/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_animations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:19:51 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/12 18:55:34 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"

/**
 * @brief Initialize player idle animation images.
 * Exits on failure
 * @param mlx: Mlx data
 * (Helper function for ft_init_animations)
 * @return t_animation*: Pointer on animations bundled in data structure
 */
t_animation	*ft_init_idle(t_mlx *mlx)
{
	t_animation	*idle;

	idle = (t_animation *) ft_calloc(1, sizeof(t_animation));
	if (idle == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	idle->duration = 10;
	idle->frame_count = 2;
	idle->frames = (void **) ft_calloc(idle->frame_count, sizeof(void *));
	if (idle->frames == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	idle->frames[0] = ft_init_img("assets/idle-1.xpm", mlx);
	idle->frames[1] = ft_init_img("assets/idle-2.xpm", mlx);
	return (idle);
}

/**
 * @brief Initialize player left animation images.
 * Exits on failure
 * @param mlx: Mlx data
 * (Helper function for ft_init_animations)
 * @return t_animation*: Pointer on animations bundled in data structure
 */
t_animation	*ft_init_left(t_mlx *mlx)
{
	t_animation	*left;

	left = (t_animation *) ft_calloc(1, sizeof(t_animation));
	if (left == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	left->duration = 10;
	left->frame_count = 4;
	left->frames = (void **) ft_calloc(left->frame_count, sizeof(void *));
	if (left->frames == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	left->frames[0] = ft_init_img("assets/left-1.xpm", mlx);
	left->frames[1] = ft_init_img("assets/left-2.xpm", mlx);
	left->frames[2] = ft_init_img("assets/left-3.xpm", mlx);
	left->frames[3] = ft_init_img("assets/left-4.xpm", mlx);
	return (left);
}

/**
 * @brief Initialize player right animation images.
 * Exits on failure
 * @param mlx: Mlx data
 * (Helper function for ft_init_animations)
 * @return t_animation*: Pointer on animations bundled in data structure
 */
t_animation	*ft_init_right(t_mlx *mlx)
{
	t_animation	*right;

	right = (t_animation *) ft_calloc(1, sizeof(t_animation));
	if (right == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	right->duration = 10;
	right->frame_count = 4;
	right->frames = (void **) ft_calloc(right->frame_count, sizeof(void *));
	if (right->frames == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	right->frames[0] = ft_init_img("assets/right-1.xpm", mlx);
	right->frames[1] = ft_init_img("assets/right-2.xpm", mlx);
	right->frames[2] = ft_init_img("assets/right-3.xpm", mlx);
	right->frames[3] = ft_init_img("assets/right-4.xpm", mlx);
	return (right);
}

/**
 * @brief Initialize player up animation images.
 * Exits on failure
 * @param mlx: Mlx data
 * (Helper function for ft_init_animations)
 * @return t_animation*: Pointer on animations bundled in data structure
 */
t_animation	*ft_init_up(t_mlx *mlx)
{
	t_animation	*up;

	up = (t_animation *) ft_calloc(1, sizeof(t_animation));
	if (up == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	up->duration = 10;
	up->frame_count = 4;
	up->frames = (void **) ft_calloc(up->frame_count, sizeof(void *));
	if (up->frames == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	up->frames[0] = ft_init_img("assets/up-1.xpm", mlx);
	up->frames[1] = ft_init_img("assets/up-2.xpm", mlx);
	up->frames[2] = ft_init_img("assets/up-3.xpm", mlx);
	up->frames[3] = ft_init_img("assets/up-4.xpm", mlx);
	return (up);
}

/**
 * @brief Initialize player down animation images.
 * Exits on failure
 * (Helper function for ft_init_animations)
 * @param mlx: Mlx data
 * @return t_animation*: Pointer on animations bundled in data structure
 */
t_animation	*ft_init_down(t_mlx *mlx)
{
	t_animation	*down;

	down = (t_animation *) ft_calloc(1, sizeof(t_animation));
	if (down == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	down->duration = 10;
	down->frame_count = 4;
	down->frames = (void **) ft_calloc(down->frame_count, sizeof(void *));
	if (down->frames == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	down->frames[0] = ft_init_img("assets/down-1.xpm", mlx);
	down->frames[1] = ft_init_img("assets/down-2.xpm", mlx);
	down->frames[2] = ft_init_img("assets/down-3.xpm", mlx);
	down->frames[3] = ft_init_img("assets/down-4.xpm", mlx);
	return (down);
}
