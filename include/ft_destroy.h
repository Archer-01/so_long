/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:01:44 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/13 11:52:06 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DESTROY_H
# define FT_DESTROY_H

# include <mlx.h>
# include "libft.h"
# include "ft_types.h"
# include "ft_errors.h"

void	ft_destroy_map(t_map **map_data, t_mlx *mlx);

#endif