/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checks.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:07:51 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/03 17:30:21 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_CHECKS_H
# define FT_MAP_CHECKS_H

# include "libft.h"

int	ft_check_minimum_requirements(t_list *lst);
int	ft_check_rectangular(t_list *lst);
int	ft_check_if_surrounded_by_walls(t_list *lst);
int	ft_check_if_valid_characters(t_list *lst);

#endif