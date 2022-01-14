/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:34:32 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/14 03:59:40 by hhamza           ###   ########.fr       */
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
