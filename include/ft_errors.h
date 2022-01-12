/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:43:50 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/12 11:27:35 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

# define E_BADARGS 1
# define E_BADMAP 2
# define E_NOFILE 3
# define E_MALLOC 4

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

#endif