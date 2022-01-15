/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 05:40:19 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/15 22:51:36 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_H
# define FT_RENDER_H

# include <mlx.h>
# include "ft_types.h"
# include "ft_init.h"

void	ft_render(t_game *map_data, const char **map);
void	ft_put_img(void *img_ptr, int i, int j, t_mlx *mlx);

#endif