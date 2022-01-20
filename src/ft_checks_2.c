/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:23:31 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/20 12:49:01 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/**
 * @brief Count exits, collectibles and starting positions in map line.
 * (Helper function for ft_check_minimum_requirements)
 * @param line: Map line to operate on
 * @param exits: Exits count
 * @param collectibles: Collectibles count
 * @param start_pos: Starting positions count
 */
static void	ft_check_line_items(const char *line, int *exits, int *collectibles,
	int *start_pos)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'E')
			++(*exits);
		else if (line[i] == 'C')
			++(*collectibles);
		else if (line[i] == 'P')
			++(*start_pos);
		++i;
	}
}

/**
 * @brief Check map minimum requirements.
 * Exits on error
 * @param lst: Linked list containing map
 */
void	ft_check_minimum_requirements(t_list *lst)
{
	int		exits;
	int		collectibles;
	int		start_pos;

	exits = 0;
	collectibles = 0;
	start_pos = 0;
	while (lst != NULL)
	{
		ft_check_line_items((char *) lst->content, &exits, &collectibles,
			&start_pos);
		lst = lst->next;
	}
	if (exits < 1 || collectibles < 1 || start_pos != 1)
	{
		ft_putstr_fd(E_BADMAP_MINREQ_MSG, STDERR_FILENO);
		exit(E_BADMAP);
	}
}

/**
 * @brief Check map rectangularity.
 * Exits on error
 * @param lst: Linked list to operate on
 */
void	ft_check_rectangular(t_list *lst)
{
	char	*line;
	size_t	len;

	if (lst != NULL)
	{
		line = (char *) lst->content;
		len = ft_strlen(line);
		lst = lst->next;
	}
	while (lst != NULL)
	{
		line = (char *) lst->content;
		if (ft_strlen(line) != len)
		{
			ft_putstr_fd(E_BADMAP_RECT_MSG, STDERR_FILENO);
			exit(E_BADMAP);
		}
		lst = lst->next;
	}
}
