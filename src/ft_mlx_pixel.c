/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:02:43 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/05 12:22:11 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mlx_pixel.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + (x * (img->bpp / 8)));
	*(unsigned int *) dst = color;
}
