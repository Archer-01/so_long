/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:31:38 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/21 15:38:52 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_destroy.h"

/**
 * @brief Destroy enemies data (position and type)
 *
 * @param enemies: Adress of enemies array
 * @param enemies_count: Enemies count
 */
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
