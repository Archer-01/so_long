/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:27:06 by hhamza            #+#    #+#             */
/*   Updated: 2021/12/31 11:50:53 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Calculates length of a string
 *
 * @param str: string to be operated on
 * @return size_t: length of the string
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

/**
 * @brief Duplicates the string entered as a parameter
 *
 * @param str: string to duplicate
 * @return char*: duplicated string
 */
char	*ft_strdup(const char *str)
{
	char	*result;
	size_t	strlen;

	strlen = ft_strlen(str) + 1;
	result = (char *) malloc(sizeof(char) * strlen);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, str, strlen);
	return (result);
}

/**
 * @brief Finds the first index of a character inside a string
 *
 * @param str: string to be operated on
 * @param c: character to find
 * @return int: index of the character or -1 if not found or error
 */
int	ft_indexof(const char *str, char c)
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
 * @brief Copies a string into another
 *
 * @param dst: destination string
 * @param src: source string
 * @param dstsize: number of characters to be copied ('\0' included)
 * @return size_t: length of source string
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/**
 * @brief Joins two strings into a new one
 *
 * @param s1: first string
 * @param s2: second string
 * @return char*: newly created joined string
 */
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	ft_strlcpy(result, s1, s1_len + 1);
	ft_strlcpy(result + s1_len, s2, s2_len + 1);
	return (result);
}
