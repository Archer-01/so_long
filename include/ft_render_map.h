/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:40:51 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/04 12:47:20 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_MAP_H
# define FT_RENDER_MAP_H

# include <mlx.h>
# include <unistd.h>
# include "libft.h"

# define WIN_BLOCK_WIDTH 50
# define WIN_BLOCK_HEIGHT 50
# define WIN_TITLE "so_long"

void	ft_render_map(const char **map);

#endif