/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:53:03 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/05 17:55:09 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_TYPES_H
# define FT_MLX_TYPES_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

#endif