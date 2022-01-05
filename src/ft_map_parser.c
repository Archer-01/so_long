/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:36:52 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/05 12:00:15 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map_parser.h"

/**
 * @brief Convert map file (.ber) to linked list
 *
 * @param fd: map (.ber) file descriptor
 * @return t_list*: Newly created linked list
 */
static t_list	*ft_map_to_list(int fd)
{
	t_list	*lst;
	t_list	*newnode;
	char	*line;
	char	*line_no_endl;

	lst = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_no_endl = ft_substr(line, 0, ft_indexof(line, '\n'));
		free(line);
		if (line_no_endl == NULL)
			return (ft_lstclear(&lst, &free), NULL);
		newnode = ft_lstnew(line_no_endl);
		if (newnode == NULL)
		{
			ft_lstclear(&lst, &free);
			return (NULL);
		}
		ft_lstadd_back(&lst, newnode);
		line = get_next_line(fd);
	}
	return (lst);
}

static void	ft_clear_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}

/**
 * @brief Convert linked list to matrix format
 *
 * @param lst: Linked list to convert
 * @return char**: Converted matrix
 */
static char	**ft_lst_to_matrix(t_list *lst)
{
	char	**matrix;
	size_t	line_count;
	t_list	*tmp;
	int		i;

	if (lst == NULL)
		return (NULL);
	line_count = ft_lstsize(lst);
	matrix = (char **) malloc(sizeof(char *) * (line_count + 1));
	if (matrix == NULL)
	{
		ft_lstclear(&lst, &free);
		ft_clear_matrix(matrix);
		return (NULL);
	}
	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		matrix[i] = ft_strdup(tmp->content);
		++i;
		tmp = tmp->next;
	}
	matrix[i] = NULL;
	return (ft_lstclear(&lst, &free), matrix);
}

/**
 * @brief Check map.
 *  Checks if map has invalid characters, if map has at least one exit, one
 * collectible and one starting position, if map is rectangular, and if map is
 * surrounded by walls. this function exits the program on error and returns
 * on success
 * @param lst: Linked list containing the map to check
 */
static void	ft_map_checker(t_list *lst)
{
	if (!ft_check_if_valid_characters(lst) \
	|| !ft_check_minimum_requirements(lst) \
	|| !ft_check_rectangular(lst) \
	|| !ft_check_if_surrounded_by_walls(lst))
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map\n", 12);
		ft_lstclear(&lst, &free);
		exit(1);
	}
}

/**
 * @brief Parse map file (.ber), checks if valid and return map as matrix
 *
 * @param path: Path to map file (.ber)
 * @return char**: Newly created matrix
 */
char	**ft_map_parser(const char *path)
{
	int		fd;
	t_list	*lst;
	char	**matrix;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		perror(path);
		exit(2);
	}
	lst = ft_map_to_list(fd);
	ft_map_checker(lst);
	matrix = ft_lst_to_matrix(lst);
	close(fd);
	return (matrix);
}
