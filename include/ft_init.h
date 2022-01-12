/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:41:25 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/12 19:09:04 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_H
# define FT_INIT_H

# include <mlx.h>
# include "ft_types.h"
# include "ft_errors.h"
# include "libft.h"

# define BLOCK_SIZE 70

void			*ft_init_img(const char *path, t_mlx *mlx);
t_animation		*ft_init_idle(t_mlx *mlx);
t_animation		*ft_init_left(t_mlx *mlx);
t_animation		*ft_init_right(t_mlx *mlx);
t_animation		*ft_init_up(t_mlx *mlx);
t_animation		*ft_init_down(t_mlx *mlx);
t_player_imgs	*ft_init_player_imgs(t_mlx *mlx);
t_map			*ft_init_map(t_mlx *mlx, const char **map);

#endif