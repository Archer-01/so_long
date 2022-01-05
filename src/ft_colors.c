/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:47:18 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/05 11:47:24 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_colors.h"

int	ft_get_color(int t, int r, int g, int b)
{
	int	color;

	color = (t << 24) & 0xFF000000;
	color |= (r << 16);
	color |= (g << 8);
	color |= b;
	return (color);
}

int	ft_get_t(int color)
{
	return ((color >> 24) & 0xFF);
}

int	ft_get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	ft_get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	ft_get_b(int color)
{
	return (color & 0xFF);
}
