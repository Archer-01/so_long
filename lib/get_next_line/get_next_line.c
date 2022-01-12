/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:24:02 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/12 09:38:37 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Finds the first index of a character inside a string
 *
 * @param str: string to be operated on
 * @param c: character to find
 * @return int: index of the character or -1 if not found or error
 */
static int	ft_indexof(const char *str, char c)
{
	unsigned int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

/**
 * @brief Saves the remaining characters for the next 'get_next_line' call
 *
 * @param line: line to be returned by 'get_next_line'
 * @param remainder: remainder to be saved for next 'get_next_line' call
 * @return char*: modified line if contains characters after newline
 */
static char	*ft_save_remainder(char *line, char *remainder)
{
	ssize_t	endl_index;
	char	*temp;

	endl_index = ft_indexof(line, '\n');
	if (endl_index != -1)
	{
		ft_strlcpy(remainder, line + endl_index + 1, BUFFER_SIZE + 1);
		temp = line;
		line = (char *) malloc(sizeof(char) * (endl_index + 2));
		if (line == NULL)
			return (NULL);
		ft_strlcpy(line, temp, endl_index + 2);
		free(temp);
	}
	else
		remainder[0] = '\0';
	return (line);
}

/**
 * @brief Get the next line from a file descriptor
 *
 * @param fd: file descriptor
 * @return char*: the next line
 */
char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_size;
	char		*temp;

	line = ft_strdup(remainder);
	while (ft_indexof(line, '\n') == -1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
	}
	if (line[0] == '\0' || read_size == -1)
	{
		free(line);
		return (NULL);
	}
	line = ft_save_remainder(line, remainder);
	return (line);
}
