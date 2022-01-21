/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:43:50 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/21 11:27:11 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

# define E_BADARGS 1
# define E_BADMAP 2
# define E_NOFILE 3
# define E_MALLOC 4
# define E_MLX_IMG 5
# define E_NULL_ARG 6
# define E_MLX_INIT 7
# define E_MLX_WIN 8
# define E_MAP_NEWL 9
# define E_INVAL_DIR 10

# define E_BADARGS_MSG "Usage: ./so_long map-path.ber\n"
# define E_BADMAPEXT_MSG "Error\nMap file must have '.ber' extension\n"
# define E_NOFILE_MSG "Error\n"
# define E_MALLOC_MSG "Malloc error\n"
# define E_BADMAP_CHARS_MSG "Error\nMap has invalid characters\n"
# define E_BADMAP_EMPTY "Error\nEmpty map\n"
# define E_BADMAP_WALL_MSG "Error\nMap must be surrounded by walls\n"
# define E_BADMAP_MINREQ_MSG "Error\nMap must have at least one exit, one \
collectible and one starting position\n"
# define E_BADMAP_RECT_MSG "Error\nMap  must be rectangular\n"
# define E_MLX_IMG_MSG "Error creating mlx image\n"
# define E_NULL_ARG_MSG "Argument Error (NULL pointer)\n"
# define E_MLX_INIT_MSG "Error establishing mlx connection\n"
# define E_MLX_WIN_MSG "Error creating mlx window\n"
# define E_MAP_NEWL_MSG "Error\nMap has newline at the end\n"
# define E_INVAL_DIR_MSG "Error\nInvalid player direction\n"

#endif