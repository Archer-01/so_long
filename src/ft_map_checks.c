/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:08:14 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/03 15:33:24 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_checks.h"

/**
 * @brief Checks if map meets minimum requirements
 * At least one exit, one collectible and one starting position
 * @param lst: Linked list containing the map to check
 * @return int: 1 for valid map, 0 otherwise
 */
int	ft_check_minimum_requirements(t_list *lst)
{
	int	exit_count;
	int	collectible_count;
	int	starting_positions_count;

	exit_count = 0;
	collectible_count = 0;
	starting_positions_count = 0;
	while (lst != NULL)
	{
		if (ft_indexof(lst->content, 'E') != -1)
			++exit_count;
		if (ft_indexof(lst->content, 'C') != -1)
			++collectible_count;
		if (ft_indexof(lst->content, 'P') != -1)
			++starting_positions_count;
		lst = lst->next;
	}
	return (exit_count >= 1 && collectible_count >= 1 \
	&& starting_positions_count >= 1);
}

/**
 * @brief Checks if map is rectangular
 *
 * @param lst: Linked list containing the map to check
 * @return int: 1 for valid, 0 otherwise
 */
int	ft_check_rectangular(t_list *lst)
{
	size_t	length;
	size_t	new_length;

	if (lst == NULL)
		return (0);
	length = ft_strlen(lst->content);
	lst = lst->next;
	while (lst != NULL)
	{
		new_length = ft_strlen(lst->content);
		if (new_length != length)
			return (0);
		lst = lst->next;
	}
	return (1);
}
