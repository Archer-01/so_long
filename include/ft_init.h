/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:41:25 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/14 03:38:39 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_H
# define FT_INIT_H

# include <mlx.h>
# include "ft_types.h"
# include "ft_errors.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_utils.h"

# define BLOCK_SIZE 70
# define WIN_TITLE "so_long"

void			*ft_init_img(const char *path, t_mlx *mlx);
t_player_imgs	*ft_init_player_imgs(t_mlx *mlx);
t_mlx			*ft_init_mlx(int width, int height, const char *title);
t_map			*ft_init_map(const char **map);
t_animation		*ft_init_animation(const char *path, t_mlx *mlx);

#endif