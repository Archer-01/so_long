/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:52:20 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/17 21:58:18 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/**
 * @brief Remove new lines ('\n) line. Exit if there is a newline on last line.
 *
 * @param lst: Linked list to operate on
 * @return t_list*: Linked list with newlines removed
 */
static t_list	*ft_remove_newline(t_list *lst)
{
	char	*str;
	t_list	*tmp;
	size_t	len;

	tmp = lst;
	while (tmp != NULL)
	{
		str = tmp->content;
		len = ft_strlen(str);
		if (str[len - 1] == '\n' && str[len] == '\0' && tmp->next == NULL)
		{
			ft_putstr_fd(E_MAP_NEWL_MSG, STDERR_FILENO);
			exit(E_MAP_NEWL);
		}
		if (str[len - 1] == '\n')
			str[len - 1] = '\0';
		tmp = tmp->next;
	}
	return (lst);
}

/**
 * @brief Convert map file (.ber) to linked list.
 * Exits on error
 * (Helper function for ft_parser)
 * @param fd: map (.ber) file descriptor
 * @return t_list*: Newly created linked list, NULL on empty map file
 */
static t_list	*ft_map_to_list(int fd)
{
	t_list	*lst;
	t_list	*node;
	char	*line;

	lst = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		node = ft_lstnew(line);
		if (node == NULL)
		{
			ft_lstclear(&lst, &free);
			ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
			exit(E_MALLOC);
		}
		ft_lstadd_back(&lst, node);
		line = get_next_line(fd);
	}
	if (lst == NULL)
	{
		ft_putstr_fd(E_BADMAP_EMPTY, STDERR_FILENO);
		exit(E_BADMAP);
	}
	return (ft_remove_newline(lst));
}

/**
 * @brief Convert linked list to matrix.
 * Exits on error
 * (Helper function for ft_parser)
 * @param lst: Linked list to convert
 * @return char**: Newly created matrix, exits the program on failure
 */
static char	**ft_lst_to_matrix(t_list *lst)
{
	char	**matrix;
	int		i;

	matrix = (char **) ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (matrix == NULL)
	{
		ft_lstclear(&lst, &free);
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	i = 0;
	while (lst != NULL)
	{
		matrix[i] = ft_strdup(lst->content);
		if (matrix[i] == NULL)
		{
			ft_lstclear(&lst, &free);
			ft_clear_matrix(&matrix);
			ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
			exit(E_MALLOC);
		}
		++i;
		lst = lst->next;
	}
	return (matrix[i] = NULL, ft_lstclear(&lst, &free), matrix);
}

/**
 * @brief Map parser.
 * Checks if map file has .ber extension, if map has no invalid characters,
 * if map is surrounded by walls, if map meets minimum requirements and if map
 * is rectangular.
 * Exits on error
 * @param map_path: Map file path
 * @return char**: Map as a matrix
 */
char	**ft_parser(const char *map_path)
{
	int		fd;
	t_list	*lst;
	char	**map;

	ft_check_extension(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(E_NOFILE_MSG, STDERR_FILENO);
		perror(map_path);
		exit(E_NOFILE);
	}
	lst = ft_map_to_list(fd);
	ft_check_content(lst);
	ft_check_wall_surrounding(lst);
	ft_check_minimum_requirements(lst);
	ft_check_rectangular(lst);
	map = ft_lst_to_matrix(lst);
	close(fd);
	return (map);
}
