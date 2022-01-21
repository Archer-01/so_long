/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:01:55 by hhamza            #+#    #+#             */
/*   Updated: 2022/01/21 15:39:35 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENEMY_H
# define FT_ENEMY_H

# include "ft_utils.h"
# include "ft_types.h"
# include "ft_move.h"

# define ENEMY_LEFT 1
# define ENEMY_RIGHT 2
# define ENEMY_UP 3
# define ENEMY_DOWN 4

void	ft_enemy_patrol(t_game *data);

#endif