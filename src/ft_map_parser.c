/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:36:52 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/03 15:34:28 by hhamza           ###   ########.fr       */
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

/**
 * @brief Parses map file (.ber), checks if valid and returns map as linked list
 *
 * @param path: Path to map file (.ber)
 * @return t_list*: Newly created linked list
 */
t_list	*ft_map_parser(const char *path)
{
	int		fd;
	t_list	*lst;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		perror(path);
		exit(2);
	}
	lst = ft_map_to_list(fd);
	if (ft_check_rectangular(lst) == 1)
		printf("Rectangular map\n");
	else
		printf("Non rectangular map\n");
	close(fd);
	return (lst);
}
