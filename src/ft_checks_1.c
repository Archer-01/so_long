/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:23:28 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/18 16:53:43 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/**
 * @brief Check map file extension.
 * Exits on error
 * @param map_path: Map file path
 */
void	ft_check_extension(const char *map_path)
{
	size_t	len;
	char	*extension;

	len = ft_strlen(map_path);
	extension = (char *) map_path + len - 4;
	if (len < 4 || ft_strncmp(extension, ".ber", 4) != 0)
	{
		ft_putstr_fd(E_BADMAPEXT_MSG, STDERR_FILENO);
		exit(E_BADMAP);
	}
}

/**
 * @brief Check if map has any invalid characters.
 * Exits on error
 * @param lst: Linked list containing map
 */
void	ft_check_content(t_list *lst)
{
	int		i;
	char	c;
	char	*line;

	while (lst != NULL)
	{
		line = (char *) lst->content;
		i = 0;
		while (line[i] != '\0')
		{
			c = line[i];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P'
				&& c != 'V' && c != 'H')
			{
				ft_putstr_fd(E_BADMAP_CHARS_MSG, STDERR_FILENO);
				exit(E_BADMAP);
			}
			++i;
		}
		lst = lst->next;
	}
}

/**
 * @brief Check if line is full wall.
 * Exits on error (Helper function for ft_check_wall_surrounding)
 * @param line: Line to check
 */
static void	ft_check_wall(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
		{
			ft_putstr_fd(E_BADMAP_WALL_MSG, STDERR_FILENO);
			exit(E_BADMAP);
		}
		++i;
	}
}

/**
 * @brief Check if map is surrounded by walls.
 * Exits on error
 * @param lst: Linked list containing map
 */
void	ft_check_wall_surrounding(t_list *lst)
{
	t_list	*tmp;
	char	*line;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp == lst || tmp->next == NULL)
			ft_check_wall(tmp->content);
		else
		{
			line = (char *) tmp->content;
			if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			{
				ft_putstr_fd(E_BADMAP_WALL_MSG, STDERR_FILENO);
				exit(E_BADMAP);
			}
		}
		tmp = tmp->next;
	}
}
