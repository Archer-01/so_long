/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:48:04 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/12 12:44:16 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_errors.h"
# include <fcntl.h>
# include <stdio.h>

void	ft_check_extension(const char *map_path);
void	ft_check_content(t_list *lst);
void	ft_check_wall_surrounding(t_list *lst);
void	ft_check_minimum_requirements(t_list *lst);
void	ft_check_rectangular(t_list *lst);

char	**ft_parser(const char *map_path);

#endif