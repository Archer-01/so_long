/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:21:43 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/03 13:22:33 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
