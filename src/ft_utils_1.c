/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:34:32 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/16 08:32:00 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

/**
 * @brief Allocate count of size elements in memory.
 * Exits on error
 * @param count: Number of elements to
 * @param size: Size of each element
 * @return void*: Pointer to allocated memory
 */
void	*ft_allocate(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
	{
		ft_putstr_fd(E_MALLOC_MSG, STDERR_FILENO);
		exit(E_MALLOC);
	}
	return (ptr);
}

/**
 * @brief Open file on read only mode.
 * Exits on error
 * @param path: File path to open
 * @return int: File descriptor
 */
int	ft_open(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(E_NOFILE_MSG, STDERR_FILENO);
		exit(E_NOFILE);
	}
	return (fd);
}

/**
 * @brief Free all allocated memory and exit program.
 *
 * @param data: Daya to be freed
 * @return int: Zero
 */
int	ft_exit(t_game *data)
{
	ft_destroy_game_data(&data);
	exit(EXIT_SUCCESS);
}

/**
 * @brief Swap two characters.
 *
 * @param a: First character
 * @param b: Second character
 */
void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * @brief Clear matrix from memory.
 * Frees all allocated memory and sets matrix pointer to NULL
 * @param matrix: Matrix to operate on
 */
void	ft_clear_matrix(char ***matrix)
{
	int	i;

	if (matrix == NULL)
	{
		ft_putstr_fd(E_NULL_ARG_MSG, STDERR_FILENO);
		exit(E_NULL_ARG);
	}
	i = 0;
	while ((*matrix)[i] != NULL)
	{
		free((*matrix)[i]);
		++i;
	}
	*matrix = NULL;
	free(*matrix);
}
