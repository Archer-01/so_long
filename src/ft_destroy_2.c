/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:31:38 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/19 13:18:41 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_destroy.h"

void	ft_destroy_enemies(t_enemy **enemies, int enemies_count)
{
	if (enemies == NULL)
	{
		ft_putstr_fd(E_NULL_ARG_MSG, STDERR_FILENO);
		exit(E_NULL_ARG);
	}
	ft_bzero(*enemies, enemies_count * sizeof(t_enemy));
	free(*enemies);
	*enemies = NULL;
}
