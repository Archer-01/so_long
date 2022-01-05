/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:53:52 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/05 17:55:31 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_PIXEL_H
# define FT_MLX_PIXEL_H

# include "ft_colors.h"
# include "ft_mlx_types.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif