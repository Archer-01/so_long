/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:27:02 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/13 12:54:29 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_destroy.h"

/**
 * @brief Destroy in-memory image.
 * Destroy image and set its pointer to NULL.
 * Exits on error.
 * (Helper function for ft_destroy_map)
 * @param img: Address of image pointer to be destroyed
 * @param mlx: Mlx data
 */
static void	ft_destroy_img(void **img, t_mlx *mlx)
{
	if (img == NULL || mlx == NULL)
	{
		ft_putstr_fd(E_NULL_ARG_MSG, STDERR_FILENO);
		exit(E_NULL_ARG);
	}
	mlx_destroy_image(mlx->mlx_ptr, *img);
	*img = NULL;
}

/**
 * @brief Destroy animation.
 * Destroy all animation frames, free all allocated memory and set animation
 * pointer to NULL.
 * Exits on error.
 * (Helper function for ft_destroy_player_imgs)
 * @param animation: Animation pointer to destroy
 * @param mlx: Mlx data
 */
static void	ft_destroy_animation(t_animation **animation, t_mlx *mlx)
{
	int	i;

	if (animation == NULL || mlx == NULL)
	{
		ft_putstr_fd(E_NULL_ARG_MSG, STDERR_FILENO);
		exit(E_NULL_ARG);
	}
	i = 0;
	while (i < (*animation)->frame_count)
	{
		ft_destroy_img(&((*animation)->frames[i]), mlx);
		++i;
	}
	free((*animation)->frames);
	*animation = NULL;
}

/**
 * @brief Destroy player images.
 * Destroy all animations, free all allocated and set player animation pointer
 * to NULL.
 * Exits on error.
 * (Helper function for ft_destroy_map)
 * @param player_imgs: Player images to destroy
 * @param mlx: Mlx data
 */
static void	ft_destroy_player_imgs(t_player_imgs **player_imgs, t_mlx *mlx)
{
	if (player_imgs == NULL || mlx == NULL)
	{
		ft_putstr_fd(E_NULL_ARG_MSG, STDERR_FILENO);
		exit(E_NULL_ARG);
	}
	ft_destroy_animation(&((*player_imgs)->idle), mlx);
	ft_destroy_animation(&((*player_imgs)->left), mlx);
	ft_destroy_animation(&((*player_imgs)->right), mlx);
	ft_destroy_animation(&((*player_imgs)->up), mlx);
	ft_destroy_animation(&((*player_imgs)->down), mlx);
	*player_imgs = NULL;
}

/**
 * @brief Destroy mlx data.
 * Exits on error.
 * (Helper function for ft_destroy_map)
 * @param mlx: Mlx data to destroy
 */
static void	ft_destroy_mlx(t_mlx **mlx)
{
	if (mlx == NULL)
	{
		ft_putstr_fd(E_NULL_ARG_MSG, STDERR_FILENO);
		exit(E_NULL_ARG);
	}
	mlx_destroy_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	(*mlx)->mlx_ptr = NULL;
	*mlx = NULL;
}

/**
 * @brief Destroy map data.
 * Destroy all map_data members and set map data pointer to NULL.
 * Exits on error.
 * @param map_data: Map data to destroy
 * @param mlx: Mlx data
 */
void	ft_destroy_map(t_map **map_data, t_mlx *mlx)
{
	if (map_data == NULL || mlx == NULL)
	{
		ft_putstr_fd(E_NULL_ARG_MSG, STDERR_FILENO);
		exit(E_NULL_ARG);
	}
	ft_destroy_player_imgs(&((*map_data)->player_imgs), mlx);
	ft_destroy_img(&((*map_data)->collectible), mlx);
	ft_destroy_img(&((*map_data)->empty), mlx);
	ft_destroy_img(&((*map_data)->exit), mlx);
	ft_destroy_img(&((*map_data)->wall), mlx);
	ft_destroy_mlx(&((*map_data)->mlx));
	*map_data = NULL;
}