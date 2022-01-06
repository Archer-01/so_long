/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:35:23 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/05 17:59:51 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMAGES_H
# define FT_IMAGES_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_mlx_types.h"

void	ft_put_xpm_image(t_mlx *mlx, const char *path, int x, int y);

#endif